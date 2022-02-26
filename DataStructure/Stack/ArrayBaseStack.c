/*
*	2022-02-26 Saturday
*	배열 기반 Stack 구현을 위한 코드
*/

#include <stdio.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;		// -1일때는 빈 상태
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->topIndex == -1) // 스택이 비었음
		return TRUE;
	else
		return FALSE;
}


void SPush(Stack* pstack, Data data) // Push
{
	pstack->topIndex += 1; // top을 하나 올려주고
	pstack->stackArr[pstack->topIndex] = data; // 데이터 저장
}

Data SPop(Stack* pstack) // Pop
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory is Empty!");
		exit(-1);
	}

	rIdx = pstack->topIndex; // 삭제할 데이터의 인덱스를 저장하고
	pstack->topIndex -= 1; // top을 하나 내려주고

	return pstack->stackArr[rIdx]; // 삭제한 데이터 반환(배열에는 남아있음)
}

Data SPeek(Stack* pstack) // Peek
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory is Empty!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex]; // 가장 위의 뎅터 반환
}