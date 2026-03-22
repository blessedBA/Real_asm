//#define _FAR_USE_FARFINDDATA

#include "..\plugin.hpp"
#include "..\farkeys.hpp"

#define COUNT(Msg) (sizeof(Msg)/sizeof(*Msg))

PluginStartupInfo Info;
FarStandardFunctions FSF;

//¤«ï ®âª«îç¥­¨ï £¥­¥à æ¨¨ startup-ª®¤  ¢ GCC
#ifdef __GNUC__
  #ifdef __cplusplus
    extern "C"
  #endif
  BOOL WINAPI DllMainCRTStartup(HANDLE hDll, DWORD dwReason, LPVOID lpReserved)
  {
    return TRUE;
  }
#endif

struct InitDialogItem
{
  int Type;
  int X1;
  int Y1;
  int X2;
  int Y2;
  int Focus;
  int Selected;                    
  unsigned int Flags;
  int DefaultButton;
  char *Data;
};

inline void MEMSET(void *s, BYTE c, int Size)
{
  BYTE *b=(BYTE *)s;
  while(Size--)
    *b++=c;
}

void InitDialogItems(const InitDialogItem *Init, FarDialogItem *Item, int Count)
{
  while(Count--)
  {
    Item->Type=Init->Type;
    Item->X1=Init->X1;
    Item->Y1=Init->Y1;
    Item->X2=Init->X2;
    Item->Y2=Init->Y2;
    Item->Focus=Init->Focus;
    Item->Selected=Init->Selected;
    Item->Flags=Init->Flags;
    Item->DefaultButton=Init->DefaultButton;
    /*if((unsigned int)Init->Data<2000)
      lstrcpy(Item->Data, GetMsg((unsigned int)Init->Data));
    else*/
      lstrcpy(Item->Data, Init->Data);

    Item++;
    Init++;
  }
}

long WINAPI DlgProc(HANDLE hDlg, int Msg, int Param1, long Param2)
{
  static int Key, KeyCount;
  static DWORD TickCount;
  switch(Msg)
  {
    case DN_INITDIALOG:
    {
      int SelectFolders=FPS_SELECTFOLDERS&Info.AdvControl(Info.ModuleNumber, ACTL_GETPANELSETTINGS, 0);
      Info.SendDlgMessage(hDlg, DM_SETCHECK, 2, SelectFolders?BSTATE_CHECKED:BSTATE_UNCHECKED);
      TickCount=GetTickCount();
      Key=Param2;
      KeyCount=0;
      return TRUE;
    }
    case DN_KEY:
      if(!KeyCount)
      {
        KeyCount++;
        //?? ¨á¯®«ì§ã© ¯ à ¬¥âà ¢à¥¬¥­¨ ¤¢®©­®£® ª«¨ª  ¬ëèìî
        if(Key==Param2 && GetTickCount()-TickCount<500)
        {
          Info.SendDlgMessage(hDlg, DM_USER, 0, Param2);
          return TRUE;
        }
      }
      if(Param2==KEY_ENTER)
      {
        Info.SendDlgMessage(hDlg, DM_USER, 0, Param2);
        return TRUE;
      }
      return FALSE;
    case DM_USER:
    {
      char Mask[512];
      FarDialogItemData fdid={sizeof(Mask), Mask};
      Info.SendDlgMessage(hDlg, DM_GETTEXT, 1, (long)&fdid);

      PanelInfo pi;
      Info.Control(INVALID_HANDLE_VALUE, FCTL_GETPANELINFO, &pi);
      //PluginPanelItem *PanelItem=pi.PanelItems;
      if(Param2==KEY_ADD)
        for(int i=0; i<pi.ItemsNumber; i++)
          pi.PanelItems[i].Flags|=PPIF_SELECTED;
      else if(Param2==KEY_SUBTRACT)
        for(int i=0; i<pi.ItemsNumber; i++)
          pi.PanelItems[i].Flags&=~PPIF_SELECTED;
      else if(Param2==KEY_ENTER)
      {
        for(int i=0; i<pi.ItemsNumber; i++)
        {
          if(pi.PanelItems[i].FindData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY
             && Info.SendDlgMessage(hDlg, DM_GETCHECK, 2, 0)==BSTATE_UNCHECKED)
            continue;
          if(FSF.ProcessName(Mask, pi.PanelItems[i].FindData.cFileName, PN_CMPNAMELIST))
            if(Key==KEY_ADD)
              pi.PanelItems[i].Flags|=PPIF_SELECTED;
            else if(Key==KEY_SUBTRACT)
              pi.PanelItems[i].Flags&=~PPIF_SELECTED;
        }
      }
      Info.Control(INVALID_HANDLE_VALUE, FCTL_SETSELECTION, &pi);

      Info.SendDlgMessage(hDlg, DM_CLOSE, -1, 0);
      return TRUE;
    }
  }
  return Info.DefDlgProc(hDlg, Msg, Param1, Param2);  
}

