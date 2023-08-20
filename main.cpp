#include <cstdio>
#include <cassert>

extern "C" void solution_for_grade_7(const int* arr, size_t arr_rows, size_t arr_cols, int* result1);
extern "C" void solution_for_grade_8(const int* arr, size_t arr_rows, size_t arr_cols, int* result2);

const size_t ROWS = 2;
const size_t COLS = 3;


int main()
{
	int data1[ROWS][COLS] = { { 0, -100, 200 }, { 300, 400, -500 } };
	int result1[ROWS];
	solution_for_grade_7((const int*)data1, ROWS, COLS, result1);
	for (size_t i = 0U; i < ROWS; i++)
		printf("%d ", result1[i]);
	printf("\n");



	int data2[ROWS][COLS] = { { 0, -100, 200 }, { 300, 400, -500 } };
	int result2[COLS];

	solution_for_grade_8((const int*)data2, ROWS, COLS, result2);

	for (size_t i = 0U; i < COLS; i++)
		printf("%d ", result2[i]);
	printf("\n");



	getchar();
	return 0;
}

