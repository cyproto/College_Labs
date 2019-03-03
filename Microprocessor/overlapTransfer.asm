global _start:
_start:

section .text
	
	;Display Macro                         ;2 parameters

	%macro disp 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
	%endmacro
	
	;Accept Macro
	
	%macro accept 2                        ;2 parameters
	mov rax,0
	mov rdi,0
	mov rsi,%1
	mov rdx,%2
	syscall
	%endmacro
	

        disp_menu:
        
	        disp menu,len                   ;Display Menu
	        accept choice,2                 ;Accept Choice
	
	        mov al,byte[choice]
	        cmp al,31h                      ;compare with 31h (=1)
	        je menu_lable1
	     	cmp al,32h                      ;compare with 32h (=2)
	        je menu_lable2
	        cmp al,33h                      ;compare with 33h (=3)
	        je menu_lable3
	        
	
	
	
	
        menu_lable1:                        ;Menu lable for string instn
        
		std                                 ;Set Direction flag
	        mov rsi,arr1                    ;move arr1 in rsi
	        mov rdi,arr1                    ;move arr1 in rdi
	        add rsi,09                      ;Add rsi with 09
	        add rdi,13                      ;Add rdi with 13
	        mov rcx,10
	        rep movsb                       ;Repeat
	        
	        jmp disp_array
	   
	
	menu_lable2:                            ;Menu lable for without string 
	
	        mov rsi,arr2                    ;move arr2 in rsi
	        mov rdi,arr2                    ;move arr2 in rsi
	        add rsi,09                      ;Add rsi with 09
	        add rdi,13                      ;Add rdi with 13
	        
	        loop4:
	                mov al,[rsi]
	                mov [rdi],al
	                dec rsi
	                dec rdi
	                dec byte[cnt2]
	                jnz loop4
	                
	        jmp disp_array
	
	        
		       	
        disp_array:                          ;Display Array procedure
	
	        disp msg1,len1	
	        mov cl,15                        ;cl = 15
	        mov byte[cnt3],cl                ;Set cnt3 with 15
	
	        mov rdi,arr1                     ;move arr1 into rdi
	
	        loop:
		        mov al,[rdi]                 ;move each element in al
		        push rdi                     ;push into stack
		        call display                 ;Display 
		        pop rdi                      ;pop out of stack
		        inc rdi 
		        dec byte[cnt3]               ;Decrement cnt3
		        jnz loop
		        jmp disp_menu
		
	;To call end
        
        menu_lable3:	
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
	mov rdx,2
	syscall
	disp msg2,len2
	ret

	
	

section .data
	
	arr1 db 01h,02h,03h,04h,05h,06h,07h,08h,09h,0Ah,0Bh,0Ch,0Dh,0Eh,0Fh
	arr2 db 01h,02h,03h,04h,05h,06h,07h,08h,09h,0Ah,0Bh,0Ch,0Dh,0Eh,0Fh
		
	cnt1 db 10
	cnt2 db 10
	cnt3 db 15
	
	msg1 db "Array after operation:",10
	len1: equ $-msg1
	
	msg2 db " ",10
	len2: equ $-msg2
	
	menu  db "--------MENU--------",10
	      db "1. Overlap transfer with String",10
	      db "2. Overlap transfer without String",10
	      db "3. Exit",10
	      db "Enter your choice: "
	len: equ $-menu
	

section .bss
	arr resb 16
	choice resb 2
