%include "macro.asm"

global buf,abuf
extern proc

global _start
_start:

section .text

        disp msg3,len3
        accept filename,50
        dec rax
        mov byte[filename+rax],0		; check for space/null character
        fopen filename
        cmp rax,-1
        je eror
        mov [filehandle],rax
        fread [filehandle],buf,buflen
        dec rax
        mov [abuf],rax
		disp buf,[abuf]
	
		call proc

        exit:
                disp msg2,len2
		mov rax,60
                mov rdi,0
                syscall
        eror:
				disp msg1,len1
				call exit

section .data

    msg1 db "Error in file open operation!",10
	len1: equ $-msg1
	
	msg2 db " ",10
	len2: equ $-msg2
	
	msg3 db "Enter File name: "
	len3: equ $-msg3

section .bss

    choice resb 2
	filename resb 1024
	filename1 resb 1024
	filehandle resb 1024
	filehandle1 resb 1024
	buf resb 1024
	buflen resb 1024
	abuf resb 1024
