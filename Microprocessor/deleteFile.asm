PRINT MACRO MSG
        MOV AH,09H
        LEA DX,MSG
        INT 21H
ENDM
 
DATA SEGMENT
 
        SPACE DB "    $"
        NEWL DB 10,13, "$"
 
        FNAME DB 100 DUP(?)
        FP  DW ?
        BUFFER DB 1024 DUP('$')
        CNT DW ?
 
        SUCCESS DB 10,13, "FILE OPERATION SUCCESSFUL$"
        FAIL DB 10,13, "FILE OPERATION FAILED$"
        CONTENTS DB 10,13, "CONTENTS OF THE FILE ARE$"
 
DATA ENDS
 
ASSUME CS:CODE ,DS:DATA
 
CODE SEGMENT
 
START:
 
        MOV AX,DATA
        MOV DS,AX
 
        MOV AH,62H                      ;LOAD BASE ADDRESS OF PSP
        INT 21H        
                       
        MOV ES,BX                       ;BX HAS BASE ADDRESS NOW LOADED IN ES
        MOV SI,80H                      ;OFFSET OF FILE NAME
        MOV CH,ES:[SI]                  ;LENGTH OF FILE NAME
        DEC CH
        MOV SI,82H                      ;OFFSET OF FILE CONTENTS
        LEA DI,FNAME
 
L1:                                     ;LOOP TO MOVE FILE NAME IN FNAME
        MOV BL,ES:[SI]
        MOV [DI],BL
        INC SI
        INC DI
        DEC CH
        JNZ L1
 
        MOV AH,09H                      ;DISPLAY FILE NAME
        LEA DX,FNAME
        INT 21H
 
        MOV AH,41H                      ;INTERRUPT FOR DELETING THE FILR
        MOV DX,SEG FNAME                ;DS:DX MUST POINT TO FILE NAME
        MOV DS,DX
        MOV DX, OFFSET FNAME
        INT 21H
 
        JNC A1
        PRINT FAIL
        JMP END1
 
 
A1:
        PRINT SUCCESS
 
 
END1:
        MOV AH,4CH
        INT 21H
 
CODE ENDS
 
END START
