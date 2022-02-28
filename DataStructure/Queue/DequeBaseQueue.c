/*	윤성우의 열혈 자료구조(윤성우 저)
	2022-02-28 Monday
	덱(Queue)을 통해 큐(Queqe)를 구현하기 위한 소스파일
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