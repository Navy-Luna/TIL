/*	�������� ���� �ڷᱸ��(������ ��) ����
	2022-02-28 Monday
	���Ḯ��Ʈ ��� ť ������ ���� �������
*/

#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node // ���
{
	Data data;
	struct _node* next;
} Node;

typedef struct _lQueue // �迭�� ���� �ʿ����
{
	// �迭 ��ݰ��� �޸� �ε��� ���� �ʿ� ����
	// enqueue�� dequeue �Ǵ� ���� ��ġ �ٸ��� ������ ������ �ʿ�!
	Node* front;
	Node* rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue* pq); // ť �ʱ�ȭ
int QIsEmpty(Queue* pq); // ť�� ������� Ȯ��

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);

#endif