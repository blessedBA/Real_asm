section .text

global _main

_main:      


;----------------------------------------------------------------------
; Print string to stdout
; Expect: rdi - adress of string
;----------------------------------------------------------------------
my_printf       proc

                push rax
                mov rax, ""
                cmp rax, [rdi]
                jne end_print

                inc rdi
                cmp rax, [rdi]
                jne end_print

                mov rax, 0x2000004
                lea rsi, [rel rdi]
                mov rdi, 1
                mov rdx, 1
                syscall

                

end_print:      pop rax


section .data

cur_adr_str db 0