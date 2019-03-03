global _start
_start:

section .text
	
	;Display Macro
	
	%macro disp 2                              ;2 parameters
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
	%endmacro
	
	;Accept Macro
	
	%macro accept 2                            ;2 parameters
	mov rax,0
	mov rdi,0
	mov rsi,%1
	mov rdx,%2
	syscall
	%endmacro
	

        disp_menu:
        
	        disp menu,len                       ;Display Menu
	        accept choice,2                     ;Accept Choice
	
	        mov al,byte[choice]                 ;Move choice into al
	        cmp al,31h                          ;compare with 31h (=1)
	        je menu_lable1
	     	cmp al,32h                          ;compare with 32h (=2)
	        je menu_lable2
	        cmp al,33h                          ;compare with 33h (=3)
	        je menu_lable3
	   
	
        menu_lable1:
		
	        ;Copy Array using string instructions
	
	        cld                                 ;Clear direction flag
	        mov rsi,arr1                        ;Move array1 in rsi
	        mov rdi,arr2                        ;Move array2 in rdi
	        mov rcx,10                          ;count = 10
	        rep movsb                           ;repeat
	        jmp disp_array
	     
		
	menu_lable2:
	
	        ;Copy Array without string instructions
	        
	        mov rsi,arr1                        ;Move array1 in rsi
	        mov rdi,arr2                        ;Move array2 in rdi
	
	        move_block:                         ;Loop to put elements into array
		        mov al,[rsi]                
		        mov [rdi],al
		        inc rsi                     	;Increment rsi
		        inc rdi                    	 	;Increment rdi
		        dec byte[cnt1]              	;Decrement cnt
		        jnz move_block              	;Jump if not zero
		jmp disp_array
		       	
        disp_array:
	
	        disp msg1,len1	
	        mov cl,10                           ;cl = 10
	        mov byte[cnt3],cl                   ;Set cnt1 3 with 10
	
	        mov rdi,arr2                    
	
	        loop:
		        mov al,[rdi]
		        push rdi
		        call display
		        pop rdi
		        inc rdi
		        dec byte[cnt3]
		        jnz loop
		        jmp disp_menu
		
	;To call end
        
        menu_lable3:							;End Program
	        mov rax,60
	        mov rdi,0
	        syscall
	
	;Display Procedure
	
	display:
	mov rsi,arr+1
	mov rcx,2

	loop1:
		mov rdx,0
		mov rbx,10h
		div rbx
		cmp dl,09h
		jbe l1
		add dl,07h

	l1:
		add dl,30h
		mov [rsi],dl
		dec rsi
		dec rcx
		jnz loop1

	mov rax,1
	mov rdi,1
	mov rsi,arr
	mov rdx,2
	syscall
	disp msg2,len2
	ret


section .data
	
	arr1 db 01h,02h,03h,04h,05h,06h,07h,08h,09h,0Ah
	arr2 db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
	
	cnt1 db 10
	cnt2 db 10
	cnt3 db 10
	
	msg1 db "Copied Array:",10
	len1: equ $-msg1
	
	msg2 db " ",10
	len2: equ $-msg2
	
	menu  db "-----MENU-----",10
	      db "1. Non Overlap transfer with String",10
	      db "2. Non Overlap transfer without String",10
	      db "3. Exit",10
	      db "Enter your choice: "
	len: equ $-menu
	

section .bss
	arr resb 16
	choice resb 2
