%include "macro.asm"

global proc
extern buf,abuf

global _main
_main:

section .text

        proc:
                ;disp buf,[abuf]
                disp msg1,len1
                accept char1,3
                
                mov bl,[char1]
                mov rcx,[abuf]
                mov rsi,buf
                
                l5:
                        mov al,[rsi]
                        cmp al,0Ah			; check for carriage return (enter)
                        je l1
                        cmp al,20h			; check for space
                        je l2
                        cmp al,bl			; check for character occurance
                        je l3
                        
                        jmp l4
                
                l1:
                        inc byte[linecount]
                        jmp l4
                l2:
                        inc byte[spacecount]
                        jmp l4
                l3:
                        inc byte[charcount]
                        jmp l4
                
                l4:
                        inc rsi
                        dec rcx
                        jnz l5
                        
                        
                disp msg3,len3
                ;inc byte[linecount]
                mov ax,[linecount]
                call display
                
                disp msg4,len4
                mov ax,[spacecount]
                call display
                
                disp msg5,len5              
                mov ax,[charcount]
                call display
           
        ret
        
        
        display:
                mov rsi,arr+3
                mov rcx,4

                loop1:
	                mov rdx,0
	                mov rbx,10h
	                div rbx
	                cmp dl,09h
	                jbe l8
	                add dl,07h

                l8:
	                add dl,30h
	                mov [rsi],dl
	                dec rsi
	                dec rcx
	                jnz loop1


                mov rax,1
                mov rdi,1
                mov rsi,arr
                mov rdx,4
                syscall
                disp msg2,len2
                ret
				
section .data

    msg1 db 10,"Enter charcter: "
	len1: equ $-msg1
	
	msg2 db " ",10
	len2: equ $-msg2
	
	msg3 db "Number of lines: "
	len3: equ $-msg3
	
	msg4 db "Number of spaces: "
	len4: equ $-msg4
	
	msg5 db "Occurance of character: "
	len5: equ $-msg5
  

section .bss
	char1 resb 50
	linecount resb 50
	spacecount resb 50
	charcount resb 50
	arr resb 50
                
