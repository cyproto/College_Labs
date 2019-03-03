;Write 80387ALP to obtain:
;i) Mean ii) Variance iii) Standard Deviation
;For a given set of data elements defined in data segment. Also display result.

section .data
	array dd 15.00,5.00,5.00,5.00,5.00
	count dw 5
	hdec dq 100
	msg1 db 10,10,"****MENU****",10
	len1 equ $-msg1
	msg2 db "1.Calculate Mean",10
	len2 equ $-msg2
	msg3 db "2.Calculate Variance",10
	len3 equ $-msg3
	msg4 db "3.Calculate Standard Variance",10
	len4 equ $-msg4
	msg5 db "4.Exit",10
	len5 equ $-msg5
	msg6 db 10,"Enter choice:"
	len6 equ $-msg6
	msg7 db 10,"Mean:"
	len7 equ $-msg7
	msg8 db 10,"Variance:"
	len8 equ $-msg8
	msg9 db 10,"Standard Deviation:"
	len9 equ $-msg9
	point db "."
		
section .bss
	choice resb 2
	mean1 resd 1
	variance1 resd 1
	sdeviation1 resd 1
	resbuff rest 1
	temp resb 2

%macro write 2			;macro for display
	mov rax,1 
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

%macro read 2			;macro for input
	mov rax,0
	mov rdi,0
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

%macro exit 0			;macro for exit
	mov rax,60
	xor rdi,rdi
	syscall
%endmacro

section .text
  global _start
  _start:
  
  main:
  	write msg1,len1
  	write msg2,len2
  	write msg3,len3
  	write msg4,len4
  	write msg5,len5
  	write msg6,len6
  	
  	read choice,2				;enter choice
	mov al,[choice]
	
	case1:					;cmp choice
	cmp al,'1'
	jne case2 
	write msg7,len7
	call mean
	jmp main
	
	case2:
	cmp al,'2'
	jne case3
	write msg8,len8
	call variance
	jmp main
	
	case3:
	cmp al,'3'
	jne case4
	write msg9,len9
	call sdeviation
	jmp main
	
	case4:
	cmp al,'4'				;exit if choice 3
	exit
	
mean:
	FINIT
	FLDZ
	mov rsi,array
	mov rcx,5
  next:
  	FADD dword[rsi]
  	add rsi,4
  	loop next
  	FIDIV word[count]
  	FST dword[mean1]
  	call disp_proc
  	ret
  	
variance:
	mov rsi,array
	mov rcx,5
FLDZ
  up1:
    FLDZ
    FLD dword[rsi]
    FSUB dword[mean1]
    FST ST1
    FMUL
    FADD
    add rsi,4
    loop up1
    FIDIV word[count]
    FST dword[variance1]
    call disp_proc
	ret

sdeviation:
	FLDZ
        FLD dword[variance1]
	FSQRT
       ; FST dword[sdeviation1]
	call disp_proc
	ret

disp_proc:
	FIMUL dword[hdec]
	FBSTP tword[resbuff]
	mov rsi,resbuff+9
	mov rcx,09
  next1:
  	
  	push rcx
  	push rsi
  	
  	mov bl,[rsi]
  	call disp
  	pop rsi
  	pop rcx
  	dec rsi
  	loop next1
	push rsi
  	write point,1
	pop rsi
  	mov bl,[rsi]
  	call disp
ret
  
disp:
    	mov rdi,temp			;mov dnum address into edi
    	mov rcx,02			;initialize ecx with 2
    	dispup1:
    	    rol bl,4			;rotate bl by 4 bits
            mov dl,bl			;move bl into dl
            and dl,0fh			;and of dl with 0fh
            add dl,30h			;add 30h into dl
            cmp dl,39h			;compare dl with 39h
            jbe dispskip1		;jump if below and equal to dispskip1
            add dl,07h			;add 7h into dl
            dispskip1:
            mov [rdi],dl		;mov dl into dnum
            inc rdi			;increament edi by a byte
            loop dispup1		;loop dispup1 while ecx not zero
            write temp,2			;Display dnum by calling macro
          ret					;return from procedure
