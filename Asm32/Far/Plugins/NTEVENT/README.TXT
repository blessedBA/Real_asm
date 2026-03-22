*********************************** NT ONLY ***********************************

Introduction

NT Events is a plugin for FAR Manager.
It allows to list/backup/clear NT Event Logs.

Status

NT Events is freeware. You can use the binaries and the source code for any
purpose you like.

Warranty
NT Events is distributed "AS IS". No warranty of any kind is expressed or
implied. Use it at your own risk.

Highliting

You may highlight different event types.

REGEDIT4

[HKEY_CURRENT_USER\Software\Far\Colors\Highlight]

[HKEY_CURRENT_USER\Software\Far\Colors\Highlight\GroupV]
"Mask"="*.auf.info"
"NormalColor"=dword:00000014
"CursorColor"=dword:00000000
"IncludeAttributes"=dword:00000000
"ExcludeAttributes"=dword:00000000
"SelectedColor"=dword:00000000
"SelectedCursorColor"=dword:00000000
"MarkChar"=dword:00000000

[HKEY_CURRENT_USER\Software\Far\Colors\Highlight\GroupW]
"Mask"="*.aus.info"
"NormalColor"=dword:00000013
"CursorColor"=dword:00000000
"IncludeAttributes"=dword:00000000
"ExcludeAttributes"=dword:00000000
"SelectedColor"=dword:00000000
"SelectedCursorColor"=dword:00000000
"MarkChar"=dword:00000000

[HKEY_CURRENT_USER\Software\Far\Colors\Highlight\GroupX]
"Mask"="*.inf.info"
"NormalColor"=dword:00000019
"CursorColor"=dword:00000000
"IncludeAttributes"=dword:00000000
"ExcludeAttributes"=dword:00000000
"SelectedColor"=dword:00000000
"SelectedCursorColor"=dword:00000000
"MarkChar"=dword:00000000

[HKEY_CURRENT_USER\Software\Far\Colors\Highlight\GroupY]
"Mask"="*.war.info"
"IncludeAttributes"=dword:00000000
"ExcludeAttributes"=dword:00000000
"NormalColor"=dword:0000001a
"SelectedColor"=dword:00000000
"CursorColor"=dword:00000000
"SelectedCursorColor"=dword:00000000
"MarkChar"=dword:00000000

[HKEY_CURRENT_USER\Software\Far\Colors\Highlight\GroupZ]
"Mask"="*.err.info"
"IncludeAttributes"=dword:00000000
"ExcludeAttributes"=dword:00000000
"NormalColor"=dword:0000001c
"SelectedColor"=dword:00000000
"CursorColor"=dword:00000000
"SelectedCursorColor"=dword:00000000
"MarkChar"=dword:00000000

Contacts

E-mail: zg@matrica.apollo.lv

History

v0.5 build 14 04-05-2003 RC3
- dialog history bug.
- removed unneeded '"'-symbol from resources.
- Crash on ShiftF1.
- ShiftF3/ShiftF4 view event data in viewer/editor.
- gcc 3.2.2.

v0.5 build 13 26-08-2002
- Shift-F2 problem fixed.
- you can customize quickview.
- state saving may be disabled.
- *.info generated mor clearly.
- fixed: params parsing bug.
- state saving improved.
- fixed: memory overrun bug.

v0.5 build 12 01-06-2002
- plugin save all state.
- then file is opened in editor, plugin set R/O attribute for this file.

v0.5 build 11 06-04-2002
- fixed: realloc bug.
- fixed: search bug.
- fixed: bad colors in overwrite dialog in FAR 1.70 beta 4.

v0.4 build 10 17-12-2001 RC2
- workaround for FormatMessage AV.
- memory leak.
- AV fix in cathegory cache.

v0.4 build  9 13-12-2001
- "local" label.
- support multiple event and parameters files.
- AV under stress.
- settings for Esc plugin.
- empty data don't shown.
- changes in documentation.
- fixed: oem problem in categories. introduced in build 6.

v0.3 build  8 22-09-2001 RC1
- now backup work only on local log.
- sid cache optimization.
- small optimization in GetFiles.
- fixed: oem problem in usernames. introduced in build 6.

v0.2 build  7 18-09-2001
- user now in 4th custom column.
- fixed: local time bug. introduced in build 6.
- now you can specify status.
- fixed: sid cache host bug.
- fixed: sid cache domain bug.
- dead code.
- fixed: Shift-Del bug.

v0.2 build  6 08-09-2001
- fixed: creation/modification time bug.
- category full support.
- sid cache.
- Esc processing then log is scanned.
- fixed: memory leak.
- fixed: Alt-Del bug.
- fixed: get full file name then open from command line.
- support "ParameterMessageFile" registry key.
- fixed: inconvenient formatting.
- progress then copying.
- russian .hlf file. thanks a lot to Sergey Morozov <msv-sergey@yandex.ru>

v0.1 build  5 14-07-2001 Beta 1
- hrc for colorer 4ever. thanks a lot to Alexey Yatsenko <alv@hotbox.ru>.
- russian .lng file. thanks a lot to Alexey Yatsenko <alv@hotbox.ru>.
- Shift-F6: local.

v0.1 build  4 06-07-2001 Alfa 2
- fixed: oem problems.
- fixed: didn't display error in some cases.
- fixed: keybar names.
- computer name now may contain oem characters.
- cd behavior changed.
- event content now is recoded to oem.
- fixed: forward/backward.
- more convenient copy routine.
- fixed: instead data displayed garbage.
- fixed: oem problems.
- fixed: evt: prefix sometimes didn't work with files.
- remove ExitFar declaration.

v0.0 build  3 21-06-2001 Alfa 1
- scan type.
- evt prefix.
- fix in SetDirectory.
- partial network support.
- text limited 260 symbols in copy dialog.
- fix: bug in event reading.
- *.evt support.
- backup log.
- very slow get user name.
- add to config menu.
- add to disk menu.
- configuration dialog.

v0.0 build  2 22-05-2001
- clear log.
- key titles.
- local time.
- custom columns.
- lng.

v0.0 build  1 16-05-2001
- first version.
