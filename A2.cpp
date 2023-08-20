#include <cstdio>
#include <cassert>
#include <iostream>

// NOTE:
//   char  data type is signed  8-bit integer (DB in assembler)
//   short data type is signed 16-bit integer (DW in assembler)
//   int   data type is signed 32-bit integer (DD in assembler)

// Mustafa Kemal VURAL - 201ADB076
// Variant  1 --> X/Y+(Z+1)^3

int solution_for_grade_4(int x, int y, int z)
{
    int result;
    
    __asm
    {
        mov eax, x
        sub eax, y
        sub eax, z

        mov[result], eax; save the result assuming it is in the processor register EAX

    }
    return result;
}

//

int solution_for_grade_5(int x, int y, int z)
{
    int result2;
    __asm
    {
        imul ebx, z, 4
        mov eax, ebx
        imul ebx, y
        mov eax, ebx
        imul ebx, x, -3
        add eax, ebx

        mov[result2], eax; save the result assuming it is in the processor register EAX
    }
    return result2;
}

//

int solution_for_grade_6(int x, int y, int z)
{
    int result3;
    __asm
    {
        
        mov eax, x;
        mov ebx, y;
        cdq;

        idiv ebx;
        mov ebx, z;
        add ebx, 1;
        mov ecx, ebx
        imul ebx, ebx
        imul ebx, ecx

        add eax, ebx;


        mov[result3], eax; save the result assuming it is in the processor register EAX

    }
    return result3;
}

int solution_for_grade_7(int x, int y, int z)
{
    int result3;
    __asm
    {
       
        mov eax, x
        sub eax, y
        sub eax, z

        cmp eax, 0;

        jg branch_c;

        mov edx, eax;

        mov eax, x;
        mov ebx, y;
        cdq;

        idiv ebx;
        mov ebx, z;
        add ebx, 1;
        mov ecx, ebx
        imul ebx, ebx
        imul ebx, ecx
        add eax, ebx;

        mov ebx, eax
        mov eax, edx

        imul eax, ebx

        jmp finish;

    branch_c:

        mov edx, eax

        imul ebx, z, 4
        mov eax, ebx
        imul ebx, y
        mov eax, ebx
        imul ebx, x, -3
        add eax, ebx

        mov ebx, eax
        mov eax, edx

        imul eax, ebx

        finish :


        mov[result3], eax; save the result assuming it is in the processor register EAX
    }
    return result3;
}

//

int solution_for_grade_8(int x, int y, int z)
{
    int result;
    __asm
    {
        mov ecx, x
        sub ecx, y
        sub ecx, z

        cmp ecx, 0
        je branch_c
        jbe branch_a

        imul ebx, z, 4
        mov eax, ebx
        imul ebx, y
        mov eax, ebx
        imul ebx, x, -3
        add eax, ebx
        cdq
        idiv ecx
        jmp finish

        branch_a :

        mov eax, x;
        mov ebx, y;
        cdq;

        idiv ebx;
        mov ebx, z;
        add ebx, 1;
        mov ecx, ebx
        imul ebx, ebx
        imul ebx, ecx
        add eax, ebx;

        cdq
        idiv ecx
        jmp finish

        branch_c :
        mov eax, -1

        finish :
        mov[result], eax; save the result assuming it is in the processor register EAX
    }
    return result;
}

//

int solution_for_grade_9(int x, int y, int z)
{
    int result;
    __asm
    {
        mov ecx, x
        sub ecx, y
        sub ecx, z

        cmp ecx, 0
        je branch_c
        jbe branch_a

        imul ebx, z, 4
        mov eax, ebx
        imul ebx, y
        mov eax, ebx
        imul ebx, x, -3
        add eax, ebx
        cdq
        idiv ecx
        jmp finish

        branch_a :

        mov eax, x;
        mov ebx, y;
        cdq;

        idiv ebx;
        mov ebx, z;
        add ebx, 1;
        mov edx, ebx
        imul ebx, ebx
        imul ebx, edx

        add eax, ebx;

        cdq
        idiv ecx
        jmp finish

        branch_c :
        mov eax, -1

        finish :
        mov[result], eax; save the result assuming it is in the processor register EAX
    }
    return result;
}





int main()
{
    // Note the 32-bit signed int value range is –2’147’483’648.. 2’147’483’647
    int first = 34;
    int second = 23;
    int third = 15;


    int result = solution_for_grade_4(first, second, third);
    int result2 = solution_for_grade_5(first, second, third);
    int result3 = solution_for_grade_6(first, second, third);
    int result4 = solution_for_grade_7(first, second, third);
    int result5 = solution_for_grade_8(first, second, third);
    int result6 = solution_for_grade_9(first, second, third);
    printf("solution_for_grade_4(%d, %d, %d) = %d\n", first, second, third, result);
    printf("solution_for_grade_5(%d, %d, %d) = %d\n", first, second, third, result2);
    printf("solution_for_grade_6(%d, %d, %d) = %d\n", first, second, third, result3);
    printf("solution_for_grade_7(%d, %d, %d) = %d\n", first, second, third, result4);
    printf("solution_for_grade_8(%d, %d, %d) = %d\n", first, second, third, result5);
    printf("solution_for_grade_9(%d, %d, %d) = %d\n", first, second, third, result6);

    
    getchar(); // Wait for the Enter key
    return 0;
}
