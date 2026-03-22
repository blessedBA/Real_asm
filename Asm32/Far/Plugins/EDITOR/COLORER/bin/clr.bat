@echo off
rem this file for calling colorer as a filter.
rem stdin - input text, stdout - result text
rem it's good for using in FAR editor :)

more > %TMP%\clr.tmp
colorer -c -h %TMP%\clr.tmp %1 %2 %3 %4 %5 %6
del %TMP%\clr.tmp
