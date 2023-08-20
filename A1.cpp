//#include "stdafx.h" // might be required for the older versions of Visual Studio
#ifdef __cplusplus
#include <cstdio>
#include <cassert>
#else
#include <stdio.h>
#include <assert.h>
#endif

// C++ built-in data types mapping to assembler data types:
//   char  data type is signed  8-bit integer (DB in assembler)
//   short data type is signed 16-bit integer (DW in assembler)
//   int   data type is signed 32-bit integer (DD in assembler)

// Mustafa Kemal VURAL - 201ADB076

short solution_for_grade_5(short x, short y, short z)
{
    // Selected variant and expression: A3 --> X-Y-Z


    short result;
    // Visual C++ inline assembler syntax:
    __asm
    {
        mov AX, x
        sub AX, y
        sub AX, z

        mov[result], AX; save the result assuming it is in the CPU register AX
    }
    assert((x - y - z) == result);
    return result;
}

short solution_for_grade_6(short x, short y, short z)
{
    // Selected variant and expression: B2 --> -3X+4YZ 

    short result;
    __asm
    {
        imul BX, z, 4
        mov AX, BX
        imul BX, y
        mov AX, BX
        imul BX, x, -3
        add AX, BX

        mov[result], AX; save the result
    }
    assert((-3 * x + 4 * y * z) == result);
    return result;
}

short solution_for_grade_7(short x, short y, short z)
{
    // B - A  --> (-3X+4YZ) - (X-Y-Z)

    short result;
    __asm
    {

        // Check  A 
        mov AX, x
        sub AX, y
        sub AX, z

        // Check B
        imul BX, z, 4
        mov CX, BX
        imul BX, y
        mov CX, BX
        imul BX, x, -3
        add CX, BX

        // Compute B - A
        sub CX, AX

        mov[result], CX; save the result
    }

    assert(((-3 * x + 4 * y * z) - (x - y - z)) == result);
    return result;
}

short solution_for_grade_8(short x, short y, short z)
{
    // B * A  --> (-3X+4YZ) * (X-Y-Z)

    short result;
    __asm
    {
        // Check A
        mov AX, x
        sub AX, y
        sub AX, z

        // B
        imul BX, z, 4
        mov CX, BX
        imul BX, y
        mov CX, BX
        imul BX, x, -3
        add CX, BX

        //B * A
        imul CX, AX

        mov[result], CX; save the result
    }

    //assert(((-3 * X + 4 * Y * Z) * (x - y - z)) == result);
    return result;
}

short solution_for_grade_9(short x, short y, short z)
{
    //Compute  B / A  --> (-3X+4YZ) / (X-Y-Z)

    short result;
    __asm
    {
        // A
        mov AX, x
        sub AX, y
        sub AX, z
        push AX

        // B
        imul BX, z, 4
        mov CX, BX
        imul BX, y
        mov CX, BX
        imul BX, x, -3
        add CX, BX
        mov AX, CX
        pop BX

        //B / A
        cwd
        idiv BX

        mov[result], AX; save the result
    }

    //assert(((-3 * X + 4 * Y * Z) / (x - y - z)) == result);
    return result;
}




int main()
{
    short first = 42; // Note the short data type range is -32768..32767
    short second = 15;
    short third = 26;

    short result = solution_for_grade_5(first, second, third);
    printf("solution_for_grade_5(%d, %d, %d) = %d\n", first, second, third, result);
    result = solution_for_grade_6(first, second, third);
    printf("solution_for_grade_6(%d, %d, %d) = %d\n", first, second, third, result);
    result = solution_for_grade_7(first, second, third);
    printf("solution_for_grade_7(%d, %d, %d) = %d\n", first, second, third, result);
    result = solution_for_grade_8(first, second, third);
    printf("solution_for_grade_8(%d, %d, %d) = %d\n", first, second, third, result);
    result = solution_for_grade_9(first, second, third);
    printf("solution_for_grade_9(%d, %d, %d) = %d\n", first, second, third, result);

    return 0;
}