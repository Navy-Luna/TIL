/*	@ �������� ���� �ڷᱸ��(������ ��) ����
	2022-02-28 Monday
	�迭 ��� ���� : ���� ť�� �����ϱ� ���� �ҽ� �ڵ�
*/

#include <stdio.h>
#include <stdlib.h> // exit ���ؼ� �ʿ�
#include "CircularQueue.h"

void QueueInit(Queue* pq) // ť �ʱ�ȭ
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue* pq) // front�� rear�� ���� ��ġ�� ��, �������
{
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos) // ť�� ���� ��ġ�� �ش��ϴ� �ε����� ��ȯ
{
	if (pos == QUE_LEN - 1) // �迭�� ���� �������� ��
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue* pq, Data data) // rear�� �� ĭ �̵����� �����͸� �������
{
	// front���� �����Ͱ� �ְų� ������ֱ� ������ rear ������ front�� ����!
	// Queue�� �� ��
	if (NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue Memory is Full!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue* pq)
{
	// ť�� ������� dequeue �� �� ����
	if (QIsEmpty(pq))
	{
		printf("Queue Memory is empty!");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory is empty!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}