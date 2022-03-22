/* 2020110249 윤주영
   본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_TERMS 101

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int row;
	int col;
	int value;
}term;

term a[MAX_TERMS], b[MAX_TERMS];

void transpose(term a[], term b[])
{// b is set to the transpose of a
	int n, i, j, currentb;
	n = a[0].value;		  // total number of elements
	b[0].row = a[0].col;  // rows in b = columns in a
	b[0].col = a[0].row;  // columns in b = rows in a
	b[0].value = n;

	if (n > 0)
	{ // non zero matrix
		currentb = 1;
		for (int i = 0; i < a[0].col; i++)
		{
			// transpose by the columns in a
			for (j = 1; j <= n; j++)
			{
				// find elements from the current column
				if (a[j].col == i)
				{ // element is in current column, add it to b
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].value = a[j].value;
					currentb++;
				}
			}
		}
	}


}


int main(void)
{
	FILE* fIn = fopen("a.txt", "r");
	FILE* fOut = fopen("b.txt", "w");

	fscanf(fIn, "%d %d %d", &a[0].row, &a[0].col, &a[0].value);
	for(int i=1; i<=8; i++)
		fscanf(fIn, "%d %d %d", &a[i].row, &a[i].col, &a[i].value);

	printf("A\n");


	int times = 1;
	for (int i = 0; i < a[0].row; i++)
	{
		for (int j = 0; j < a[0].col; j++)
		{
			if (a[times].row == i && a[times].col == j)
			{
				printf("%d ", a[times].value);
				times++;
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}

	transpose(a, b); // 전치

	printf("\nB\n");


	int timess = 1;
	for (int i = 0; i < b[0].row; i++)
	{
		for (int j = 0; j < b[0].col; j++)
		{
			if (b[timess].row == i && b[timess].col == j)
			{
				printf("%d ", b[timess].value);
				timess++;
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}

	// b.txt 출력하기
	for (int i = 0; i <= b[0].value; i++)
	{
		fprintf(fOut, "%d %d %d\n", b[i].row, b[i].col, b[i].value);
	}

	fclose(fIn);
	fclose(fOut);
}
