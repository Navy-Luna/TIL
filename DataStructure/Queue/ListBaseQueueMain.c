/*	�������� ���� �ڷᱸ��(������ ��) ����
	2022-02-28 Monday
	���Ḯ��Ʈ ��� ť�� Ȱ���غ��� main
*/

#include <stdio.h>
#include "ListBaseQueue.h"

int main(void)
{
	// Queue�� ���� �� �ʱ�ȭ ///////
	Queue q;
	QueueInit(&q);

	// ������ �ֱ� ///////
	Enqueue(&q, 1);  Enqueue(&q, 2);
	Enqueue(&q, 3);  Enqueue(&q, 4);
	Enqueue(&q, 5);

	// ������ ������ ///////
	while (!QIsEmpty(&q))
		printf("%d ", Dequeue(&q));

	/*	���� ��°� :
		1 2 3 4 5
	*/

	return 0;
}