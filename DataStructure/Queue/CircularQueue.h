/*	@ �������� ���� �ڷᱸ��(������ ��) ����
	2022-02-28 Monday
	�迭 ��� ���� : ���� ť�� �����ϱ� ���� ��� ����
*/

#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE	1
#define FALSE	0

#define QUE_LEN	100 // ť�� ����
typedef int Data;

typedef struct _cQueue
{
	int front;		// ���� ���� ������ �ε���
	int rear;		// ���� ���� ������ �ε���
	Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue* pq);	// ť �ʱ�ȭ
int QIsEmpty(Queue* pq);	// ť ����ִ��� Ȯ��

void Enqueue(Queue* pq, Data data);	// ������ �ֱ�
Data Dequeue(Queue* pq); // ������ ���
Data QPeek(Queue* pq); // ������ Ȯ��(���� ���� ��)

#endif