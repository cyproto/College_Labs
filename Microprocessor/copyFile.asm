.MODEL SMALL

  EXITDOS MACRO
     MOV AH,4CH
     INT 21H
  ENDM

  PRINT MACRO MSG
    MOV AH,09H
    LEA DX,MSG
    INT 21H
  ENDM

.DATA

  FNAME1 DB 40 DUP(0)
  FNAME2 DB 40 DUP(0)
                     
  HANDLE1 DW ?
  HANDLE2 DW ?
  BUFF DB 100 DUP(0)
  STDOUT EQU 1
  M1 DB 10,13,'FILE ERROR...$'
  M2 DB 10,13,'FILE COPIED SUCCESSFULLY.$'
               
.CODE

      MOV AX,@DATA									;initialise data segment
      MOV DS,AX


      MOV AH,62H
      INT 21H
      MOV ES,BX

      MOV SI,0081H									;loading psp starting address
      XOR DI,DI
      INC SI

  F_SCAN1: MOV BL,BYTE PTR ES:[SI]
           INC SI
           CMP BL,20H				; check for space
           JE NEXT_FILE
           CMP BL,0DH				; carriage return (enter)
           JE F_OPEN
           MOV FNAME1[DI],BL
           INC DI
           LOOP F_SCAN1

  NEXT_FILE:
            XOR DI,DI

      F_SCAN2:
               MOV BL,BYTE PTR ES:[SI]
               INC SI
               CMP BL,0DH
               JE F_OPEN
               MOV FNAME2[DI],BL
               INC DI
               LOOP F_SCAN2

     F_OPEN:										;open file
               MOV AH,3DH
               MOV AL,02H
               MOV DX,OFFSET FNAME1
               INT 21H
               JC ERROR
               MOV HANDLE1,AX

     CREATE:										;create new file for copy
               MOV AH,3CH
               MOV CX,00H
               MOV DX,OFFSET FNAME2
               INT 21H
               JC  ERROR
               MOV HANDLE2,AX

      READ:											;read contents of first file
               MOV AH,3FH
               MOV BX,HANDLE1
               MOV CX,50
               LEA DX,BUFF
               INT 21H
               JC FILECLOSE
               MOV SI,AX

      WRITE:										;write into new file
               MOV AH,40H
               MOV BX,HANDLE2
               MOV CX,SI
               LEA DX,BUFF
               INT 21H
               CMP CX,50
               JE READ

      FILECLOSE:									;close both the files
                 MOV AH,3EH
                 MOV BX,HANDLE1
                 INT 21H
                 MOV BX,HANDLE2
                 INT 21H
                 PRINT M2
                 exitdos
                

        ERROR:
                PRINT M1
                EXITDOS


               

END



