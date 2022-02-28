/*	윤성우의 열혈 자료구조(윤성우 저)
	2022-02-28 Monday
	구현한 양방향 연결리스트 기반의 덱(Deque)을 사용하는 main
*/

#include <stdio.h>
#include "Deque.h"

int main(void)
{
	// Deque의 생성 및 초기화 ///////
	Deque deq;
	DequeInit(&deq);

	// 데이터 넣기 1차 ///////
	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);

	// 데이터 꺼내기 1차 ///////
	while (!DQIsEmpty(&deq))
		printf("%d ", DQRemoveFirst(&deq));

	/* 예상 출력값 :
		1 2 3 4 5 6
	*/

	printf("\n");

	// 데이터 넣기 2차 ///////
	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);

	// 데이터 꺼내기 2차 ///////
	while (!DQIsEmpty(&deq))
		printf("%d ", DQRemoveLast(&deq));

	/* 예상 출력값 :
		6 5 4 3 2 1
	*/

	return 0;
}