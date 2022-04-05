/*
	Chap1_Basic_Concept : C Programming Basic
	1차원 포인터 배열을 사용하여 변수 a,b,c의 내용을 출력하세요
*/

#include <stdio.h>

int main()
{
	int a=2, b=3, c=4;

	int* p[3] = { &a,&b,&c };
	
	printf("포인터 배열의 배열요소를 이용한 a,b,c 출력");
	
	printf("\na: %d, b: %d, c: %d", *p[0], *p[1], *p[2]);

	return 0;
}