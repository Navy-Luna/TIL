// 2022.4.26 YJY
// 우선순위 큐의 구현 : 우선순위 큐를 목표로 힙을 구현했기 때문에 기존 파일을 적극 사용

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