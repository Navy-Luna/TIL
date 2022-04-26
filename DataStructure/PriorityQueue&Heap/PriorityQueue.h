// 2022.4.26 YJY
// �켱���� ť�� ���� : �켱���� ť�� ��ǥ�� ���� �����߱� ������ ���� ������ ���� ���
#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "UsefulHeap.h"

typedef Heap PQueue;
typedef HData PQData;

void PQueueInit(PQueue* ppq, PriorityComp pc);
int PQIsEmpty(PQueue* ppq);

void PEnqueue(PQueue* ppq, PQData data);
PQData PDequeue(PQueue* ppq);

#endif