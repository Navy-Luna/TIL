/*
	Chap1_Basic_Concept : C Programming Basic
	1���� ������ �迭�� ����Ͽ� ���� a,b,c�� ������ ����ϼ���
*/

#include <stdio.h>

int main()
{
	int a=2, b=3, c=4;

	int* p[3] = { &a,&b,&c };
	
	printf("������ �迭�� �迭��Ҹ� �̿��� a,b,c ���");
	
	printf("\na: %d, b: %d, c: %d", *p[0], *p[1], *p[2]);

	return 0;
}