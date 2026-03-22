Backup Editor files plugin v0.5b
--------------------------------

This plugin enables creation of BAK files in internal editor.


INSTALLATION
------------

1. Create "Backup" directory in "Far\Plugins\Editor\" directory.
2. Copy all files from this archive to this directory.
3. Restart FAR
4. Choose Options->Plugins configuration->Backup Editor Files (or
   Параметры->Параметры внешних модулей->Создавать BAK файлы) and
   configure plugin as you wish

HISTORY
-------

v1.0  21.11.99 - fixed bug with appending extensions

                 now you can disable creating copies in FarTmp directories

                 it is possible to create copies in specified folder
                 without changing file names

v0.5b 22.07.99 - folder for backup copies is now created if not exists

                 it is possible not to change file extension, but append
                 '.bak' one to file name (e.g. filename.ext.bak,
                 filename.ext.b00)

                 it was bug with creation only one copy when several
                 editor sessions were opened at the same time

                 now you can enable backup creation only to current
                 session by selecting corresponding item in editor plugin
                 menu (accessed by F11 key)

v0.4b 19.07.99 - it is possible to save copies to specified folder
                 configure dialog is now accessible in editor

v0.3b 23.06.99 - it is possible to create only one copy in one editor
                 session

                 it is possible to create a copy at editor start

v0.2b 19.05.99 - it is possible to create B00, B01, ... files

v0.1b 14.05.99 - first version

CONTACTS
--------

(c) 1998-99 by Ilya V. Gershman
email ilya@oasis.cctpu.edu.ru
fido  2:5005/26.39
ICQ   14863431
