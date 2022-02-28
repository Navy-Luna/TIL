/*	@ �������� ���� �ڷᱸ��(������ ��) ����
	2022-02-26	Saturday
	���Ḯ��Ʈ ��� Stack ������ ���� �ڵ�
	Stack = ����� �߰��Ǵ� ���Ḯ��Ʈ
*/

#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"


void StackInit(Stack* pstack)	// ���� �ʱ�ȭ
{
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack)		// ���� ������� Ȯ��
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) // ������ push
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	// stdlib�ȿ� malloc�� free�� ���ǵǾ� �����Ƿ� #include <stdlib.h>
	// �߸��ϸ� ���ǰ� �ȵǼ� ���⼭ �����
	NewNode->data = data;
	NewNode->next = pstack->head;

	pstack->head = NewNode; // head�� ���ο� ������ �߰�

	return;
}

Data SPop(Stack* pstack)	// ������ pop
{
	Data rdata;
	Node* rnode; // ������ node�� free�� ���� ����

	if (SIsEmpty(pstack))
	{
		printf("Stack is Empty!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next; // pop
	free(rnode); // �޸� ���� ������ ���� free

	return rdata;

}

Data SPeek(Stack* pstack)	// ������ peek
{
	if (SIsEmpty(pstack))
	{
		printf("Stack is Empty!");
		exit(-1);
	}

	return pstack->head->data;
}