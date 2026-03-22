FAR Resource Browser Plugin 1.00 Beta 5
---------------------------------------

FAR Resource Browser Plugin is freeware product.
It may be freely distributed.

Resource Browser is plugin for FAR Manager.
FAR Manager can be downloaded at:

http://www.rarsoft.com

Resource Browser supports getting resources from executable files

This version supports the following resources:

  - Bitmap
  - Icon
  - Cursor
  - String
  - Menu
  - Version_Info (read only)
  - Dialog (read only, partly)
  - Group_Icon (read only)
  - Group_Cursor (read only)


Plugin provides file description for some items.

Under Windows NT 4.0 or later plugin also supports resource updating.

HOW TO USE
----------
There are three ways to open DLL or EXE file in Resource Browser:

1) Set cursor on the file and press Ctrl+PageDown.

2) Set cursor on the file and call Resource Browser Plugin from
   Plugin commands menu by pressing F11. This method works even
   if you have plugin disabled in configuration.

3) Type in command line:
   resource:filename
   where filename is a name of the file which you want to open.
   This method works even if you have plugin disabled in
   configuration.

If you have collision with other plugins. you can disable Resource 
Browser Plugin in configuration dialog and enter to files via
Plugin commands menu or via command line. 


CONFIGURATION
-------------
To open configuration windows select the following items in FAR menu:
Options / Pligin configuration / Resource browser.
In this dialog you may change the following parameters:

Plugin Enabled    Enables / Disables plugin. It has no effect
                  if you use command line or plugin commands menu
                  for entering plugin.
 
Text in Unicode   If this option is not selected all Unicode resource
                  strings will be converted to ANSI strings and vice versa.


NOTE
----
It is not recommended to delete resource items, since Windows NT 4.0
probably has bug with this function. Please, if you know how to solve
this problem give me to know about it.



INSTALLATION
------------

1) Create "Resource" directory in "Far\Plugins\" directory.
2) Copy all files from this packet to created directory.
3) Restart Far.



  This distrubutive packet contains following files:

  readme.txt    - This file
  file_id.diz   - Short Description file
  History.txt   - History of the Resource Browser
  Resource.dll  - Resource Browser Plugin DLL
  ResEng.hlf    - Help file in English
  ResRus.hlf    - Help file in Russian
  ResEng.lng    - Plugin message strings in English
  ResRus.lng    - Plugin message strings in Russian



INTERNET
--------

http://www.7-zip.com

E-mail: support@7-zip.com


OTHER PRODUCTS
--------------

  FAR Plugins
  ~~~~~~~~~~~
    Text Converter:   Plugin converts word-processing, spreadsheet
                      files to one of the export formats
                      selected by user.  Examples: HTML -> TXT,
                      DOC -> TXT, XLS -> TXT, DOC -> HTML.
                      Plugin Uses MS Office text converters.

    DocFile Browser:  Browsing, viewing and changing contents of the
                      compound files (OLE Starages and Streams):
                      MS Office documents and others.


  Compression software
  ~~~~~~~~~~~~~~~~~~~~
    7-ZIP Archiver:   ZIP format compatibility.
                      Highest compression ratio in ZIP format.
                      Console 32 bit version for Windows 95/98/NT.
                      FAR Support.

    Document Press:   Compressing MS Office documents and other
                      compound files. After compression, files
                      can be used without any decompression.


These and some other programs can be found at:

http://www.7-zip.com


---
  Igor Pavlov, the author of the Resource Browser Plugin.


End of document
