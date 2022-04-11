/*
   2022.04.11
   정적할당 배열, 동적할당 배열, 구조체 학습을 복습하기 위한 코드
   (2) 정적으로 할당된 2차원 배열 3개를 전달하여 더하기를 진행하는 함수이다. 2차원 배열을 사용한 행렬 더하기 프로그램을 작성하라.
 */
#define _CRT_SECURE_NO_WARNINGS
#define ROWS 2
#define COLS 3

#include <stdio.h>
#include <stdlib.h>

void print2DArray(int ary[][COLS], int rows, int cols);
void input2DArray(int ary[][COLS], int rows, int cols);
void add(int a[][COLS], int b[][COLS], int c[][COLS], int rows, int cols);

int main()
{
	int A[2][3], B[2][3], C[2][3];

	printf("input data for 2 * 3 matrix A >> ");
	input2DArray(A, 2, 3);

	printf("input data for 2 * 3 matrix B >> ");
	input2DArray(B, 2, 3);

	printf("\n");

	printf("Matrix A\n");
	print2DArray(A, 2, 3);
	printf("Matrix B\n");
	print2DArray(B, 2, 3);
	
	add(A, B, C, 2, 3);
	
	printf("Matrix C\n");
	print2DArray(C, 2, 3);

	return 0;
}

void print2DArray(int ary[][COLS], int rows, int cols) // 행렬 출력
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", ary[i][j]);
		printf("\n");
	}
}

void input2DArray(int ary[][COLS], int rows, int cols) // 행렬 입력
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &ary[i][j]);
}

void add(int a[][COLS], int b[][COLS], int c[][COLS], int rows, int cols) // 행렬 더하기
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			c[i][j] = a[i][j] + b[i][j];
}
