/*	윤성우의 열혈 자료구조(윤성우 저)
	2022-02-28 Monday
	덱(Queue)으로 구현한 큐(Queqe)를 활용하는 main
*/

#include <stdio.h>
#include "DequeBaseQueue.h"

int main(void)
{
	Queue q;
	QueueInit(&q);

	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);
	Enqueue(&q, 5);

	while (!QIsEmpty(&q))
		printf("%d ", Dequeue(&q));

	/* 예상 결과값:
		1 2 3 4 5
	*/

	return 0;
}