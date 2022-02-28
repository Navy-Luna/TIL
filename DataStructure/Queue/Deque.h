/*	�������� ���� �ڷᱸ��(������ ��)
	2022-02-28 Monday
	����� ���Ḯ��Ʈ ����� ��(Deque) ������ ���� �������
*/

#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
	struct _node* prev; // ������� ���� ���� �ʿ�
} Node;

typedef struct _dlDeque
{
	Node* head;
	Node* tail;
} DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque* pdeq);				// ���� �ʱ�ȭ
int DQIsEmpty(Deque* pdeq);					// ���� ������� Ȯ��

void DQAddFirst(Deque* pdeq, Data data);	// �� �Ӹ��� ������ �߰�
void DQAddLast(Deque* pdeq, Data data);		// �� ������ ������ �߰�

Data DQRemoveFirst(Deque* pdeq);			// �� �Ӹ��� ������ ����
Data DQRemoveLast(Deque* pdeq);				// �� ������ ������ ����

Data DQGetFirst(Deque* pdeq);				// �� �Ӹ��� ������ Ȯ��
Data DQGetLast(Deque* pdeq);				// �� ������ ������ Ȯ��

#endif