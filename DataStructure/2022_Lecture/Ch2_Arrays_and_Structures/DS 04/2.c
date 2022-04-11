/*
   2022.04.11
   �����Ҵ� �迭, �����Ҵ� �迭, ����ü �н��� �����ϱ� ���� �ڵ�
   (2) �������� �Ҵ�� 2���� �迭 3���� �����Ͽ� ���ϱ⸦ �����ϴ� �Լ��̴�. 2���� �迭�� ����� ��� ���ϱ� ���α׷��� �ۼ��϶�.
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

void print2DArray(int ary[][COLS], int rows, int cols) // ��� ���
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", ary[i][j]);
		printf("\n");
	}
}

void input2DArray(int ary[][COLS], int rows, int cols) // ��� �Է�
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &ary[i][j]);
}

void add(int a[][COLS], int b[][COLS], int c[][COLS], int rows, int cols) // ��� ���ϱ�
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			c[i][j] = a[i][j] + b[i][j];
}
