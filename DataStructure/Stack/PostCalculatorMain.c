/*	@ �������� ���� �ڷᱸ��(������ ��) ����
	2022-02-26	Saturday
	����������� ���� ������ �����غ��� main
*/
/*
	������ Ȱ��					: ListBaseStack.h, ListBaseStack.c
	��ȯ�� �������� ���		: PostCalculator.h, PostCalculator.c
*/

#include <stdio.h>
#include "PostCalculator.h"

int main(void)
{
	char postExp1[] = "42*8+";
	char postExp2[] = "123+*4/";

	printf("%s = %d \n", postExp1, EvalRPNExp(postExp1));
	printf("%s = %d \n", postExp2, EvalRPNExp(postExp2));

	return 0;
}