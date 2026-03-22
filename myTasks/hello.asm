;:================================================
;: 0-MacOS-nasm-64.s                   (c)Ded,2012
;:================================================

; nasm -f macho64 -l 1-nasm.lst 1-nasm.s  ;  ld -s -o 1-nasm 1-nasm.o

section .text

global _main                   ; predefined entry point name for MacOS ld

_main:      mov rax, 0x2000004 ; write64bsd (rdi, rsi, rdx) ... r10, r8, r9
            mov rdi, 1         ; stdout
           
            mov rdi, 1

            lea rsi, [rel Msg]
            mov rdx, MsgLen    ; strlen (Msg)
            syscall
            
            mov rax, 0x2000001 ; exit64bsd (rdi)
            xor rdi, rdi
            syscall
            
section     .data
            
Msg:        db "__Hllwrld", 0x0a
MsgLen      equ $ - Msg
