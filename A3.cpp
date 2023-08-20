
#ifdef __cplusplus
#include <cstdio>
#include <cassert>
#else
#include <stdio.h>
#include <assert.h>
#endif


// Mustafa Kemal VURAL - ID: 201ADB076 - Variant Task A-3 / Task B-2 / Task C-1

int solution_for_grade_6(const int arr[], unsigned arr_size)
{
    int result{ 0 };
    __asm
    {
        
        mov	ESI, [arr]; an example of how to obtain the addres ofand array parameter
        mov	ECX, [arr_size]
        mov EAX, 0
        
        Cycle:
        cmp dword ptr[ESI], 0; an example of addressing individual dword element
            JGE Karst
            inc EAX
            Karst :
        add	ESI, 4; an example of adjusting the array offset(4 bytes)
            loop	Cycle
            Exit:
        mov[result], EAX; save the result assuming it is in the register EAX
    }
    return result;
}
// :::
int solution_for_grade_7(const int arr[],  int arr_size)
{
    int result{ 0 };
    __asm
    {
        xor EAX, EAX;
        mov ESI, [arr];
        mov ECX, [arr_size];
        cmp[arr_size], 0;
        jl WrongInput;
    Cycle:
        cmp dword ptr[ESI], 0;
        jle Next;
        add EAX, dword ptr[ESI];
    Next:
        add ESI, 4;
        loop Cycle;
        jmp Exit;
    WrongInput:
        mov EAX, -1;
        jmp Exit;
    Exit:
        mov[result], EAX;
    }
    int test_value = 0;
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] %2!= 0) {
            test_value += arr[i];
        }
    }
    assert(result == test_value);
    return result;
}

int solution_for_grade_9(const int arr[], unsigned arr_size)
{
    int result{ 0 };
    __asm
    {
        mov	ESI, [arr]
        mov	ECX, [arr_size]
        mov	EAX, 0
        mov EBX, 50000
        Cycle:
        cmp dword ptr[ESI], 0;
        JGE Karst
            mov eax, dword ptr[ESI]
            mov edx, 0
            idiv 2
            cmp edx, 0
            JG Karst
            JB Karst
            mov edx, 0

            cmp eax, ebx
            JG Karst
            mov ebx, eax

        Karst:
        add	ESI, 4
            loop Cycle


            mov eax, ebx
            mov[result], EAX; save the result assuming it is in the register EAX
    }
    return result;
}


int main()
{
    int test_result;

    int test_arr1[] = { 0, 1000, 2237, -3000, 3433, 5638, 64547, 73, -70000, 800000 };

    test_result = solution_for_grade_6(test_arr1, sizeof(test_arr1) / sizeof(test_arr1[0]));
    printf("Grade 6 result1 = %d\n", test_result);

    test_result = solution_for_grade_7(test_arr1, sizeof(test_arr1) / sizeof(test_arr1[0]));
    printf("Grade 7 result1 = %d\n", test_result);

    test_result = solution_for_grade_9(test_arr1, sizeof(test_arr1) / sizeof(test_arr1[0]));
    printf("Grade 9 result1 = %d\n", test_result);

    int test_arr2[] = { 0, -1, 2, -3, 4, -5, 6, -7, 8, -9 };

    test_result = solution_for_grade_6(test_arr2, sizeof(test_arr2) / sizeof(test_arr2[0]));
    printf("Grade 6 result2 = %d\n", test_result);

    test_result = solution_for_grade_7(test_arr2, sizeof(test_arr2) / sizeof(test_arr2[0]));
    printf("Grade 7 result2 = %d\n", test_result);

    test_result = solution_for_grade_9(test_arr2, sizeof(test_arr2) / sizeof(test_arr2[0]));
    printf("Grade 9 result1 = %d\n", test_result);
    // :::
    getchar(); // Wait for the Enter key
    return 0;
}
