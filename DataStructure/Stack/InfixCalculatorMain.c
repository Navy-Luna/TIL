/*
	2022-02-26 Saturday
	���� : ��ȭ(����)
	���� ǥ������ �ı� ǥ�������� �ٲپ� ����� ���� ����
*/

/*
	������ Ȱ��					: ListBaseStack.h, ListBaseStack.c
	���� ǥ����� �������� ��ȯ : InfixToPostfix.h, InfixToPostfix.c
	���� ǥ����� ������ ���	: PostCalculator.h, PostCalculator.c
	���� ǥ����� ������ ���	: InfixCalculator.h, InfixCalculator.c
*/

#include <stdio.h>
#include "InfixCalculator.h"

int main(void)
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	printf("%s = %d \n", exp1, EvalInfixExp(exp1));
	printf("%s = %d \n", exp2, EvalInfixExp(exp2));
	printf("%s = %d \n", exp3, EvalInfixExp(exp3));

	return 0;
}