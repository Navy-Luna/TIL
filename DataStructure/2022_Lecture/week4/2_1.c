/* 2020110249 ���ֿ�
   ������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_TERMS 101
#define MAX_COLS 10

#include <stdio.h>
#include <stdlib.h>

// �������� 0�ƴ� ��
typedef struct
{
	int row;
	int col;
	int value;
}term;

// ������
term a[MAX_TERMS]; // a[0] : �� ũ��, �� ũ��, 0�ƴ� ���� ����
term b[MAX_TERMS]; // a�� ��ġ��� b

void fastTranspose(term a[], term b[])
{
	// the transpose of a is placed in b
	int rowTerms[MAX_COLS], startingPos[MAX_COLS];
	int i, j, numCols = a[0].col, numTerms = a[0].value;
	b[0].row = numCols; 
	b[0].col = a[0].row;
	b[0].value = numTerms;

	if (numTerms > 0)
	{ // nonzero matrix
		for (i = 0; i < numCols; i++)
			rowTerms[i] = 0;
		for (i = 0; i <= numTerms; i++)
			rowTerms[a[i].col]++;
		startingPos[0] = 1;

		for (i = 1; i < numCols; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];


		for (i = 1; i <= numTerms; i++)
		{
			j = startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}

		printf("\n");
		
	}
}

void printMatrix(term matrix[])
{
	int times = 1;
	for (int i = 0; i < matrix[0].row; i++)
	{
		for (int j = 0; j < matrix[0].col; j++)
		{
			if (matrix[times].row == i && matrix[times].col == j)
			{
				printf("%d ", matrix[times].value);
				times++;
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
}

int main(void)
{
	FILE* fIn = fopen("a.txt", "r");
	FILE* fOut = fopen("b.txt", "w");

	fscanf(fIn, "%d %d %d", &a[0].row, &a[0].col, &a[0].value);
	for (int i = 1; i <= 8; i++)
		fscanf(fIn, "%d %d %d", &a[i].row, &a[i].col, &a[i].value);


	printf("A\n");
	printMatrix(a);

	fastTranspose(a, b);
	
	printf("\nB\n");
	printMatrix(b);

	// b.txt ����ϱ�
	for (int i = 0; i <= b[0].value; i++)
	{
		fprintf(fOut, "%d %d %d\n", b[i].row, b[i].col, b[i].value);
	}

	fclose(fIn);
	fclose(fOut);


	return 0;
}