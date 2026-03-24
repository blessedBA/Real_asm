%macro PUSH_ARGS_ABI 0
        push r9
        push r8
        push rcx
        push rdx
        push rsi
        push rdi
%endmacro

%macro POP_ARGS_ABI 0
        pop rdi
        pop rsi
        pop rdx
        pop rcx
        pop r8
        pop r9
%endmacro

%macro PUSH_REGS_ABI 0
        push rbx
        push rbp
        push r12
        push r13
        push r14
        push r15
%endmacro

%macro POP_REGS_ABI 0
        pop r15
        pop r14
        pop r13
        pop r12
        pop rbp
        pop rbx
%endmacro

section .text

;global _start

global my_printf

;_start:      
;                mov rdi, string
;                mov rsi, arg1
;                mov rdx, arg2 
;                call my_printf
;                
;                mov rax, 0x3C      ; exit64 (rdi)
;                xor rdi, rdi
;                syscall
                
;----------------------------------------------------------------------
; Print string to stdout
; r10 - count processed arguments
; Expect: rdi - 1st argument (adress of main string)
;         rsi - 2nd argument
;         ...
;         r9  - 6th argument
; Destr:  rcx, rdx, rax, r10, r11
;----------------------------------------------------------------------
;----------------------------------------------------------------------
;       TRUMPLINE
;----------------------------------------------------------------------
my_printf:
                PUSH_REGS_ABI
                PUSH_ARGS_ABI
                jmp my_printf_main

my_printf_main:       

                xor r10, r10           ; r10 - count processed arguments
                mov rdi, [rsp + r10]  ; load adress of main string in rdi
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
                syscall

carry_processing:
                mov rdi, rbx

carry_processing_2:

                inc rdi
                xor al, al
                cmp al, [rdi]   ; check end of string (\0)
                jne next_char
                jmp end_printf

test_procent:   
                cmp al, [rdi + 1]
                je print_cur_char

                inc rdi
                mov al, 'c'
                cmp al, [rdi]
                je process_char
                mov al, 's'
                cmp al, [rdi]
                je process_string
                jmp print_cur_char    ; you need to add parsing of error or full output %<wrong specificator>

process_char:   
                inc r10
                mov rax, 0x01
                mov r11, [rsp + r10*8]
                lea rsi, [rel r11]
                jmp short_print_cur_char 
                
process_string:
                inc r10
                mov r11, [rsp + r10*8]
                xor rcx, rcx
carry_proc_str:
                mov al, 0
                cmp byte [r11 + rcx], al
                je carry_processing_2

                mov rax, 0x01
                lea rsi, [rel r11 + rcx]
                mov rbx, rdi
                mov rdi, 1
                mov rdx, 1
                mov [var1], rcx
                mov [var2], r11
                syscall
                
                mov rdi, rbx
                mov rcx, [var1]
                mov r11, [var2]
                inc rcx
                jmp carry_proc_str

end_printf:
                POP_ARGS_ABI
                POP_REGS_ABI
                ret


section .data

            curr_arg dq 0
            arg1 db 'Q'
            arg2 db "i am cockblock"
            arg2_len equ $ - arg2
            arg3 db 0
            arg4 db 0
            arg5 db 0
            arg6 db 0
            
            var1 dq 0
            var2 dq 0

            table dq process_char, process_string

            string: db "hello world! %c %s", 0xa
            str_length equ $ - string