
.model flat, C

;------------------------------------------------

printf          proto fmtStr: ptr, args: vararg

;------------------------------------------------
.data

PrintfStr       db "SubFunc(): %d - %d = %d", 0dh, 0ah, 0

;------------------------------------------------
.code

SubFunc         proc a: dword, b: dword
                push esi

                mov eax, a
                sub eax, b
                mov esi, eax

                push esi
                push b
                push a
                push offset PrintfStr
                call printf
                add esp, 4*4

                invoke printf, offset PrintfStr, a, b, esi

                mov eax, esi
                pop esi
                ret

SubFunc         endp

;--------------------------------------------------

end