//²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²
//²²²²²²²²²²²²²²²                                             ²²²²²²²²²²²²²²²²²²
//²²²²²²²²²²²²²²²   ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Select ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»   °°²²²²²²²²²²²²²²²²
//²²²²²²²²²²²²²²²   º °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°º   °°²²²²²²²²²²²²²²²²
//²²²²²²²²²²²²²²²   º [ ] Select folders                  º   °°²²²²²²²²²²²²²²²²
//²²²²²²²²²²²²²²²   ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼   °°²²²²²²²²²²²²²²²²
//²²²²²²²²²²²²²²²                                             °°²²²²²²²²²²²²²²²²
//²²²²²²²²²²²²²²²²²°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°²²²²²²²²²²²²²²²²
//²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²

void Select(int Code)
{
  InitDialogItem InitItems[]=
  {
    {DI_DOUBLEBOX, 3,1,41,4, 0,0,0,0, "Select"},
    {DI_EDIT,      5,2,39,0, 1, (int)"Masks", /*DIF_USELASTHISTORY|*/DIF_HISTORY, 0, "*.*"},
    {DI_CHECKBOX,  5,3, 0,0, 0,0,0,0, "Select folders"},
  };
  FarDialogItem Items[COUNT(InitItems)];
  InitDialogItems(InitItems, Items, COUNT(InitItems));
  int Ret=Info.DialogEx(Info.ModuleNumber, -1,-1,45,6, NULL, Items, COUNT(Items), 0, 0, DlgProc, Code);
}

HANDLE WINAPI OpenPlugin(int OpenFrom, int Item)
{
/*  const FarMenuItemEx Items[]=
  {
    {0, "&+",          0,0,0},
    {0, "&-",          0,0,0},
  };*/
  FarMenuItemEx Items[2];
  MEMSET(Items, 0, sizeof(Items));
  lstrcpy(Items[0].Text.Text, "&+");
  lstrcpy(Items[1].Text.Text, "&-");

  int BreakKeys[]=
  {
    VK_ADD,
    VK_SUBTRACT,
    0
  };
  int BreakCode;

  int Code=Info.Menu(Info.ModuleNumber, -1,-1, 0, FMENU_USEEXT|FMENU_WRAPMODE,
                     "SELECT", NULL, NULL, BreakKeys, &BreakCode,
                     (FarMenuItem *)Items, COUNT(Items));
  Code=((BreakCode==-1)?Code:BreakCode);

  switch(Code)
  {
    case 0:
      Select(KEY_ADD);
      break;
    case 1:
      Select(KEY_SUBTRACT);
      break;
  }

  return INVALID_HANDLE_VALUE;
}

void WINAPI _export GetPluginInfo(PluginInfo *Info)
{
  Info->StructSize=sizeof(PluginInfo);
  static const char *PluginMenuStrings[1];
  PluginMenuStrings[0]="SELECT";
  Info->PluginMenuStrings=PluginMenuStrings;
  Info->PluginMenuStringsNumber=1;
}

void WINAPI _export SetStartupInfo(const PluginStartupInfo *Info)
{
  ::Info=*Info;
  FSF=*Info->FSF;
  ::Info.FSF=&FSF;
}
