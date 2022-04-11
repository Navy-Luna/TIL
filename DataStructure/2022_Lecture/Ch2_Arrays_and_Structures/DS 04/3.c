/*
   2022.04.11
   정적할당 배열, 동적할당 배열, 구조체 학습을 복습하기 위한 코드
   (3) 동적으로 2차원 배열을 생성하는 함수와 동적 배열을 사용하여 더하기를 하는 함수를 작성하세요.
 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int** make2dArray(int rows, int cols);
void inputMatrix(int** ary, int rows, int cols);
void printMatrix(int** ary, int rows, int cols);
void addMatirx(int** a, int** b, int** c, int rows, int cols);
void freeAry2D(int** ary, int row);

int main(void)
{
	int row, col;
	int** A, **B, **C; //  int ** A, B, C 하면 B와 C는 int형으로 선언되버리니까 조심하자!
	printf("Enter row size and column size (ex) 2 3 >> ");
	scanf("%d %d", &row, &col);
	
	A = make2dArray(row, col);
	B = make2dArray(row, col);
	C = make2dArray(row, col);

	printf("input data for 2 * 3 matrix A >> ");
	inputMatrix(A, row, col);
	printf("input data for 2 * 3 matrix B >> ");
	inputMatrix(B, row, col);

	printf("Matrix A\n");
	printMatrix(A, row, col);
	printf("Matrix B\n");
	printMatrix(B, row, col);

	addMatirx(A, B, C, row, col);

	printf("Matrix C\n");
	printMatrix(C, row, col);

	freeAry2D(A, row);
	freeAry2D(B, row);
	freeAry2D(C, row);

	return 0;
}

void freeAry2D(int** ary, int row) // 2차원 동적할당 배열의 해제
{	/* 메모리를 할당할 때와는 반대로 해제를 진행해주면 된다. */
	for (int i = 0; i < row; i++)
		free(ary[i]);	// 행에 해당하는 각각의 1차원 배열 free

	free(ary);	// 행들을 가리켰던 포인터들의 모임을 free

	return;
}

void addMatirx(int** a, int** b, int** c, int rows, int cols) // 동적 할당 행렬 더하기
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			c[i][j] = a[i][j] + b[i][j];
}

void inputMatrix(int** ary, int rows, int cols) // 사용자 데이터 입력
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			scanf("%d", (*(ary + i) + j));
}

void printMatrix(int** ary, int rows, int cols) // 행렬 출력
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%d ", *(*(ary + i) + j));
		printf("\n");
	}
}

int** make2dArray(int rows, int cols) // 2차원 메모리 할당하기
{
	int** temp;
	temp = (int**)malloc(rows * sizeof(int*));

	for (int i = 0; i < rows; i++)
		temp[i] = (int*)malloc(cols * sizeof(int));

	return temp;
}