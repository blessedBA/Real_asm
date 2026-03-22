;:================================================
;: 2-Nasm+Link.asm                     (c)Ded,2012
;:================================================

; nasm + link + LibC

; nasm "2-Nasm+Link.asm" -f win32 -l "2-Nasm+Link.lst"
; link "2-Nasm+Link.obj" libcmt.lib kernel32.lib /subsystem:console

global _main
extern _printf
 
section .text

_main:          push dword Text
                call _printf            ; printf (MsgText)
                add esp, 4
                ret

section .data

Text            db "Hello, World", 0ah, 0
