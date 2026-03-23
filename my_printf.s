section .text

global _start

_start:      

                
                mov rdi, string
                mov rcx, str_length
                call my_printf
                
                mov rax, 0x3C      ; exit64 (rdi)
                xor rdi, rdi
                syscall
                
;----------------------------------------------------------------------
; Print string to stdout
; Expect: rdi - adress of string; 
;         rcx - length of string
;         arg1 - 1st argument
;         arg2 - 2nd argument
;         ...
;         arg6 - 6th argument
; Destr:  rdi, rcx, rdx
;----------------------------------------------------------------------
my_printf:       

                push rax
                push rbx
                push r8

next_char:      
                mov al, '%'
                cmp al, [rdi]
                je test_procent
                
print_cur_char:

                mov rax, 0x01
                lea rsi, [rel rdi]

short_print_cur_char:

                mov rbx, rdi
                mov rdi, 1
                mov rdx, 1
                mov r8, rcx
                syscall

carry_processing:
                mov rcx, r8
                mov rdi, rbx
                inc rdi
                loop next_char
                jmp end_printf

test_procent:   
                cmp al, [rdi + 1]
                je print_cur_char

                inc rdi
                dec rcx
                mov al, 'c'
                cmp al, [rdi]
                je process_char
                mov al, 's'
                cmp al, [rdi]
                je process_string
                jmp print_cur_char    ; you need to add parsing of error or full output %<wrong specificator>

process_char:   
                mov rax, 0x01
                lea rsi, arg1
                jmp short_print_cur_char 
                
process_string:
                mov rax, 0x01
                lea rsi, [rel arg2]
                
                mov rbx, rdi
                mov rdi, 1
                mov rdx, arg2_len
                mov r8, rcx
                syscall
                jmp carry_processing

end_printf:     pop r8
                pop rbx
                pop rax
                ret


section .data

            arg1 db 'Q'
            arg2 db "i am cockblock"
            arg2_len equ $ - arg2
            arg3 db 0
            arg4 db 0
            arg5 db 0
            arg6 db 0

            table dq process_char, process_string

            string: db "hello world! %c %s", 0xa
            str_length equ $ - string