// 2022.04.22 : Sparse Matrix
// Sparse Matrix의 전치행렬을 fastTranspose 알고리즘을 사용하여 구현한다.

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 101
#define MAX_COL 10

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int row;
	int col;
	int value;
}term;

term A[MAX_LEN]; // 희소행렬
term B[MAX_LEN]; // 전치행렬

void fastTranspose();

int main()
{
	int i = 1;
	FILE* fp = fopen("a2.txt", "r");
	FILE* fout = fopen("b2.txt", "w");
	fscanf(fp, "%d %d %d", &A[0].row, &A[0].col, &A[0].value);

	// 파일로부터 값을 읽어온다.
	while (!feof(fp))
	{
		fscanf(fp, "%d %d %d", &A[i].row, &A[i].col, &A[i].value);
		i++;
	}

	// A를 출력
	printf("A\n");
	int k = 1;
	for (int i = 0; i < A[0].row; i++)
	{
		for (int j = 0; j < A[0].col; j++)
		{
			if (A[k].row == i && A[k].col == j)
			{
				printf("%d ", A[k].value);
				k++;
			}
			else
			{
				printf("%d ", 0);
			}

		}
		printf("\n");
	}

	// 전치를 실행
	fastTranspose();

	// B를 출력
	printf("B\n");
	k = 1;
	for (int i = 0; i < B[0].row; i++)
	{
		for (int j = 0; j < B[0].col; j++)
		{
			if (B[k].row == i && B[k].col == j)
			{
				printf("%d ", B[k].value);
				k++;
			}
			else
			{
				printf("%d ", 0);
			}

		}
		printf("\n");
	}
}

void fastTranspose()
{
	/* the transpose of A is placed in B */
	int j;
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int numCols = A[0].col, numTerms = A[0].value;

	B[0].col = A[0].row;
	B[0].row = numCols;
	B[0].value = numTerms;

	if (numTerms > 0)
	{
		/* calculation of rowTerms : O(numCols+numTerms) = O(elements+columns) */
		for (int i = 0; i < numCols; i++)
			rowTerms[i] = 0;
		for (int i = 1; i <= numTerms; i++)
			rowTerms[A[i].col]++;
		/* calculation of startingPos */
		startingPos[0] = 1;
		for (int i = 1; i < numCols; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
		/* b(j,i) <- a(i,j) */
		for (int i = 1; i <= numTerms; i++)
		{
			j = startingPos[A[i].col]++;
			B[j].row = A[i].col;
			B[j].col = A[i].row;
			B[j].value = A[i].value;
		}

	}

}