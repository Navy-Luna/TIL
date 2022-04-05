/*
	Chap1_Basic_Concept : C Programming Basic
	3차원 배열을 인수로 가지는 세가지 타입의 함수를 사용해보자
*/

#include <stdio.h>



int main()
{
	int ary3D[][2][3] = { { {1,2,3},{4, 5, 6} },{{7,8,9},{10,11,12}} };

	// 각각의 함수들은 모두 ary를 int[3]* 의 함수인자를 사용한다.
	printf("f1: %d\n", sumAry3D_f1(ary3D,2, 2, 3));
	printf("f2: %d\n", sumAry3D_f2(ary3D,2, 2, 3));
	printf("f3: %d\n", sumAry3D_f3(ary3D,2, 2, 3));
}

int sumAry3D_f1(int ary[][2][3],int sec, int row, int col) // 배열의 파라미터, 칸?, 행, 렬
{
	int sum = 0;

	for (int i = 0; i < sec; i++)
		for (int j = 0; j < row; j++)
			for (int k = 0; k < col; k++)
				sum += ary[i][j][k];


	return sum;
}

int sumAry3D_f2(int(*ary)[2][3],int sec,int row, int col) // 배열의 포인터, 행, 열
{
	int sum = 0;

	for (int i = 0; i < sec; i++)
		for (int j = 0; j < row; j++)
			for (int k = 0; k < col; k++)
				sum += ary[i][j][k];
	
	return sum;
}

int sumAry3D_f3(int ary[2][2][3],int sec, int row, int col) // 배열의 크기가 지정된 파라미터, 행, 열
{
	int sum = 0;

	for (int i = 0; i < sec; i++)
		for (int j = 0; j < row; j++)
			for (int k = 0; k < col; k++)
				sum += ary[i][j][k];

	return sum;
}
