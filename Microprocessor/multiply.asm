global _start
_start:

section .text

    ;Display Macro
	
	%macro disp 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
	%endmacro
	
	;Accept Macro
	
	%macro accept 2
	mov rax,0
	mov rdi,0
	mov rsi,%1
	mov rdx,%2
	syscall
	%endmacro
	
	disp_menu:
        
	        disp menu,len                       ;Display Menu
	        accept choice,2                     ;Accept Choice
	        disp menu1,menlen
	
	        mov al,byte[choice]
	        cmp al,31h                          ;compare with 31h (=1)
	        je menu_lable1
	     	cmp al,32h                          ;compare with 32h (=2)
	        je menu_lable2
	        cmp al,33h                          ;compare with 33h (=3)
	        je menu_lable3
	        
	        
	        
        menu_lable1:
        
                disp msg3,len3
	        accept no,3                        ;Accept no
	        call convert
	        mov [no1],al                       ;move converted no into no1
	
	        disp msg4,len4
	        accept no,3                        ;Accept no
	        call convert
	        mov [no2],al                       ;move converted no into no2
                
                disp msg5,len5
                mov bx,0000h
                mov [result],bx                ;Set Result with 0000h
                mov ax,[no1]                   ;move no1 into ax
                
                loop3:                  
                        add [result],ax         ; Add( ax+0000h )
                        dec byte[no2]           ;Decrement no2 used as count
                        jnz loop3               ;Repeat until no2 becomes 0
                        
                mov ax,[result]                 ;move ax into Result
                call display                    ;Display Result
                jmp disp_menu
                
        menu_lable2:
                
                disp msg3,len3
	        accept no,3                         ;Accept no
	        call convert
	        mov [no1],al                        ;move converted no into no1
	
	        disp msg4,len4
	        accept no,3                         ;Accept no
	        call convert
	        mov [no2],al                        ;move converted no into no2
               
                
                disp msg5,len5
                mov bx,0000h                    ;Set bx with 0000h
                mov [result1],bx                ;result = 0000h
                
                mov ax,[no1]                    ;Move no1 into ax
                mov bx,[no2]                    ;Move no2 into bx
                
                loop7:
                        shr bx,01               ;Shift right by 1
                        jnc shift               ;Jump if no carry
                        add [result1],ax        ;Add
                        
                        shift:
                                shl ax,01       ;Shift left by 1
                                cmp ax,0        ;Compare
                                je disp_res     ;Jump if equal
                                cmp bx,0
                                je disp_res     ;Jump if equal
                                jmp loop7
                disp_res:
                
                        mov ax,[result1]
                        call display
                        jmp disp_menu
                   
                
        
        menu_lable3:
        
                ;To call end
                mov rax,60
                mov rdi,0
                syscall
                
        ;Convert Procedure
        
        convert:
                
                mov rsi,no                       ;Move no into rsi (index)
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
	        jle l2                           	 ;Jump if equal
	        sub al,07h
	        
	        l2:
	        sub al,30h
	     
	        add al,bl
	        ret
	        
        ;Display Procedure
	
	display:
	        mov rsi,arr+3
	        mov rcx,4

	        loop1:
		        mov rdx,0
		        mov rbx,10h
		        div rbx
		        cmp dl,09h
		        jbe l4
		        add dl,07h

	        l4:
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

        menu  db 10,"--------MENU--------",10
	      db "1. Successive Addition Method.",10
	      db "2. Add & Shift Method.",10
	      db "3. Exit.",10
	      db "Enter your choice: "
	len: equ $-menu
	
	menu1 db "------------------------",10
	menlen: equ $-menu1
	
	msg1 db"Multiplication is: "
	len1: equ $-msg1
	
	msg2 db " ",10
	len2: equ $-msg2 
	
	msg3 db 10, "Enter 1st number: "
	len3: equ $-msg3
	
	msg4 db "Enter 2nd number: "
	len4: equ $-msg4
	
	msg5 db 10,"Multiplication: "
	len5: equ $-msg5

section .bss
        
        no resb 4
        no1 resb 4
        no2 resb 4
        result resb 4
        result1 resb 4
        choice resb 2
        arr resb 16
