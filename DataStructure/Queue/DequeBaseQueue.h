/*	�������� ���� �ڷᱸ��(������ ��)
	2022-02-28 Monday
	��(Queue)�� ���� ť(Queqe)�� �����ϱ� ���� �������
*/
#ifndef __DEQUE_BASE_QUEUE_H__
#define __DEQUE_BASE_QUEUE_H__

#include "Deque.h"

typedef Deque Queue; // �̷��� typedef�ϳ��� ����ü ���Ǹ� ����� �� ����

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);

#endif
