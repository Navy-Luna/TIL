/*	윤성우의 열혈 자료구조(윤성우 저)
	2022-02-28 Monday
	양방향 연결리스트 기반의 덱(Deque) 구현을 위한 소스코드
*/

#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque* pdeq)	// 덱의 초기화
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque* pdeq)					// 덱이 비었는지 확인
{
	if (pdeq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque* pdeq, Data data)		// 덱 머리에 데이터 추가
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // 새로운 노드
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL; 

	if (DQIsEmpty(pdeq))	// 첫 번째 노드
	{
		pdeq->head = newNode;
		pdeq->tail = newNode;
	}
	else					// 두 번째 노드 이후
	{
		pdeq->head->prev = newNode; // 양방향 연결 신경쓰자!!!
		newNode->next = pdeq->head;
		pdeq->head = newNode;
	}

}
void DQAddLast(Deque* pdeq, Data data)		// 덱 꼬리에 데이터 추가
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // 새로운 노드
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (DQIsEmpty(pdeq)) // 첫 번째 노드
	{
		pdeq->head = newNode;
		pdeq->tail = newNode;
	}
	else
	{
		pdeq->tail->next = newNode; // 양방향 연결 신경쓰자!!!
		newNode->prev = pdeq->tail;
		pdeq->tail = newNode;
	}
}

Data DQRemoveFirst(Deque* pdeq)			// 덱 머리의 데이터 제거
{
	Data rdata;
	Node* rNode;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque is empty!");
		exit(-1);
	}
	rdata = pdeq->head->data; // 반환할 데이터 받기
	rNode = pdeq->head;
	pdeq->head = pdeq->head->next;

	free(rNode);
	
	return rdata;
}

Data DQRemoveLast(Deque* pdeq)				// 덱 꼬리의 데이터 제거
{
	Data rdata;
	Node* rNode;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque is empty!");
		exit(-1);
	}

	rdata = pdeq->tail->data; // 반환할 데이터 받기
	rNode = pdeq->tail;
	pdeq->tail = pdeq->tail->prev;

	free(rNode);

	return rdata;
}

Data DQGetFirst(Deque* pdeq)				// 덱 머리의 데이터 확인
{
	return pdeq->head->data;
}

Data DQGetLast(Deque* pdeq)				// 덱 꼬리의 데이터 확인
{
	return pdeq->tail->data;
}