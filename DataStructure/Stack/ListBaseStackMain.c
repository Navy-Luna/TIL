*	@ �������� ���� �ڷᱸ��(������ ��) ����
	2022-02-26	Saturday
	������ ���Ḯ��Ʈ ��� Stack�� ����غ��� main
*/
/*
	ListBaseStack.h, ListBaseStack.c
*/

#include <stdio.h>
#include "ListBaseStack.h"


int main(void)
{


	// Stack ���� �� �ʱ�ȭ
	Stack stack;
	StackInit(&stack);

	// ������ push
	SPush(&stack, 10);
	SPush(&stack, 20);
	SPush(&stack, 30);
	
	// ������ peek
	printf("%d\n", SPeek(&stack));


	// ������ pop
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	/* ���� ��°�
	* 30
	* 30 20 10
	*/

	return 0;
}