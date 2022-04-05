/*
	Chap1_Basic_Concept : C Programming Basic
	1차원 배열을 인수로 가지는 세가지 타입의 함수를 사용해보자
*/

#include <stdio.h>

int sumAry1D_f1(int ary[], int size); // 배열의 파라미터, 크기
int sumAry1D_f2(int* ary, int size);  // 배열의 포인터, 크기
int sumAry1D_f3(int ary[6], int size); // 배열 크기 다 적어줌, 크기

int main()
{
	int ary1D[] = { 1,2,3,4,5,6 };

	// 세 함수 모두 ary를 int* 형태로 함수인자를 받는다.
	printf("f1: %d\n", sumAry1D_f1(ary1D, 6));
	printf("f2: %d\n", sumAry1D_f2(ary1D, 6));
	printf("f3: %d\n", sumAry1D_f3(ary1D, 6));
}

int sumAry1D_f1(int ary[], int size) // 배열의 파라미터, 크기
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += ary[i];

	return sum;
}

int sumAry1D_f2(int* ary, int size)  // 배열의 포인터, 크기
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += ary[i];

	return sum;
}

int sumAry1D_f3(int ary[6], int size) // 배열 크기 다 적어줌, 크기
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += ary[i];

	return sum;
}