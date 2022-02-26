/*
	2022-02-26	Saturday
	연결리스트 기반 Stack 구현을 위한 헤더파일
	Stack = 헤더에 추가되는 연결리스트
*/

#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE  1
#define FALSE 0

typedef int Data; // 스택에 들어가는 자료형 변경


typedef struct _node // 연결 리스트의 노드를 표현한 구조체
{
	Data data;
	struct _node* next;
}Node;


typedef struct _listStack // 연결 리스트 기반 스택을 표현한 구조체
{
	Node* head;
}ListStack;


typedef ListStack Stack;


void StackInit(Stack* pstack);				// 스택 초기화
int SIsEmpty(Stack* pstack);				// 스택이 비었는지 확인

void SPush(Stack* pstack, Data data);		// 스택의 push
Data SPop(Stack* pstack);					// 스택의 pop
Data SPeek(Stack* pstack);					// 스택의 peek


#endif
