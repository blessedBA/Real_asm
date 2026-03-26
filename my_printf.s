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
global _start
default rel

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
; Destr:  rcx, rdx, rax, r10, r11, r8, r9
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
                je test_percent
                
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

test_percent:   
                cmp al, [rdi + 1]
                je increment_rdi
                jmp char_not_percent 
carry_proc_percent:
                jmp print_cur_char

increment_rdi:
                inc rdi
                jmp carry_proc_percent

char_not_percent:
                inc rdi
                lea r11, [jmp_table]
                xor r12, r12
                mov r12b, [rdi]
                jmp [r11 + (r12 - 'b') * 8]
                jmp print_cur_char    ; you need to add parsing of error or full output %<wrong specificator>

process_char:   
                inc r10
                mov rax, 0x01
                lea rsi, [rsp + r10*8]
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

process_hex:             

                xor r12, r12    ; r12 - flag UZ

                call print_start_hex_value

                inc r10
                mov r11, [rsp + r10*8]
                mov [var2], r11
                mov rcx, 0x0f    ; we start shift from 15 digits
print_hex_loop:
                mov r9, rcx         ; save loop counter
                mov r8, rcx
                shl r8, 2              ; multiply by 4 for nibble shift
                mov cl, r8b            ; shift count must be in cl
                mov r11, [var2]
                shr r11, cl
                mov rcx, r9            ; restore loop counter
                and r11, 0x0f          ; nulling all digits except essential
                cmp r11b, 0xA
                jb  print_digit
                add r11b, 'A' - 10
                jmp print_store

print_digit:
                cmp r11b, 0
                jz check_flag_UZ        ; flag UZ - flag Useless Zeros (there are useless zeros or not in hex value)
                mov r12, 1
carry_proc_hex:
                add r11b, '0'
                jmp print_store

check_flag_UZ:
                test r12, 1
                jnz carry_proc_hex
                dec rcx                 ; if there is useless zero -> just skip digit
                cmp rcx, 0
                jnl print_hex_loop
                jmp end_proc_hex

print_store:
                mov rax, 0x01
                mov [var3], r11
                lea rsi, [var3]
                mov rbx, rdi
                mov rdi, 1
                mov rdx, 1
                mov [var1], rcx
                syscall

                mov rdi, rbx
                mov rcx, [var1]
                dec rcx
                mov r11, [var2]
                cmp rcx, 0
                jnl print_hex_loop
end_proc_hex:
                inc rdi
                jmp next_char

process_bin:
                xor r12, r12
                inc r10

                mov r11, [rsp + r10*8]
                mov [var2], r11
                mov rcx, 63    ; we start shift from 15 digits
print_bin_loop:
                mov r9, rcx             ; save loop counter
                mov cl, r9b             ; shift count must be in cl
                mov r11, [var2]
                shr r11, cl
                mov rcx, r9             ; restore loop counter

                and r11, 1
                jz check_flag2_UZ        ; flag UZ - flag Useless Zeros (there are useless zeros or not in hex value)
                mov r12, 1
carry_proc_bin:
                add r11b, '0'
                jmp print_binary

check_flag2_UZ:
                test r12, 1
                jnz carry_proc_bin
                dec rcx                 ; if there is useless zero -> just skip digit
                cmp rcx, 0
                jnl print_bin_loop
                jmp end_proc_bin

print_binary:
                mov rax, 0x01
                mov [var3], r11
                lea rsi, [var3]
                mov rbx, rdi
                mov rdi, 1
                mov rdx, 1
                mov [var1], rcx
                syscall

                mov rdi, rbx
                mov rcx, [var1]
                dec rcx
                mov r11, [var2]
                cmp rcx, 0
                jnl print_bin_loop

end_proc_bin:
                inc rdi
                jmp next_char

                
process_oct:             
;
;                xor r12, r12    ; r12 - flag UZ
;
;                call print_start_oct_value
;
;                inc r10
;                mov r11, [rsp + r10*8]
;                mov [var2], r11
;                mov rcx, 0x0f    ; we start shift from 15 digits
;print_oct_loop:
;                mov r9, rcx         ; save loop counter
;                mov r8, rcx
;                shl r8, 2              ; multiply by 4 for nibble shift
;                mov cl, r8b            ; shift count must be in cl
;                mov r11, [var2]
;                shr r11, cl
;                mov rcx, r9            ; restore loop counter
;                and r11, 7             ; nulling all digits except essential
;                
;                cmp r11b, 0
;                jz check_flag3_UZ        ; flag UZ - flag Useless Zeros (there are useless zeros or not in hex value)
;                mov r12, 1
;carry_proc_oct:
;                add r11b, '0'
;                jmp print_oct
;
;check_flag3_UZ:
;                test r12, 1
;                jnz carry_proc_oct
;                dec rcx                 ; if there is useless zero -> just skip digit
;                cmp rcx, 0
;                jnl print_oct_loop
;                jmp end_proc_oct
;
;print_oct:
;                mov rax, 0x01
;                mov [var3], r11
;                lea rsi, [var3]
;                mov rbx, rdi
;                mov rdi, 1
;                mov rdx, 1
;                mov [var1], rcx
;                syscall
;
;                mov rdi, rbx
;                mov rcx, [var1]
;                dec rcx
;                mov r11, [var2]
;                cmp rcx, 0
;                jnl print_oct_loop
;end_proc_oct:
;                inc rdi
;                jmp next_char


process_dec:
skip_place:


end_printf:
                POP_ARGS_ABI
                POP_REGS_ABI
                ret

;--------------------------------------------------------------
; Print start of hex value = "0x" (indicator of hex value)
; Expect: nothing
; Destr:  nothing
;--------------------------------------------------------------
print_start_hex_value:

                push rax
                push rdi
                push rsi
                push rdx
                push r11
                push rcx
                
                mov rax, 0x01
                lea rsi, [start_hex_value]
                mov rdi, 1
                mov rdx, len_start_hex_value 
                syscall

                pop rcx
                pop r11
                pop rdx
                pop rsi
                pop rdi
                pop rax

                ret

;-------------------------------------------------------------
; Print start of every octal value - zero
; Expect - nothing
; Destr  - nothing
;-------------------------------------------------------------
print_start_oct_value:
                
                push rax
                push rdi
                push rsi
                push rdx
                push r11
                push rcx
                
                mov rax, 0x01
                lea rsi, [start_oct_value]
                mov rdi, 1
                mov rdx, 1 
                syscall

                pop rcx
                pop r11
                pop rdx
                pop rsi
                pop rdi
                pop rax

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
            var3 dq 0

            jmp_table:
                dq process_bin
                dq process_char
                dq process_dec
                times ('o' - 'd' -1) dq skip_place
                dq process_oct
                times ('s' - 'o' - 1) dq skip_place
                dq process_string
                times ('x' - 's' - 1) dq skip_place
                dq process_hex

            string: db "hello world! %c %s", 0xa
            str_length equ $ - string
            start_hex_value db "0x"
            len_start_hex_value equ $ - start_hex_value
            start_oct_value db '0'