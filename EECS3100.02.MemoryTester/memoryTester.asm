;; EECS 3100 - Microsystems Design
;; LAB 02 - Memory Test
;; 10/08/2012
;; 
;; Authors:
;; 
;; 

	Prog_Code SEGMENT 'ROM'
	; TODO - explain what ASSUME does
	ASSUME  cs:Prog_Code
	
	Start: 
	    ;mov ax, Prog_Data
	    ;mov ds, ax
		xor	bx, bx
		xor cx, cx
		xor ax, ax
		mov es, ax
	    jmp Next_Segment
	    ;; Test memory location
	    ; We use 4 bit patterns to test every bit in the byte - "walking bit pattern"
	    ; This allows us to test every bit in case it gets stuck high or low.
	    ; This also takes measures to prevent against crosstalk, or one bit 
	    ; affecting the value of nearby bits.
	TestIt:
	    ; store memory contents in cl (it's safe in there)
	    mov al, es:[bx]
	    mov cl, al
	    
	    ; Test pattern 1 - 0000 0101
	    ; Move pattern into register
	    mov dl, 05h
	    ; write pattern to memory
	    mov es:[bx], dl
	    ; read back from memory
	    mov al, es:[bx]
	    ; compare
	    sub al, dl
	    ; if they're not the same, it's bad
	    jnz Bad
	
	    ; Test pattern 2 - 0101 0000
	    mov dl, 50h
	    mov es:[bx], dl
	    mov al, es:[bx]
	    sub al, dl
	    jnz Bad
	    
	    ; Test pattern 3 - 0000 1010
	    mov dl, 0Ah
	    mov es:[bx], dl
	    mov al, es:[bx]
	    sub al, dl
	    jnz Bad
	    
	    ; Test pattern 4 - 1010 0000
	    mov dl, 160
	    mov es:[bx], dl
	    mov al, es:[bx]
	    sub al, dl
	    jnz Bad
		
	    
	Good:
	    ; clear out ax, just for fun
	    sub ax, ax
	    ; retrieve saved contents
	    mov al, cl
	    ; restore saved contents to memory
	    mov es:[bx], al
	    ; increment the offset
	    inc bx
        jz Next_Segment
	    ; continue testing
	    jmp TestIt
	    
	Next_Segment:
	    ; move to the next segment
	    xor dx, dx
		xor ax, ax
	    mov ax, es ; move es into ax
	    add ax, 1000h ; move to the next segment in ax
		jc	Done
		mov dx, ax ; move the new segment into dx
	    ; we need to make sure we're not overwriting CS,
	    ; because then it'd get funky
	    mov ax, cs ; move the cs into ax
	    cmp ax, dx ; if the new segment is equal to the cs...
	    je Next_Segment ; try the next segment
		; if we reset, then we tested all memory - we're done
        mov ax, dx ; move the new segment into ax
		mov es, ax ; actually move es to the next segment
	    ; otherwise continue testing
	    jmp TestIt
	Bad:
	    nop
	    jmp Bad
	    ; TODO - keep track of bad memory locations?
    Done:
        ; ch will be our flag if we're just testing the CS or not
        jcxz TestCS
        jmp actuallyDone
    TestCS:
        ; start back at segment 0
        xor bx, bx
        xor dx, dx
		add bx, 1000h
        mov ax, cs
		mov dx, ax ; dx holds cs
        
        cmp ax, bx  ; is this valid?
        jne copySeg ; if the segments are different, then we found where we want to copy the CS to 
        inc bx ; otherwise move on to the next segment
		mov ax, dx
        mov es, ax  
        xor bx, bx ; we need to clear out bx since we inc'd it
    copySeg:
        ; move the contents of cs to es
		xor bx, bx
		mov ax, dx
		mov es, ax
	copyByte:
        mov ax, cs:[bx]
        mov es:[bx], ax ; is this valid?
        inc bx
        jc  setNewCs
		jmp copyByte
    setNewCs:
		xor bx, bx
        ; es is the new cs, so push it onto the stack
        push es
        ; now we can't do a pop cs because the assembler yells at us
        ; so we should just be able to do a ret to return to es (need to test this)
        ret
        ; set a flag saying we hit this point already
        mov ch, 1
        jmp TestIt
    actuallyDone:
        ; what do?
        ; TODO - play sound to indicate successful test - we don't know if we have speaker or not
        jmp actuallyDone
	Prog_Code ENDS
	
	END Start
