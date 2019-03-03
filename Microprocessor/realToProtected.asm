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
	
	
	smsw eax
	mov [msw],eax
	bt eax,1
	jc protected_mode
	disp msg8,len8
	
	protected_mode:
	        disp msg7,len7
	
	disp msg1,len1
	sldt[ldt]
	mov ax,[ldt]
	call display
	
	disp msg3,len3
	str[tr]
	mov ax,[tr]
	call display
	
	disp msg4,len4
	sgdt[gdt]
	mov ax,[gdt+4]
	call display
	mov ax,[gdt+2]
	call display
	mov ax,[gdt]
	call display
	
	disp msg5,len5
	sidt[idt]
	mov ax,[idt+4]
	call display
	mov ax,[idt+2]
	call display
	mov ax,[idt]
	call display
	
	disp msg6,len6
	mov ax,[msw+2]
	call display
	mov ax,[msw]
	call display
	
       
        ;To call end
        disp msg2,len2
        
        mov rax,60
        mov rdi,0
        syscall
        
        
        ;Display procedure
    	
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
	        ret


section .data
        
                
        msg1 db "LDTR (16bit): "
        len1: equ $-msg1
        
        msg2 db " ",10
	len2: equ $-msg2 
        
        msg3 db 10,"TR (16bit): "
        len3: equ $-msg3
        
        msg4 db 10,"GDTR (48bit): "
        len4: equ $-msg4
        
        msg5 db 10,"IDTR (48bit): "
        len5: equ $-msg5
        
        msg6 db 10,"MSW (32bit): "
        len6: equ $-msg6
        
        msg7 db "In Protected Mode!",10
        len7: equ $-msg7
        
        msg8 db "In Real Mode!",10
        len8: equ $-msg8
        
section .bss

       
       arr resb 16
       ldt resb 32
       tr resb 32
       gdt resb 32
       idt resb 32
       msw resb 32
