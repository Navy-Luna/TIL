/*
	2022-02-26 Saturday
	������ �迭 ��� Stack�� ����غ��� main �Լ� 
*/
/*
	ArrayBaseStack.h, ArrayBaseStack.c
*/

#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void)
{
	// Stack�� ���� �� �ʱ�ȭ
	Stack stack;
	StackInit(&stack); // Stack �ʱ�ȭ �ʼ�

	// ������ �ֱ� : Put
	SPush(&stack, 1);
	SPush(&stack, 12);
	SPush(&stack, 9);

	// top�� ������ Ȯ���ϱ� : Peek
	printf("%d\n", SPeek(&stack));

	// ������ ������ : Pop
	while (!SIsEmpty(&stack))
	{
		printf("%d ", SPop(&stack));
	}

	/*	���� ��°� : ����� ���� ��µ�
		9
		9 12 1
	*/

	return 0;
}