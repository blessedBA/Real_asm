static void EnablePrivilege(const wchar_t *name)
{
  TOKEN_PRIVILEGES priv;
  HANDLE token;
  priv.PrivilegeCount=1;
  priv.Privileges[0].Attributes=SE_PRIVILEGE_ENABLED;

  if(!LookupPrivilegeValueW(0,name,&(priv.Privileges[0].Luid)))
    LogSys(L"LookupPrivilegeValue",NULL,NULL);
  else
  {
    if(!OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES,&token))
      LogSys(L"OpenProcessToken",NULL,NULL);
    else
    {
      AdjustTokenPrivileges(token,FALSE,&priv,sizeof(priv),0,0);
      if(GetLastError()!=ERROR_SUCCESS)
        LogSys(L"AdjustTokenPrivileges",NULL,NULL);
      CloseHandle(token);
    }
  }
}

void *DefaultTokenInformation(HANDLE token,TOKEN_INFORMATION_CLASS tic)
{
  unsigned long size; unsigned char *Result=NULL;
  GetTokenInformation(token,tic,0,0,&size);
  Result=(unsigned char *)malloc(size);
  if(Result)
  {
    if(!GetTokenInformation(token,tic,Result,size,&size))
      LogSys(L"GetTokenInformation",NULL,NULL);
  }
  return Result;
}

static BOOL GetPwdName(HANDLE pipe,PUNICODE_STRING Name);

static void PipeToThread(HANDLE pipe,HANDLE thread)
{
  HANDLE pipe_token,new_token;
  SECURITY_QUALITY_OF_SERVICE sqos={sizeof(sqos),SecurityImpersonation,SECURITY_STATIC_TRACKING,FALSE};
  OBJECT_ATTRIBUTES oa={sizeof(oa),0,0,0,0,&sqos};
  TOKEN_STATISTICS *stats=NULL;
  PTOKEN_USER user=NULL; PTOKEN_GROUPS groups=NULL; PTOKEN_PRIVILEGES privileges=NULL;
  TOKEN_OWNER *owner=NULL; TOKEN_PRIMARY_GROUP *group=NULL; TOKEN_DEFAULT_DACL *dacl=NULL;
  long res; BOOL CanOpenThread,LogonAs=FALSE;
  //LogonAs variables
  LSA_HANDLE Policy; LSA_OBJECT_ATTRIBUTES ObjectAttributes;
  LSA_UNICODE_STRING key,*data;
  wchar_t *username=NULL,*password=NULL,*domain=NULL;
  HANDLE NetworkUser=INVALID_HANDLE_VALUE; LUID BCopyID; LARGE_INTEGER BCopyExpirationTime;

  //get stored pwd
  memset(&ObjectAttributes,0,sizeof(ObjectAttributes));
  res=LsaOpenPolicy(NULL,&ObjectAttributes,POLICY_GET_PRIVATE_INFORMATION,&Policy);
  if(res)
  {
    DWORD doserr=RtlNtStatusToDosError(res);
    SetLastError(doserr);
    LogSys(L"LsaOpenPolicy",NULL,NULL);
  }
  else
  {
    if(GetPwdName(pipe,&key))
    {
      res=LsaRetrievePrivateData(Policy,&key,&data);
      if(!res)
      {
        password=(wchar_t *)malloc(data->Length+sizeof(wchar_t));
        if(password)
        {
          memmove(password,data->Buffer,data->Length);
          LogonAs=TRUE;
        }
        res=LsaFreeMemory(data);
        if(res)
        {
          DWORD doserr=RtlNtStatusToDosError(res);
          SetLastError(doserr);
          LogSys(L"LsaFreeMemory",NULL,NULL);
        }
      }
      free(key.Buffer);
    }
    LsaClose(Policy);
  }

  if(!ImpersonateNamedPipeClient(pipe))
    LogSys(L"ImpersonateNamedPipeClient",NULL,NULL);
  else
  {
    CanOpenThread=OpenThreadToken(GetCurrentThread(),TOKEN_ALL_ACCESS,FALSE,&pipe_token);
    if(!CanOpenThread)
      LogSys(L"OpenThreadToken",NULL,NULL);
    if(!RevertToSelf())
      LogSys(L"RevertToSelf",NULL,NULL);
    if(CanOpenThread)
    {
      //get user name and domain
      if(LogonAs)
      {
        user=(PTOKEN_USER)DefaultTokenInformation(pipe_token,TokenUser);
        if(user)
        {
          SID_NAME_USE snu; DWORD usersize=0,domainsize=0;
          if(!LookupAccountSidW(NULL,user->User.Sid,NULL,&usersize,NULL,&domainsize,&snu))
          {
            if(GetLastError()==ERROR_INSUFFICIENT_BUFFER)
            {
              username=(wchar_t *)malloc(usersize*sizeof(wchar_t));
              domain=(wchar_t *)malloc(domainsize*sizeof(wchar_t));
              if(username&&domain)
              {
                if(!LookupAccountSidW(NULL,user->User.Sid,username,&usersize,domain,&domainsize,&snu))
                  LogonAs=FALSE;
              }
              else LogonAs=FALSE;
            }
            else LogonAs=FALSE;
          }
          else LogonAs=FALSE;
          free(user);
          user=NULL;
        }
        else LogonAs=FALSE;
      }
      if(LogonAs)
      {
        if(LogonUserW(username,domain,password,LOGON32_LOGON_INTERACTIVE,LOGON32_PROVIDER_DEFAULT,&NetworkUser))
        {
          stats=(TOKEN_STATISTICS *)DefaultTokenInformation(NetworkUser,TokenStatistics);
          if(stats)
          {
            BCopyID=stats->AuthenticationId;
            BCopyExpirationTime=stats->ExpirationTime;
            free(stats);
          }
          else LogonAs=FALSE;
        }
        else LogonAs=FALSE;
      }
      if(LogonAs)
      {
        user=(PTOKEN_USER)DefaultTokenInformation(pipe_token,TokenUser);
        if(!user) goto cleanup;
        groups=(PTOKEN_GROUPS)DefaultTokenInformation(pipe_token,TokenGroups);
        if(!groups) goto cleanup;
        privileges=(PTOKEN_PRIVILEGES)DefaultTokenInformation(pipe_token,TokenPrivileges);
        if(!privileges) goto cleanup;
        owner=(TOKEN_OWNER *)DefaultTokenInformation(pipe_token,TokenOwner);
        if(!owner) goto cleanup;
        group=(TOKEN_PRIMARY_GROUP *)DefaultTokenInformation(pipe_token,TokenPrimaryGroup);
        if(!group) goto cleanup;
        dacl=(TOKEN_DEFAULT_DACL *)DefaultTokenInformation(pipe_token,TokenDefaultDacl);
        if(!dacl) goto cleanup;
        res=ZwCreateToken(&new_token,TOKEN_ALL_ACCESS,&oa,TokenImpersonation,&BCopyID,&BCopyExpirationTime,user,groups,privileges,owner,group,dacl,&NetworkSource);
        if(res)
        {
          DWORD doserr=RtlNtStatusToDosError(res);
          SetLastError(doserr);
          LogSys(L"ZwCreateToken",NULL,NULL);
        }
        else
        {
          if(!SetThreadToken(&thread,new_token))
            LogSys(L"SetThreadToken",NULL,NULL);
          CloseHandle(new_token);
        }
cleanup:
        if(user) free(user);
        if(groups) free(groups);
        if(privileges) free(privileges);
        if(owner) free(owner);
        if(group) free(group);
        if(dacl) free(dacl);
      }
      else
      {
        if(!SetThreadToken(&thread,pipe_token))
          LogSys(L"SetThreadToken",NULL,NULL);
      }
      CloseHandle(pipe_token);
    }
  }
  free(username);
  free(domain);
  free(password);
  CloseHandle(NetworkUser);
}

