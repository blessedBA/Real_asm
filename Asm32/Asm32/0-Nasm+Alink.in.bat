;:================================================
;: 0-Nasm+Alink.in.bat                 (c)Ded,2012
;:================================================
@echo off
@echo.
@path bin;..\bin;%path%

set Input=%~n0
set Output=%Input:~0,-3%.asm

subst Y: /d >nul 2>nul
subst Y: "%~dp0."
pushd Y:\

for /f "tokens=1*" %%i in ('Ver') do set Ver=%%i %%j

echo OS Version: %Ver%
echo Input:      %Input%
echo Generating: %Output%

for /f "tokens=4" %%i in ('GetProcAddress kernel32.dll  GetStdHandle') do set  GetStdHandle=0%%ih     
for /f "tokens=4" %%i in ('GetProcAddress kernel32.dll WriteConsoleA') do set WriteConsoleA=0%%ih      
for /f "tokens=4" %%i in ('GetProcAddress kernel32.dll   ExitProcess') do set   ExitProcess=0%%ih    

set .sed.tmp="%Temp%\~%~n0.sed"
set | sed -e "s/[.*^$\[]/\\\0/g" -e "s/\(.\+\)=\(.*\)/s\/$(\1)\/\2\/i/" > %.sed.tmp%
sed -f %.sed.tmp% %Input% > %Output%
del %.sed.tmp% 2>nul

popd
subst Y: /d

