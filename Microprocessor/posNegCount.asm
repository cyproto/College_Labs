global _start
_start:

section .text
mov rsi,arr

l:
	mov rax,[rsi]
	push rsi				   ;mov qword[temp],rsi
	call display
	pop rsi                    ;mov rsi,qword[temp]

	add rsi,8                  ;add 8 bytes to rsi    
	dec byte[cnt]
	jnz l

	mov rsi,arr                ;mov rax,[rsi]
l3:	

	bt qword[rsi],63           ;bt rax,63
	jc l2                      ;jump if carry=1
	inc byte[pcnt]             ;positive if carry=0
	jmp l4
l2: 
	inc byte[ncnt]             ;negative no.

l4: 
	add rsi,8                  ;increment index pointer by 8 bytes
	dec byte[cnt1]             ;decrement cnt1 till zero
	jnz l3

	mov rax,1                  ;display msg1
	mov rdi,0
	mov rsi,msg1
	mov rdx,len1
	syscall
	mov ah,00h
	mov al,byte[pcnt]
	call display

	mov rax,1                   ;display msg2
	mov rdi,0       
	mov rsi,msg2
	mov rdx,len2
	syscall
	mov ah,00h
	mov al,byte[ncnt]
	call display


	mov rax,60                  ;exit from program
	mov rdi,0
	syscall

display:
	mov rsi,arr1+15             ;pointer to array at 15 loc
	mov rcx,16                  ;count=16

	loop: 
		mov rdx,0				;division code
		mov rbx,10h             ;divide by 10 
		div rbx

		cmp dl,09h              ;compare remainder to 0-9
		jbe l1                  ;jump to l1 if below or equal
		add dl,07h              ;add 7 to remainder 

	l1:
		add dl,30h              ;add 30 to remainder(ASCII)
		mov [rsi],dl            ;mov ascii equivalent into arr

		dec rsi                 ;decrement pointer 
		dec rcx                 ;decrement count

		jnz loop                ;jump to loop if not zero

		mov rax,1               ;display code
		mov rdi,1
		mov rsi,arr1
		mov rdx,16
		syscall 

		mov rax,0                ;display code
		mov rdi,0
		mov rsi,msg
		mov rdx,len
		syscall
		ret

section .data

	arr dq 1234567812345678h, 1111111112345678h, 8888888888888888h, 9999999900000000h
	cnt db 4
	msg: db " "
	len: equ $-msg
	cnt1 db 2
	msg1: db "Positive Numbers are: "
	len1: equ $-msg1
	msg2: db "Negative Numbers are: "
	len2: equ $-msg2

section .bss

	arr1 resb 32 
	temp resq 64   
	pcnt resb 1
	ncnt resb 1
