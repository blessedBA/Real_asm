DocFile Browser Plugin for FAR 1.02
-----------------------------------

DocFile Browser is plugin for FAR Manager.
DocFile Browser allows browsing, viewing and changing contents of
compound files.

DocFile Browser is freeware product. It may be freely distributed.

FAR Manager can be downloaded from
http://www.rarsoft.com


What is a COMPOUND FILE?
~~~~~~~~~~~~~~~~~~~~~~~~
Compound file is a number of individual files bound together in one
physical file. Some  Microsoft's programs write data to compound 
files. The examples of programs that write data to compound files are
the most of the MS Office programs: Word, Excel, PowerPoint.

MSI (Installation package for Windows) and CHM (HTML Help) files also 
are compound files.


HOW TO USE
----------
There are three ways to open compound file in DocFile Browser:

1) Set cursor on the file and press Ctrl+PageDown.

2) Set cursor on the file and call DocFile Browser Plugin from
   Plugin commands menu by pressing F11. This method works even
   if you have plugin disabled in configuration.

3) Type in command line:
   DocFile:filename
   where filename is a name of the file which you want to open.
   This method works even if you have plugin disabled in
   configuration.

If you have collision with other plugins. you can disable DocFile
Browser Plugin in configuration dialog and enter to document files
via Plugin commands menu or via command line. 


Files in the compound file are handled in the same manner as if
they were in a folder. Plugin supports creating new substorages
by pressing F7.


CONFIGURATION
-------------
To open configuration window select the following items in FAR menu:
Options / Pligin configuration / DocFile browser.
In this dialog you may change the following parameters:

Plugin Enabled    Enables / Disables plugin. It has no effect
                  if you use command line or plugin commands menu
                  for entering plugin.
 

NOTE
----
DocFile Browser opens compound file in EXCLUSIVE mode. Thus,
you can not open already open file by other copy of the
DocFile Browser or by any other application.

DocFile Browser supports MSI files (thanks to Michael Yutsis).



INSTALLATION
------------

1) Create "DocFile" directory in "Far\Plugins\" directory.
2) Copy all files from this packet to created directory.
3) Restart Far.



  This distrubutive packet contains following files:

  readme.txt    - This file
  file_id.diz   - Short Description file
  History.txt   - History of the DocFile Browser
  DocFile.dll   - DocFile Browser Plugin DLL
  ResEng.hlf    - Help file in English
  ResRus.hlf    - Help file in Russian
  ResEng.lng    - Plugin message strings in English
  ResRus.lng    - Plugin message strings in Russian



INTERNET
--------

http://www.7-zip.org
        
E-mail: support@7-zip.org


OTHER PRODUCTS
--------------

  FAR Plugins
  ~~~~~~~~~~~

    Resource Browser: Extracting and updating resources in EXE and
                      DLL files. Supported resources:
                      Bitmap, Icon, Cursor, String, Menu,
                      Version_Info, Dialog, Group_Icon, Group_Cursor


  Compression software
  ~~~~~~~~~~~~~~~~~~~~
    7-Zip:            7-Zip is a file archiver with the highest 
                      compression ratio. The program supports 7z, 
                      ZIP, RAR, CAB, GZIP, BZIP2 and TAR formats. 
                      Compression ratio in the new 7z format 
                      is 30-50% better than ratio in ZIP format. 
                      Also 7-Zip compresses to ZIP 2-10% better 
                      than PKZip and WinZip. 7-Zip has additional 
                      powerful command line version and FAR Manager 
                      support.   ZIP format compatibility.


These and some other programs can be found at:

http://www.7-zip.org



---
  Igor Pavlov, the author of the DocFile Browser Plugin.



End of document
