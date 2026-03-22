#include "../../plugin.hpp"

#define FAR165_INFO_SIZE 336
#define sizeofa(array) (sizeof(array)/sizeof(array[0]))

PluginStartupInfo Info;
FARSTANDARDFUNCTIONS FSF;
char PluginRootKey[80];
BOOL IsOldFAR=TRUE;

enum {
  mName,
  mSelect,
  mUnselect,
  mInverse,
};

const char *GetMsg(int MsgId)
{
  return(Info.GetMsg(Info.ModuleNumber,MsgId));
}

void WINAPI SetStartupInfo(const struct PluginStartupInfo *Info)
{
  memset(&::Info,0,sizeof(::Info));
  memmove(&::Info,Info,(Info->StructSize>(int)sizeof(::Info))?sizeof(::Info):Info->StructSize);
  if(Info->StructSize>FAR165_INFO_SIZE)
  {
    IsOldFAR=FALSE;
    ::FSF=*Info->FSF;
    ::Info.FSF=&::FSF;

    strcpy(PluginRootKey,Info->RootKey);
    strcat(PluginRootKey,"\\vins");
  }
}

int WINAPI _export GetMinFarVersion(void)
{
  return MAKEFARVERSION(1,70,1634);
}

HANDLE WINAPI _export OpenPlugin(int OpenFrom,int Item)
{
  (void)Item;
  if(OpenFrom==OPEN_VIEWER)
  {
    int Msgs[]={mSelect,mUnselect,mInverse};
    FarMenuItem MenuItems[sizeofa(Msgs)];
    for(unsigned int i=0;i<sizeofa(Msgs);i++)
    {
      MenuItems[i].Selected=MenuItems[i].Checked=MenuItems[i].Separator=FALSE;
      strcpy(MenuItems[i].Text,GetMsg(Msgs[i]));
    }
    MenuItems[0].Selected=TRUE;
    int MenuCode=Info.Menu(Info.ModuleNumber,-1,-1,0,FMENU_WRAPMODE,GetMsg(mName),NULL,NULL,NULL,NULL,MenuItems,sizeofa(MenuItems));
    if(MenuCode>=0)
    {
      PanelInfo PInfo;
      if(Info.Control(INVALID_HANDLE_VALUE,FCTL_GETPANELSHORTINFO,&PInfo))
      {
        if(PInfo.PanelType==PTYPE_FILEPANEL&&!PInfo.Plugin)
        {
          WindowInfo wi; wi.Pos=-1;
          Info.AdvControl(Info.ModuleNumber,ACTL_GETWINDOWINFO,&wi);
          char vdir[MAX_PATH],pdir[MAX_PATH],vname[MAX_PATH],*filename;
          strcpy(pdir,PInfo.CurDir);
          FSF.AddEndSlash(pdir);
          DWORD full_res=GetFullPathName(wi.Name,sizeof(vdir),vdir,&filename);
          if(full_res&&full_res<sizeof(vdir))
          {
            if(filename)
            {
              strcpy(vname,filename);
              *filename=0;
              if(!_stricmp(pdir,vdir))
              {
                if(Info.Control(INVALID_HANDLE_VALUE,FCTL_GETPANELINFO,&PInfo))
                {
                  for(int i=0;i<PInfo.ItemsNumber;i++)
                  {
                    if(!_stricmp(vname,PInfo.PanelItems[i].FindData.cFileName)||!_stricmp(vname,PInfo.PanelItems[i].FindData.cAlternateFileName))
                    {
                      switch(MenuCode)
                      {
                        case 0:
                          PInfo.PanelItems[i].Flags|=PPIF_SELECTED;
                          break;
                        case 1:
                          PInfo.PanelItems[i].Flags&=~PPIF_SELECTED;
                          break;
                        case 2:
                          PInfo.PanelItems[i].Flags^=PPIF_SELECTED;
                          break;
                      }
                      Info.Control(INVALID_HANDLE_VALUE,FCTL_SETSELECTION,&PInfo);
                      Info.Control(INVALID_HANDLE_VALUE,FCTL_REDRAWPANEL,NULL);
                      break;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return INVALID_HANDLE_VALUE;
}

void WINAPI GetPluginInfo(struct PluginInfo *Info)
{
  if(!IsOldFAR)
  {
    Info->StructSize=sizeof(*Info);
    Info->Flags=PF_VIEWER;
    static const char *PluginMenuStrings[1];
    PluginMenuStrings[0]=GetMsg(mName);
    Info->PluginMenuStrings=PluginMenuStrings;
    Info->PluginMenuStringsNumber=sizeofa(PluginMenuStrings);
  }
}

#ifdef __cplusplus
extern "C"{
#endif
  bool WINAPI DllMainCRTStartup(HANDLE hDll,DWORD dwReason,LPVOID lpReserved);
#ifdef __cplusplus
};
#endif

bool WINAPI DllMainCRTStartup(HANDLE hDll,DWORD dwReason,LPVOID lpReserved)
{
  (void)hDll;
  (void)dwReason;
  (void)lpReserved;
  return true;
}
