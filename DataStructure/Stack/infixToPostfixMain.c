/*	@ �������� ���� �ڷᱸ��(������ ��) ����
	2022-02-26 Saturday : ���� ��ȭ(����)
	���� ������� ���� ��������� ��ȯ��Ų �ڵ带 Ȯ���ϱ� ���� main
*/
/*
	������ Ȱ��					: ListBaseStack.h, ListBaseStack.c
	�������� ���������� ��ȯ	: InfixToPostfix.h, InfixToPostifix.c
*/

#include <stdio.h>
#include <string.h>
#include "InfixToPostfix.h"

int main(void)
{

	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);

	printf("%s \n", exp1);
	printf("%s \n", exp2);
	printf("%s \n", exp3);
}