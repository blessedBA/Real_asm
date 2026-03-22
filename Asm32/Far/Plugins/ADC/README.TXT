
Advanced Disk Catalog (ADC) plugin for File and Archive Manager (FAR) v1.47
===========================================================================

Contents
--------

    Common program information
    Contact info
    What is FAR and ADC?
    Program description
    Installation
    Note for Russian citizens
    Release history
    Known problems
    Support
    Plans for near/far future

For registartion and ordering issues see files license.txt and order.txt


Common program information
--------------------------

Program archive name:     adcplug.zip
Program name:             ADC viewer plugin for FAR
Program version:          1.47
Program release date:     February 1, 1998
Program description:      FAR file system plugin for viewing ADC databases
Target OS:                Windows 95/98, Windows NT 4.0/5.0 + FAR 1.52+
Software type:            Shareware ($10)


Contact info
------------

Should you have any questions feel free to write to
Vitaly Klimov at adcplugin@snowball.ru

Latest version of this plugin is always available at
http://www.elcomsoft.com

What is FAR and ADC?
--------------------

1. FAR stands for 'File and Archive manager'

      FAR developed to facilitate a large number of operations with files,
      folders and archives under Windows 95/98 and Windows NT operating
      systems. Note, that FAR is actually a text mode shell.

      More detailed info on FAR can be found at:
                    http://www.creabel.com/softronic

2. ADC stands for 'Advanced Disk Catalog'

      Advanced Disk Catalog (ADC) is an easy to use tool with
      explorer-like interface which allows you to catalog the drives:
      floppy disks, hard drives (including network ones), optical
      disks, CD-ROMs, ZIP disks and other media.

      More detailed info on ADC can be found at:
                  http://www.elcomsoft.com

Program description
-------------------

This program is a plugin intended to work with FAR version 1.52 or higher.
Plugin implements virtual file system based on ADC database files.
Plugin has following features:

1. Lighting fast (up to ten times faster than ADC itself!) database processing
2. Option to treat archives as ordinary folders (*)
3. Ability to view your databases from remote computer without ADC installed
   on this computer (for example via network) (**)
4. Support for ADC categories and descriptions
5. All the virtual file system functionality provided by FAR
   (file find, save path shortcut, etc)

*  - shareware version do not have this feature
** - number of archives treated as directories in shareware version
     limited to 10.

Installation
------------

First, create folder named ADCPLUGIN in FAR\PLUGINS directory.
Second, extract contents of this archive to this directory.
Third, restart FAR.

That's it!

To view ADC database simply press enter or Ctrl-PgDn on it.
To configure ADC plugin, goto to Menu(F9)->Options->Plugins configuration
and select item 'Configure ADC viewer'. For further help simply press F1.

Please note, that ADC plugin will show only databases which created with
ADC version 1.20 or higher. If you have old version, please upgrade it
to 1.20 and load/save your database!


Note for Russian citizens
-------------------------

Text below is for Russian citizens only, please disregard it if you are not.

Если Вы являетесь гражданином России, то можете получить полную версию plugin
бесплатно. Для этого отправьте письмо на адрес adcplugin@snowball.ru с
указанием своего e-mail.


Release history
---------------

1.47 - Bug with OEM(russian for example) category names fixed
       Added option to separate digit groups in info/viewer panels
1.45 - Bugfix: in some cases memory was not freed at all
1.40 - 'files as archives' option status now displayed in panel title
     - Keybar labels corrected
     - Possibility to view details and whole comments (AltF3/AltF4/F4)
1.30 - Quick toggle of 'files as archives' option (Ctrl-A while in catalog)
     - Info about current file displayed on info panel
     - Multiline comments displayed on info panel
     - Possibility to set panel startup mode
1.21 - Fixed weird memory bug (if option 'free memory' was active, wrong
       addresses were freed, resulting unstable system behavior)
1.20 - Added new option 'free memory' (default is on)
       for immediate freeing unused directory data
       thus speeding up search/close process slightly
     - Version info could be found in 'settings' dialog
1.12 - Fixed problem with OEM filenames, first public version
1.11 - Fixed bug with IDX date compare
1.10 - Plugin now is shareware.
       Info panel bug fixed
       Info format improved
1.00 - Initial release


Known problems
--------------

- Supports ADC catalogs only from version 1.20 and higher
- Do not work correct with bad/broken ADC catalogs


Support
-------

This plugin is shareware. Should you have any problems, questions, comments
do not hesitate to write to Vitaly Klimov <adcplugin@snowball.ru>


Plans for near/far future
-------------------------

ADC-style search (with categories, size and data range support)
User customisation for Full (LCtrl-3) view
Possibility to copy files directly from database
Go to disk from database
Merged disks view mode
