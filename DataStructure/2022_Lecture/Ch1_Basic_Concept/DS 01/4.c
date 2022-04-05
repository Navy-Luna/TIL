/*
	Chap1_Basic_Concept : C Programming Basic
	2차원 배열을 인수로 가지는 세가지 타입의 함수를 사용해보자
*/

#include <stdio.h>

int sumAry2D_f1(int ary[][3], int row, int col); // 배열의 파라미터, 크기
int sumAry2D_f2(int(*ary)[3], int row, int col); // 배열의 포인터, 행, 열
int sumAry2D_f3(int ary[2][3], int row, int col); // 배열의 크기가 지정된 파라미터, 행, 열

int main()
{
	int ary2D[][3] = {{1,2,3},{4, 5, 6}};

	// 각각의 함수들은 모두 ary를 int[3]* 의 함수인자를 사용한다.
	printf("f1: %d\n", sumAry2D_f1(ary2D, 2,3));
	printf("f2: %d\n", sumAry2D_f2(ary2D, 2,3));
	printf("f3: %d\n", sumAry2D_f3(ary2D, 2,3));
}

int sumAry2D_f1(int ary[][3], int row, int col) // 배열의 파라미터, 행, 렬
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += ary[i][j];

	return sum;
}

int sumAry2D_f2(int (*ary)[3], int row, int col) // 배열의 포인터, 행, 열
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += ary[i][j];

	return sum;
}

int sumAry2D_f3(int ary[2][3], int row, int col) // 배열의 크기가 지정된 파라미터, 행, 열
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += ary[i][j];

	return sum;
}
