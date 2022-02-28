/*	윤성우의 열혈 자료구조(윤성우 저) 참고
	2022-02-28 Monday
	연결리스트 기반 큐 구현을 위한 소스 코드
*/
#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue* pq)
{
	// Dequeue가 front에서 일어나니까 front Null이면 큐가 빈 것임
	if (pq->front == NULL) 
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq)) // 첫 번째 노드 추가
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else // 두 번째 이후의 노드 추가
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data Dequeue(Queue* pq)
{
	Node* delNode;
	Data retData;

	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->front;			// 삭제할 노드 저장
	retData = delNode->data;		// 삭제할 노드가 지닌 값 return 위해 저장
	pq->front = pq->front->next;	// 다음 노드 저장

	/* rear에 쓰레기 값 들어가도 QIsEmpty는 front만 확인하기 괜찮음 */
	free(delNode);
	return retData;
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->front->data;
}