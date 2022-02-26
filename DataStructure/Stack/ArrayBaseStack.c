/*
*	2022-02-26 Saturday
*	�迭 ��� Stack ������ ���� �ڵ�
*/

#include <stdio.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;		// -1�϶��� �� ����
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->topIndex == -1) // ������ �����
		return TRUE;
	else
		return FALSE;
}


void SPush(Stack* pstack, Data data) // Push
{
	pstack->topIndex += 1; // top�� �ϳ� �÷��ְ�
	pstack->stackArr[pstack->topIndex] = data; // ������ ����
}

Data SPop(Stack* pstack) // Pop
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory is Empty!");
		exit(-1);
	}

	rIdx = pstack->topIndex; // ������ �������� �ε����� �����ϰ�
	pstack->topIndex -= 1; // top�� �ϳ� �����ְ�

	return pstack->stackArr[rIdx]; // ������ ������ ��ȯ(�迭���� ��������)
}

Data SPeek(Stack* pstack) // Peek
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory is Empty!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex]; // ���� ���� ���� ��ȯ
}