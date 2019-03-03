global _start
_start:

section .text
        
    ;Display Macro
	
	%macro disp 2                           ;2 parameters
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
	%endmacro
	
	;Accept Macro
	
	%macro accept 2                         ;2 parameters
	mov rax,0
	mov rdi,0
	mov rsi,%1
	mov rdx,%2
	syscall
	%endmacro
	
        disp msg1,len1
        accept num,03
        call convert
        mov [cnt],rax
        dec byte[cnt]
        cmp al,01h
        jle l6
        disp msg3,len3
        
        fact:
                push rax
                dec rax
                cmp rax,01h
                jne fact   
               
        l5:
                pop rbx
                mul rbx
                dec byte[cnt]
                jnz l5
                
                
                call display
                call exit
                
        l6:
               disp msg4,len4 
               call exit
                
	convert:
   
        mov rsi,num                       ;Move no into rsi (index)
        mov al,[rsi]                     ;Move content of rsi into al
        cmp al,39h                       ;Compare
        jle l1                           ;Jump if equal
        sub al,07h
        
        l1:
        sub al,30h
        
        rol al,04                        ;Rotate by 4
        mov bl,al
        inc rsi
        mov al,[rsi]                     ;Move 2nd numnber                
        cmp al,39h
        jle l2                           ;Jump if equal
        sub al,07h
        
        l2:
               sub al,30h
     
        add al,bl
        ret

	display:
 
	mov rsi,arr+15
	mov rcx,16

	loop1:
		mov rdx,0
		mov rbx,10h
		div rbx
		cmp dl,09h
		jbe l3
		add dl,07h

	l3:
		add dl,30h
		mov [rsi],dl
		dec rsi
		dec rcx
		jnz loop1


	mov rax,1
	mov rdi,1
	mov rsi,arr
	mov rdx,16
	syscall
	
	
	exit:   
		;To call end
		disp msg2,len2
	   
		mov rax,60
		mov rdi,0
		syscall
		
section .data

	msg1 db "Enter the number: "
	len1: equ $-msg1

	msg2 db " ",10
	len2: equ $-msg2 

	msg3 db 10,"Factorial is: "
	len3: equ $-msg3

	msg4 db 10,"Factorial is: 01"
	len4: equ $-msg4
	
section .bss

   arr resb 16
   num resb 5
   cnt resb 32
