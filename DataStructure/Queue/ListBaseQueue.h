/*	윤성우의 열혈 자료구조(윤성우 저) 참고
	2022-02-28 Monday
	연결리스트 기반 큐 구현을 위한 헤더파일
*/

#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node // 노드
{
	Data data;
	struct _node* next;
} Node;

typedef struct _lQueue // 배열이 따로 필요없음
{
	// 배열 기반과는 달리 인덱스 관리 필요 없음
	// enqueue와 dequeue 되는 연산 위치 다르기 때문에 별도로 필요!
	Node* front;
	Node* rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue* pq); // 큐 초기화
int QIsEmpty(Queue* pq); // 큐가 비었는지 확인

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);

#endif