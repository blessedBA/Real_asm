                       Search and Replace: A FAR Plug-in
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    (File, which is usually read first ;-))

   If  you  haven't   yet    voted    for    this    plug-in    at    PlugRing:
http://plugring.farmanager.com/cgi-bin/voter.cgi?ID=229  as  actively,  as  you
send me wishes, this world won't get worst 'cose if you do it :-)


   If you want to support program's development, please donate some money. My
     purses in WebMoney.ru (www.wmtransfer.com) system: Z787475721790 (for
           USD), E876273527569 (for Euro). R538290555814 (for RUR).


   I've got a wish to you (don't look back,  actually  to  you):  couldn't  you
(your friends etc.) translate lng, hlf, readme, faq and history  into  English,
German, French or any other language you know, and then send it to me, and I'll
include it into plug-in distribution. I'm just asking for such a  help,  hoping
that there are people, ready to make their "thanks" sensible...


1. What kind of software it is
2. System requirements
3. License
4. Installation and uninstallation
5  Support of the plugin modules
   5.1 System plugin modules
   5.2 User's plugin modules
   5.3 Changes history
6. Changes history
7. New versions location
8. Additional settings

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. What kind of software it is

   This is a FAR plug-in, allowing you to perform search  and  replacements  of
data in a single file, as well as in multiple files at once. Also it  works  in
editor and viewer. It is intended to be used by  Web-masters,  programmers  and
experienced users.

   The main features are the following:
   * You can process files in any codepage, installed in FAR, and in Unicode
   * You can perform hex-codes search and replacements
   * You can use regular expressions in search and replacement lines, and for
     file-masks
   * You can save schemes and use them later
   * You can specify processed files date, size, attributes limits
   * You can specify processed folders list
   * You can translate data from any codepage into any other (except Unicode)
   * It's possible to count occurrences of the string, being searched  for,  in
     editor, viewer or in multiple files
   * Work in selected area in editor
   * Convenient navigation on found occurrences in editor
   * Support of extension of possibilities through external plugin modules.
     Already exist and work:
       * NewName: files renaming with regular expression usage
       * Dir2File: file list creator - multifunction  plugin  module  which  is
         capable  to  generate  everything,  everything,  by  your  rules.  For
         example, you can:
           * create html-page with pictures from the current directory
           * create bat-files with complex commands of processing of
             necessary files
           * copy your internet shortcuts (*.url) in one html-page
           * et cetera, et cetera... All depends on your imagination :-)
       * VerInfo: versionInfo viewer
   * Et cetera, et cetera...

   I recommend you to read help (it  isn't  big,  but  several  questions  will
have an answer) and FAQ.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
2. System requirements

   Far 1.6x: main plugin features will work.
   Far 1.70 build 1634 and above:
     - you can use file attributes
     - plugin can use "smart" dialogs
     - plugin can search in internal FAR viewer
     - plugin's autoopen in the "locked" editor

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
3. License

   Read the license (License.txt), please - everything's written there.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
4. Installation and uninstallation

   Installation is the same as for most part of FAR plug-ins:
   -  make  an arbitrary  named  subfolder  in  Far\Plugins  and   copy   files
s_and_r.dll, *.hlf, *.lng, *.srp, *.msg, folder  SRPlugins  (with  subfolders),
folder System (with subfolders).
   - if it's needed, import Reg\FATypes.reg into registry - it contains several
filetypes' settings, which are used to  search  sections  in  the  file,  being
edited. If you have similar settings for different filetypes, send them to  me,
and I'll include them in the distribution on the plug-in.
   - If you use 2nd level plug-in newname.srp,  import  newnamescheme.reg  into
registry. It contains an example  of  schemes,  designed  to  replace  standard
"FileCase" plug-in capabilities.
   - If you use 2nd level plug-in dir2file.srp, import dir2file_scheme.reg into
registry. It contains an example of schemes for this plugin module.
   - Restart FAR
   - In plug-ins menu (F11) the S&R item appears - use it
     (you can run plug-in from the command line also - look help for details)

   For plug-in usage in  editor  and  viewer  convenience  you  can  "overload"
standard FAR functions with macros. Examples of macros  ready  to  use  are  in
*.reg files of this distribution.

   Plug-in uninstallation:
   - remove the plug-in folder, you've created during  installation  (possibly,
you'll need to restart FAR to release s_and_r.dll)
   - remove all macros, which use S&R - they are useless now
   - remove plug-in's registry entries (for example, by running uninstall.reg)

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
5. Support of plugin modules

   The program realizes some functions through external plugin modules.  Plugin
modules can be divided into two types: system and user's.

   All the plugins supplied with S&R are designed only for the version  of  S&R
with which they are supplied. It is not guaranteed that standard  plugins  will
function correctly with different S&R versions.

   5.1. System plugin modules
   ~~~~~~~~~~~~~~~~~~~~~~~~~~
   System plugin modules realize some internal functions of  the  S&R  and  for
convenience of development  and  uses  they  are  physically  arranged  not  in
s_and_r.dll, but  in  dynamic-link  libraries.  They  have  SRS  extension  and
together with the messages (msg-files) must be placed in the System subfolders.
Do not change their names.

   5.2. User's plugin modules
   ~~~~~~~~~~~~~~~~~~~~~~~~~~
   User's plugin modules realize additional functions of S&R.  They  must  have
SRP extension. Program searches for them in folder SRPLugins and all  its  sub-
folders  (SRPlugins  directory  should  be  located  in  the  same  folder   as
s_and_r.dll, also see "Other options").

   It is possible to write plugin modules for panels, editor and viewer.

   Documentation  for   writing    external    plugin    modules    for     S&R
(unfortunately, only in Russian) in chm or html format is placed on my site.

   Example of user's plugin module in C++ (example is the sources of any  (your
choice) from standard plugin modules) will be sent on the your request.


   5.3. Changes history
   ~~~~~~~~~~~~~~~~~~~~~~
   See srp_history.txt

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
6. Changes history

   See historyEng.txt

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
7. New versions location

   At first, I place all my creations here: http://www.moris.ru/~spinoza

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
8. Additional settings

   In this chapter you  can  find  description  for  several  parameters  which
affects plug-in behavior, but they are not accessible  in  configuration  menu.
These parameters are saved as all other plug-in's settings - usually  it's  the
following registry branch:  HKCU\Software\Far\Plugins\S_And_R.  After  some  of
these parameters change, you'll have to restart FAR.

   "UFH"=dword:00000001
   If value is equal to 00000001, first line from FAR  "history"  is  used  for
search, replacement and file mask string, if 00000000, then  specified  strings
are taken from inner plug-in's variables. Default is 00000001.

   "Prefix"="S&R"
   Prefix to run plug-in from command line. Possible size -  up  to  63  bytes.
Default is "S&R". After this  parameter  change  it  may  be  needed  to  clear
plug-ins cache (see FAR\ClearPluginsCache.bat)

   "LogDir"=""
   Folder to create the log. If this variable is absent or it's equal to  null,
log is created in the current folder. Possible to  use  environment  variables.
You'd use OEM codepage. Maximum size is 256 bytes.

   "CPN"=dword:0000000A
   Temporary panels number. Default is 10. Possible value: from 2 to 64.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   Thanks for using S&R.

                                                                 Ivan Sintyurin
                                                       Sat 04 Feb 17:12:30 2006
