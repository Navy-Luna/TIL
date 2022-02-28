/*	@ 윤성우의 열혈 자료구조(윤성우 저) 참고
	2022-02-28 Monday
	배열 기반 구현 : 원형 큐를 구현하기 위한 소스 코드
*/

#include <stdio.h>
#include <stdlib.h> // exit 위해서 필요
#include "CircularQueue.h"

void QueueInit(Queue* pq) // 큐 초기화
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue* pq) // front와 rear이 같은 위치일 때, 비어있음
{
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos) // 큐의 다음 위치에 해당하는 인덱스를 반환
{
	if (pos == QUE_LEN - 1) // 배열의 끝에 도달했을 때
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue* pq, Data data) // rear을 한 칸 이동시켜 데이터를 집어넣음
{
	// front에는 데이터가 있거나 비워져있기 때문에 rear 다음이 front면 에러!
	// Queue가 꽉 참
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
	// 큐가 비었으면 dequeue 할 게 없음
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