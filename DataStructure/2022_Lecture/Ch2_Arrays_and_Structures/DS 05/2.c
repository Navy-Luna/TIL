// 2022.04.22 : Sparse Matrix
// Sparse Matrix의 전치행렬을 column 전체 탐색 방식을 통해 구현한다.
#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 101

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

void transpose();

int main(void)
{
	int i = 1;
	FILE* fp = fopen("a.txt", "r");
	FILE* fout = fopen("b.txt", "w");
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

	// 전치를 진행
	transpose();

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

void transpose()
{
	B[0].row = A[0].col;
	B[0].col = A[0].row;
	B[0].value = A[0].value;

	if (A[0].value > 0) // nonzero matrix
	{	
		int currentb = 1; // 현재 b에 저장할 위치
		for (int i = 0; i < A[0].col; i++)
		{
			for (int j = 1; j <= A[0].value; j++)
			{
				if (A[j].col == i)
				{
					B[currentb].row = A[j].col;
					B[currentb].col = A[j].row;
					B[currentb].value = A[j].value;
					currentb++;
				}
			}
		}
	}
}

