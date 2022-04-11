/*
   2022.04.11
   �����Ҵ� �迭, �����Ҵ� �迭, ����ü �н��� �����ϱ� ���� �ڵ�
   (3) �������� 2���� �迭�� �����ϴ� �Լ��� ���� �迭�� ����Ͽ� ���ϱ⸦ �ϴ� �Լ��� �ۼ��ϼ���.
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
	int** A, **B, **C; //  int ** A, B, C �ϸ� B�� C�� int������ ����ǹ����ϱ� ��������!
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

void freeAry2D(int** ary, int row) // 2���� �����Ҵ� �迭�� ����
{	/* �޸𸮸� �Ҵ��� ���ʹ� �ݴ�� ������ �������ָ� �ȴ�. */
	for (int i = 0; i < row; i++)
		free(ary[i]);	// �࿡ �ش��ϴ� ������ 1���� �迭 free

	free(ary);	// ����� �����״� �����͵��� ������ free

	return;
}

void addMatirx(int** a, int** b, int** c, int rows, int cols) // ���� �Ҵ� ��� ���ϱ�
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			c[i][j] = a[i][j] + b[i][j];
}

void inputMatrix(int** ary, int rows, int cols) // ����� ������ �Է�
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			scanf("%d", (*(ary + i) + j));
}

void printMatrix(int** ary, int rows, int cols) // ��� ���
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%d ", *(*(ary + i) + j));
		printf("\n");
	}
}

int** make2dArray(int rows, int cols) // 2���� �޸� �Ҵ��ϱ�
{
	int** temp;
	temp = (int**)malloc(rows * sizeof(int*));

	for (int i = 0; i < rows; i++)
		temp[i] = (int*)malloc(cols * sizeof(int));

	return temp;
}