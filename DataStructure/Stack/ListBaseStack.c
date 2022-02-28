/*	@ 윤성우의 열혈 자료구조(윤성우 저) 참고
	2022-02-26	Saturday
	연결리스트 기반 Stack 구현을 위한 코드
	Stack = 헤더에 추가되는 연결리스트
*/

#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"


void StackInit(Stack* pstack)	// 스택 초기화
{
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack)		// 스택 비었는지 확인
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) // 스택의 push
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	// stdlib안에 malloc과 free가 정의되어 있으므로 #include <stdlib.h>
	// 잘못하면 정의가 안되서 여기서 종료됨
	NewNode->data = data;
	NewNode->next = pstack->head;

	pstack->head = NewNode; // head에 새로운 노드들을 추가

	return;
}

Data SPop(Stack* pstack)	// 스택의 pop
{
	Data rdata;
	Node* rnode; // 삭제할 node의 free를 위한 변수

	if (SIsEmpty(pstack))
	{
		printf("Stack is Empty!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next; // pop
	free(rnode); // 메모리 낭비 방지를 위해 free

	return rdata;

}

Data SPeek(Stack* pstack)	// 스택의 peek
{
	if (SIsEmpty(pstack))
	{
		printf("Stack is Empty!");
		exit(-1);
	}

	return pstack->head->data;
}