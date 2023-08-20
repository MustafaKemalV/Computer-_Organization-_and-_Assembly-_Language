#include <iostream>
#include <cassert>

// Mustafa Kemal VURAL -  ID:201AD076 - Variant: A-3 / B-2 / C-1

void solution_for_grade_7(const int* arr, size_t arr_rows, size_t arr_cols, int* result)
{
    __asm
    {
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
    }
}

void solution_for_grade_9(const int* arr, size_t arr_rows, size_t arr_cols, int* result)
{
    __asm
    {
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
        inc esi
            loop row_loop
            mov ebx, [result]
            mov[ebx + edi * 4], eax
            inc edi
            pop ecx
            loop col_loop
    }
}


const size_t ROWS = 2;
const size_t COLS = 3;

int main()
{
    
    int data1[ROWS][COLS] = { { 0, -100, 200 }, { 300, 400, -500 } };
    int result1[COLS]; 

    
    solution_for_grade_9((const int*)data1, ROWS, COLS, result1);

    
    for (auto i{ 0U }; i < COLS; i++)
        printf("%d ", result1[i]);
    printf("\n");

    int data2[ROWS][COLS] = { { 0, -100, 200 }, { 300, 400, -501 } };
    int result2[ROWS];  

    solution_for_grade_7((const int*)data2, ROWS, COLS, result2);

    for (auto i{ 0U }; i < ROWS; i++)
        printf("%d ", result2[i]);
    printf("\n");

   

    return 0;
}
