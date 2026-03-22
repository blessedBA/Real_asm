;:================================================
;: 1-ML+Link(2).asm                    (c)Ded,2012
;:================================================

; masm + link + WinAPI + LibC

; ml /c "1-ML+Link(2).asm" /Fl /Sa /Cp /Zi
; link  "1-ML+Link(2).obj" kernel32.lib user32.lib libcmt.lib /subsystem:console

;-------------------------------------------------              

.model flat, stdcall
option casemap: none

;-------------------------------------------------              

;includelib kernel32.lib
GetStdHandle  proto :dword
WriteConsoleA proto :dword, :dword, :dword, :dword, :dword
ExitProcess   proto :dword

STD_OUTPUT_HANDLE equ -11d

;includelib user32.lib
MessageBoxA proto :dword, :dword, :dword, :dword

;includelib libcmt.lib
strlen proto C: dword

;-------------------------------------------------              

PutS proto: dword

;-------------------------------------------------              
.data
MsgTitle        db "Title", 0ah, 0
MsgText         db "Text",  0ah, 0

;-------------------------------------------------              
.code
Start:          invoke PutS, offset MsgText

                invoke MessageBoxA, 0, offset MsgText, offset MsgTitle, 0

                invoke ExitProcess, 0

;-------------------------------------------------              
.code
PutS            proc msg: dword

                invoke GetStdHandle, STD_OUTPUT_HANDLE
                push eax

                invoke strlen, msg

                pop edx
                invoke WriteConsoleA, edx, msg, eax, 0, 0

                ret
PutS            endp

;-------------------------------------------------              

end Start
