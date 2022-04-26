// 2022.4.26 YJY
// 우선순위 큐의 구현 : 우선순위 큐를 목표로 힙을 구현했기 때문에 기존 파일을 적극 사용
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