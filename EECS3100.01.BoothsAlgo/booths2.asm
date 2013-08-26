;; EECS 3100 - Microsystems Design
;; LAB 01 - Booth's Algo
;; 09/17/2012
;; Nick Caley
;; This program implements Booth's Algorithm in x86 Assembly

	name    booths
	.model 	small
	.stack  100h
	.data
    resultMsg db 0ah, 0dh, "Results: $"
    ininfo  db  0ah, 0dh, "Input Number: $"
    Input1	dw  0002h
    Input2  dw  0004h
	        db  '$'
    prompt  db  0ah, 0dh, "Enter a number: $"
    resmes  db	0ah, 0dh, "Double your number is: "
    result  db  ?, 0ah, 0dh, "$"
    NEWLINE	db	10, 13, '$'
    tmp 	dw	0000h
    lsbm	dw	0000h
    lsbc	dw	0000h
    resultn	dd	0000h
		
	.code 
	extrn PutDec:near
	extrn GetDec:near

start:	
 	mov	ax, @data
	mov	ds, ax
	
GETINPUT:
	; display prompt
	xor ax, ax
	mov dx, offset prompt
	mov	ah, 09h
	int	21h
	call GetDec
	mov Input1, ax
	
	xor ax, ax
	mov dx, offset prompt
	mov	ah, 09h
	int	21h
	call GetDec
	mov Input2, ax
	
SHOWINPUT:
	; display input info
	mov dx, offset ininfo
	mov ah, 09h
	int 21h
	mov ax, Input1
	call PutDec
	mov dx, offset NEWLINE
	mov ah, 09h
	int 21h
	mov ax, Input2
	call PutDec
	
STEP1:
	xor cx, cx
;    mov cx, 8h		; WORKS IF PRODUCT CAN BE STORED IN A WORD
	mov cx, 10h		; init counter to 16
	mov bx, Input2	; put multiplicand in bx
	mov ax, Input1  ; put multiplier in ax
	xor dx,dx		; clear dx
	clc				; clear cf
	
STEP6:
	pushf			; push flags onto stack
	mov lsbm, 0001h
	mov lsbc, 0001h
	and lsbm, ax	; get LSB of multiplier	
	;get LSB of CF
	mov Input1, ax	; store the multiplier
	xor ax, ax
	pop ax			; pop flags back into ax
	and lsbc, ax	; get the CF
	
	; compare LSBs
    xor ax, ax
	mov ax, lsbc
	cmp ax, lsbm
	je STEP10		; if equal, goto step10
	
	cmp al, 0000h	; if CF is 0, multiplr must be 1
	je CFISZERO
	; otherwise CF=1 LSBM=0
	add dx, bx 		; add mutliplicand to dx
	jmp STEP10
	
CFISZERO:
	sub dx, bx		; sub multiplicand from dx
	
STEP10:
	mov ax, Input1	; restore multiplier	
	clc
	; shift dx into ax by 1
	sar dx, 1		; shift dx right, keep sign
	jc INCAX
	jmp NOCHANGEAX
	
INCAX:
	shr ax, 1
	pushf
	or ax, 8000h		; make MSB of ax=1
	jmp ENDCHECK
	
NOCHANGEAX:
	shr ax, 1
	pushf
	jmp ENDCHECK
	
ENDCHECK:
	popf
	dec cx
	jcxz STEP13
	jmp STEP6
	
STEP13:
	mov Input1, ax
	mov Input2, dx
	
DISPLAYRESULT:
	mov dx, offset resultMsg
	mov ah, 09h
	int 21h
	mov dx, offset NEWLINE
	mov ah, 09h
	int 21h
	mov ax, Input2
	call PutDec
	mov ax, Input1
	call PutDec
	
EXITSTUFF:
	mov	ax, 4c00h
	int 21h
	end	start
