/*	�������� ���� �ڷᱸ��(������ ��)
	2022-02-28 Monday
	��(Queue)�� ���� ť(Queqe)�� �����ϱ� ���� �ҽ�����
*/

#include "DequeBaseQueue.h"
#include <stdlib.h>

void QueueInit(Queue* pq) 
{
	pq->head = NULL;
	pq->tail = NULL;
}

int QIsEmpty(Queue* pq)
{
	if (pq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
	DQAddLast(pq, data);
}
Data Dequeue(Queue* pq) 
{
	return DQRemoveFirst(pq);
}
Data QPeek(Queue* pq)
{
	return DQGetFirst(pq);
}