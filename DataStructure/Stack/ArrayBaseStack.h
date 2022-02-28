/* 	@ �������� ���� �ڷᱸ��(������ ��) ����
*	2022-02-26 Saturday
*	�迭 ��� Stack ������ ���� �������
*/

#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100 // ������ ����

// �ʿ信 ���� stack�� �� �ڷ��� ����
typedef int Data;


typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex; // ������ ���� ��
}ArrayStack;

typedef ArrayStack Stack;


void StackInit(Stack* pstack);			// ������ �ʱ�ȭ
int SIsEmpty(Stack* pstack);			// ������ ������� Ȯ��

void SPush(Stack* pstack, Data data);	// ������ push ����
Data SPop(Stack* pstack);				// ������ pop ����
Data SPeek(Stack* pstack);				// ������ peek ����



#endif