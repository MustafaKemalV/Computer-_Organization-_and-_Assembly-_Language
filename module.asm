.586
.model flat, C 

.code

; Matches the following C/C++ declaration:
; extern "C" void solution_for_grade_7(const int * arr, size_t arr_rows, size_t arr_cols, int * result);

solution_for_grade_7 PROC PUBLIC \ 
    USES EBX ECX \
    arr: PTR DWORD, arr_rows: DWORD, arr_cols: DWORD, result: PTR DWORD

	cmp[arr], 0;
	je Exit;
	cmp[arr_rows], 0;
	je Exit;
	cmp[arr_cols], 0;
	je Exit;
	cmp[result], 0;
	je Exit;

	
	xor esi, esi
    xor edi, edi
    mov ecx, [arr_rows]
    row_loop:
	push ecx
            mov ebx, [arr]
            xor eax, eax
            mov ecx, [arr_cols]
            col_loop :
            test dword ptr[ebx + esi * 4], 1
            jnz skip
            inc eax
            skip :
            inc esi
            loop col_loop
            mov ebx, [result]
            mov[ebx + edi * 4], eax
            inc edi
            pop ecx
            loop row_loop

Exit:
    

    ret

solution_for_grade_7 ENDP

solution_for_grade_8 PROC PUBLIC \ 
    USES EBX ECX \
    arr: PTR DWORD, arr_rows: DWORD, arr_cols: DWORD, result: PTR DWORD

        xor esi, esi
        xor edi, edi
        mov ecx, [arr_cols]
        col_loop:
        push ecx
            mov ebx, [arr]
            xor eax, eax
            mov ecx, [arr_rows]
            row_loop :
            test dword ptr[ebx + esi * 4], 1
            jnz skip
            inc eax
            skip :
        add esi, [arr_cols]
            loop row_loop
            mov ebx, [result]
            mov[ebx + edi * 4], eax
            inc edi
            pop ecx
            loop col_loop

        ret

solution_for_grade_8 ENDP

END
