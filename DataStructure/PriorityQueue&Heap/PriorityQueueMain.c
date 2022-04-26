// 2022.4.26 YJY
// ������ �켱���� ť�� ����Ϻ��� �ڵ�

#include <stdio.h>
#include "PriorityQueue.h"

/* ���ڰ� �ƽ�Ű �ڵ� ���� ���Ͽ� �� ���� ��(A�� ����� ����) �켱���� ���� */
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
