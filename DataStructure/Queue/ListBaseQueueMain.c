/*	윤성우의 열혈 자료구조(윤성우 저) 참고
	2022-02-28 Monday
	연결리스트 기반 큐를 활용해보는 main
*/

#include <stdio.h>
#include "ListBaseQueue.h"

int main(void)
{
	// Queue의 생성 및 초기화 ///////
	Queue q;
	QueueInit(&q);

	// 데이터 넣기 ///////
	Enqueue(&q, 1);  Enqueue(&q, 2);
	Enqueue(&q, 3);  Enqueue(&q, 4);
	Enqueue(&q, 5);

	// 데이터 꺼내기 ///////
	while (!QIsEmpty(&q))
		printf("%d ", Dequeue(&q));

	/*	예상 출력값 :
		1 2 3 4 5
	*/

	return 0;
}