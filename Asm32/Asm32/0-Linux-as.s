;//================================================
;// 0-Linux-as.s                        (c)Ded,2012
;//================================================

;// gcc -c -o 1-as.o 1-as.s             ;  ld -s -o 1-as 1-as.o

;// as  -a -o 1-as.o 1-as.s > 1-as.lst  ;  ld -s -o 1-as 1-as.o

.intel_syntax noprefix

.text

           .globl _start

_start:     mov eax, 0x04      ;// write (ebx, ecx, edx)
            mov ebx, 1         ;// stdout
            mov ecx, Msg
            mov edx, 10        ;// strlen (Msg)
            int 0x80
            
            mov eax, 0x01      ;// exit (ebx)
            xor ebx, ebx
            int 0x80

            ret
            
.data       
            
Msg:        .string "__Hllwrld\n"