static BOOL GetPwdName(HANDLE pipe,PUNICODE_STRING Name)
{
  BOOL Result=FALSE;
  if(!ImpersonateNamedPipeClient(pipe))
    LogSys(L"ImpersonateNamedPipeClient",NULL,NULL);
  else
  {
    HANDLE pipe_token;
    if(!OpenThreadToken(GetCurrentThread(),TOKEN_ALL_ACCESS,FALSE,&pipe_token))
      LogSys(L"OpenThreadToken",NULL,NULL);
    else
    {
      PTOKEN_USER pipe_user;
      pipe_user=(PTOKEN_USER)DefaultTokenInformation(pipe_token,TokenUser);
      if(pipe_user)
      {
        long res; UNICODE_STRING sid;
        memset(&sid,0,sizeof(sid));
        res=RtlConvertSidToUnicodeString(&sid,pipe_user->User.Sid,TRUE);
        if(res)
        {
          DWORD doserr=RtlNtStatusToDosError(res);
          SetLastError(doserr);
          LogSys(L"RtlConvertSidToUnicodeString",NULL,NULL);
        }
        else
        {
          Name->Buffer=(wchar_t *)malloc((sid.Length+10)*sizeof(wchar_t));
          if(Name->Buffer)
          {
            wcscpy(Name->Buffer,L"FARBCopy!");
            wcsncat(Name->Buffer,sid.Buffer,sid.Length);
            Name->Length=wcslen(Name->Buffer)*sizeof(wchar_t);
            Name->MaximumLength=Name->Length;
            Result=TRUE;
          }
          RtlFreeUnicodeString(&sid);
        }
        free(pipe_user);
      }
      CloseHandle(pipe_token);
    }
    if(!RevertToSelf())
      LogSys(L"RevertToSelf",NULL,NULL);
  }
  return Result;
}
