section .text

global _start

_start:      

                
                mov rdi, string
               ;mov rcx, str_length
                call my_printf
                
                mov rax, 0x3C      ; exit64 (rdi)
                xor rdi, rdi
                syscall
                
;----------------------------------------------------------------------
; Print string to stdout
; Expect: rdi - adress of string; rcx - length of string
; Destr:  rdi, rcx, rdx
;----------------------------------------------------------------------
my_printf:       

                push rax
                push rbx

next_char:      
                mov rax, '$'
                cmp al, byte [rdi]  ; test end of string
                je end_printf

                mov rax, 0x01
                lea rsi, [rel rdi]
                mov rbx, rdi
                mov rdi, 1
                mov rdx, 1
                syscall

                mov rdi, rbx
                inc rdi
                ;loop next_char
                jmp next_char

                

end_printf:     pop rbx
                pop rax
                ret

section .data

string: db "hello world!$", 0xa
str_length equ $ - string