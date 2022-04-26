// 2022.4.26 YJY
// 구현한 우선순위 큐를 사용하보는 코드

#include <stdio.h>
#include "PriorityQueue.h"

/* 문자간 아스키 코드 값을 비교하여 더 낮은 것(A에 가까울 수록) 우선순위 높음 */
int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1;
}

int main(void)
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq));

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq));

	while (!PQIsEmpty(&pq))
		printf("%c \n", PDequeue(&pq));

	return 0;
}
