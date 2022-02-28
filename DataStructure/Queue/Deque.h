/*	윤성우의 열혈 자료구조(윤성우 저)
	2022-02-28 Monday
	양방향 연결리스트 기반의 덱(Deque) 구현을 위한 헤더파일
*/

#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
	struct _node* prev; // 양방향을 가기 위해 필요
} Node;

typedef struct _dlDeque
{
	Node* head;
	Node* tail;
} DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque* pdeq);				// 덱의 초기화
int DQIsEmpty(Deque* pdeq);					// 덱이 비었는지 확인

void DQAddFirst(Deque* pdeq, Data data);	// 덱 머리에 데이터 추가
void DQAddLast(Deque* pdeq, Data data);		// 덱 꼬리에 데이터 추가

Data DQRemoveFirst(Deque* pdeq);			// 덱 머리의 데이터 제거
Data DQRemoveLast(Deque* pdeq);				// 덱 꼬리의 데이터 제거

Data DQGetFirst(Deque* pdeq);				// 덱 머리의 데이터 확인
Data DQGetLast(Deque* pdeq);				// 덱 꼬리의 데이터 확인

#endif