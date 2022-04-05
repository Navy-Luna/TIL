/*
	Chap1_Basic_Concept : C Programming Basic
	1,2,3차원 배열을 선언하고 배열이름 ary 및 배열 포인터 p를 이용하여 배열 요소를 출력하는 프로그램을 만들어라
*/

#include <stdio.h>

int main()
{
	int ary1[3] = { 1,2,3 };
	int ary2[2][3] = { {4,2,3},{5,2,3} };
	int ary3[2][2][3] = { { {1,2,3},{4,5,6}},{{7,8,9},{10,11,12}} };
	int* p1 = ary1;
	int(*p2)[3] = ary2;
	int(*p3)[2][3] = ary3;


	printf("ary1을 이용한 출력:\n");
	for (int i = 0; i < 3; i++)
		printf("%d ", ary1[i]);
	printf("\np1을 이용한 출력:\n");
	for (int i = 0; i < 3; i++)
		printf("%d ", *(p1+i));
	printf("\n");

	printf("ary2을 이용한 출력:\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", ary2[i][j]);
		printf("\n");
	}
	printf("p2을 이용한 출력:\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", *(*(p2 + i) + j));
		printf("\n");
	}
	printf("ary3를 이용한 출력\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 3; k++)
				printf("%d ", ary3[i][j][k]);
				printf("\n");
		}
		printf("\n");
	}
	printf("p3를 이용한 출력\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 3; k++)
				printf("%d ", *(*(*(ary3 + i) + j) + k));
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}