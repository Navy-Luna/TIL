/*	�������� ���� �ڷᱸ��(������ ��)
	2022-02-28 Monday
	����� ���Ḯ��Ʈ ����� ��(Deque) ������ ���� �ҽ��ڵ�
*/

#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque* pdeq)	// ���� �ʱ�ȭ
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque* pdeq)					// ���� ������� Ȯ��
{
	if (pdeq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque* pdeq, Data data)		// �� �Ӹ��� ������ �߰�
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // ���ο� ���
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL; 

	if (DQIsEmpty(pdeq))	// ù ��° ���
	{
		pdeq->head = newNode;
		pdeq->tail = newNode;
	}
	else					// �� ��° ��� ����
	{
		pdeq->head->prev = newNode; // ����� ���� �Ű澲��!!!
		newNode->next = pdeq->head;
		pdeq->head = newNode;
	}

}
void DQAddLast(Deque* pdeq, Data data)		// �� ������ ������ �߰�
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // ���ο� ���
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (DQIsEmpty(pdeq)) // ù ��° ���
	{
		pdeq->head = newNode;
		pdeq->tail = newNode;
	}
	else
	{
		pdeq->tail->next = newNode; // ����� ���� �Ű澲��!!!
		newNode->prev = pdeq->tail;
		pdeq->tail = newNode;
	}
}

Data DQRemoveFirst(Deque* pdeq)			// �� �Ӹ��� ������ ����
{
	Data rdata;
	Node* rNode;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque is empty!");
		exit(-1);
	}
	rdata = pdeq->head->data; // ��ȯ�� ������ �ޱ�
	rNode = pdeq->head;
	pdeq->head = pdeq->head->next;

	free(rNode);
	
	return rdata;
}

Data DQRemoveLast(Deque* pdeq)				// �� ������ ������ ����
{
	Data rdata;
	Node* rNode;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque is empty!");
		exit(-1);
	}

	rdata = pdeq->tail->data; // ��ȯ�� ������ �ޱ�
	rNode = pdeq->tail;
	pdeq->tail = pdeq->tail->prev;

	free(rNode);

	return rdata;
}

Data DQGetFirst(Deque* pdeq)				// �� �Ӹ��� ������ Ȯ��
{
	return pdeq->head->data;
}

Data DQGetLast(Deque* pdeq)				// �� ������ ������ Ȯ��
{
	return pdeq->tail->data;
}