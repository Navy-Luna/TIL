/*	윤성우의 열혈 자료구조(윤성우 저)
	2022-02-28 Monday
	덱(Queue)을 통해 큐(Queqe)를 구현하기 위한 헤더파일
*/
#ifndef __DEQUE_BASE_QUEUE_H__
#define __DEQUE_BASE_QUEUE_H__

#include "Deque.h"

typedef Deque Queue; // 이렇게 typedef하나로 구조체 정의를 대신할 수 있음

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);

#endif
