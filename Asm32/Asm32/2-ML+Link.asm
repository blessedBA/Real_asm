;:================================================
;: 2-ML+Link.asm                       (c)Ded,2012
;:================================================

; masm + link + LibC

; ml /c "2-ML+Link.asm" /Fl /Sa /Cp /Zi
; link  "2-ML+Link.obj" libcmt.lib kernel32.lib /subsystem:console

.model flat
option casemap: none 

public _main

;includelib libcmt.lib
_printf proto

.code

_main:          push offset MsgText
                call _printf            ; printf (MsgText)
                add esp, 4
                ret

.data

MsgText         db "Hello, World", 0ah, 0

end
