/*	@ �������� ���� �ڷᱸ��(������ ��) ����
	2022-02-28 Monday
	�迭 ��� ���� : ������ ���� ť�� ������� ���� main
*/

#include <stdio.h>
#include "CircularQueue.h"

int main(void)
{
	// Queue�� ���� �� �ʱ�ȭ ///////
	Queue q;
	QueueInit(&q); // ����� �ٷ� �ҷ��� ��!

	// ������ �ֱ� ///////
	Enqueue(&q, 1);  
	Enqueue(&q, 2);
	Enqueue(&q, 3);

	// ������ ������ ///////
	while (!QIsEmpty(&q))
		printf("%d ", Dequeue(&q));

	return 0;
}