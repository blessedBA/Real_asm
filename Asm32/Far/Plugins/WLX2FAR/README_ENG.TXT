WLX2FAR version 0.1.6

Warning: Works only in WindowsNT, Windows 2000, Windows XP, Windows 2003

This plugin is intended for support TotalCommander WLX plugins in FAR.
This tool supports only "real" WLX plugins. The "real" are understood as
what fairly create new window, instead of deceive lister with new process
creating.

Installation:
1) Create a new folder wlx2far in a directory with FAR plugins (c:\Far\Plugins)
2) Copy contents of archive in this folder
3) Restart FAR
4) Launch wlx2far and add wlx plugins.
5) At desire use macros (it is necessary to hotkey wlx2far on a key 'G' or to correct
   macros) in a file wlx2far.reg

Working modes:
1) As a lister with set bookmarks which executes from a command line with parameters
2) As a panels of quick viewing

WLX plugins base updating:
Updating can be carried out manually editing wlx2far.ini or from the menu of a plugins.
At editing a file manually it is necessary to be careful - the format of records should
be right, differently all can fall.
A format of records for WLX plugins is following:

Hotkey1 - Plugin alias1 ? Plugin name1 ? Plugin mask1
Hotkey2 - Plugin alias2 ? Plugin name2 ? Plugin mask2
..............................................
HotkeyN - Plugin aliasN ? Plugin nameN ? Plugin maskN

Where: HotkeyN       - Hot key of a plug-in in the wlx2far menu.
                       If is equals ' ' that is not present a hot key.
       Plugin aliasN - Short name of a plugin.
       Plugin nameN  - File name of a plugin. Can be full or relative
                       (from %PATH%).
       Plugin maskN  - Mask of files which are processed by default.
                       Looks like the usual list of FAR masks divided by a comma.
                       Use of masks expediently at fast viewing as in it associations
                       do not work. Lister opening is initiated by command line and
                       can be accordingly caused by means of associations.

Example of wlx2far.ini:
A - IEView ? Plugins\IEView\IEView.wlx ? *.htm,*.html,*.shtml,*.txt,*.plg,*.mht,*.xml,*.xsl
  - MMedia ? Plugins\MMedia\MMedia.wlx ? *.avi,*.mp3,*.mpg

Controlling of a plug-in:
Controlling is carried out or from the FAR plugins menu, or with a command line.
Use of macros from wlx2far.reg is recommended

Controlling from the menu of plugins:
1     - Show/Hide the panel of quick viewing for a current file on active FAR panel
2     - Translate focus in the panel of quick viewing
3     - Update contents of the panel of quick viewing for a new current file
4     - Open a new bookmark in lister for a current file on active FAR panel
5     - Show lister
6     - Hide lister
7     - Search for new wlx plugins
Ins   - Add new WLX plugin (it is possible to set in addition a hot key and a default mask of files)
Del   - Remove current WLX plugin
F4    - Change config of a current WXL plugin (a hot key, a default mask of files)
Enter - Open in the lister a new bookmark for current WLX plugin with the set parameters.
        As parameters the name of a file usually acts, but something can also. For example
        in WebBrowser it is possible to transfer URL (www.farmanager.com)

Controlling from the command line:
wlx:Arguments                                  - Open a new bookmark in listar with default plugin for arguments
                                                 Arguments in current directory.
wlx2far:search Path                            - Search for new WLX plugins in Path
wlx2far:plugin_install PluginName PluginFileName PluginMask - Install new WLX plugin with name PluginName, file name
                                                              PluginFileName and a mask PluginMask
wlx2far:plugin_uninstall PluginName            - Remove WLX plugin with name PluginName
wlx2far:lister_open PluginName Arguments       - Open a new bookmark in listar for plugin PluginName with arguments
                                                 Arguments. If a name of a plugin equally '? ' the first gets out
                                                 a suitable plugin on a mask with arguments Arguments.
wlx2far:lister_show                            - Show lister
wlx2far:lister_hide                            - Hide lister
wlx2far:leftqviewer_open PluginName Arguments  - Open the left panel of fast viewing for plugin PluginName with
                                                 arguments Arguments. If a name of a plugin equally '? ' the first
                                                 gets out a suitable plugin on a mask with arguments Arguments.
wlx2far:rightqviewer_open PluginName Arguments - Open the right panel of fast viewing for plugin PluginName with
                                                 arguments Arguments. If a name of a plugin equally '? ' the first
                                                 gets out a suitable plugin on a mask with arguments Arguments.
wlx2far:leftqviewer_focus                      - translate focus on a left quick viewing panel
wlx2far:rightqviewer_focus                     - translate focus on a right quick viewing panel
wlx2far:leftqviewer_close                      - close left quick viewing panel
wlx2far:rightqviewer_close                     - close right quick viewing panel

Controlling in a mode of quick viewing:
All configuration in wlx2far.keys.ini file

Checked up WLX plugins:
 3DMax
 ActiveSnapView
 AmpView 1.0
 ANSI
 AnyTag
 ArchView
 CADView
 Calendar
 CDRView
 DBFView
 DMFView
 DSView
 Dvi
 Eml
 EventLog
 Excellence
 Factory
 FileInfo
 Filter
 Font
 GDBView
 GDBViewer
 Ghost
 GisLister
 ICLView
 IEView
 Imagine
 IniEd
 JccView
 ListDoc
 MD2wlx
 MDLViewer
 MMedia
 MPlayer
 NFOView
 Office
 OOViewer
 OriginView
 PDBView
 PDFView
 PEViewer
 PictureViewer
 Playlist
 Putty
 ruDwgPreview
 SciLister
 SGViewer
 SolidWorks
 Sudoku
 SWFLst
 SWFView
 SyntaxColorizer
 SynUs
 TTFViewer
 TxQuickView
 URLView
 VisualDirSize
 WaveView
 wcpfrep
 WebBrowser
 WebView
 WiseTracker
 WSZView
 xBaseView

Author information and contacts:
Name  - Shynkarenka Ivan aka 4ekucT
email - at 4enet.by / 4ekucT
ICQ   - 674333
www   - www.depth.belmt.com
