// 2022.4.26 YJY
// �켱���� ť�� ���� : �켱���� ť�� ��ǥ�� ���� �����߱� ������ ���� ������ ���� ���

#include "PriorityQueue.h"
#include "UsefulHeap.h"

void PQueueInit(PQueue* ppq, PriorityComp pc)
{
	HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue* ppq)
{
	return HIsEmpty(ppq);
}

void PEnqueue(PQueue* ppq, PQData data)
{
	HInsert(ppq, data);
}

PQData PDequeue(PQueue* ppq)
{
	return HDelete(ppq);
}