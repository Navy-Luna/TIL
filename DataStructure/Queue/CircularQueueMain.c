/*	@ 윤성우의 열혈 자료구조(윤성우 저) 참고
	2022-02-28 Monday
	배열 기반 구현 : 구현한 원형 큐를 실행시켜 보는 main
*/

#include <stdio.h>
#include "CircularQueue.h"

int main(void)
{
	// Queue의 생성 및 초기화 ///////
	Queue q;
	QueueInit(&q); // 만들고 바로 불려야 됨!

	// 데이터 넣기 ///////
	Enqueue(&q, 1);  
	Enqueue(&q, 2);
	Enqueue(&q, 3);

	// 데이터 꺼내기 ///////
	while (!QIsEmpty(&q))
		printf("%d ", Dequeue(&q));

	return 0;
}