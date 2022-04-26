// 2022.04.26 YJY
// 힙을 구현하기 위한 헤더파일 : 우선순위를 힙에서 비교하도록 하여 정의
#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__
// ifndef를 사용하지 않으면 구조체와 같은 것의 재정의 문제가 발생할 수 있음

#define TRUE	1
#define FALSE	0

/*** Heap의 정의 ****/
#define HEAP_LEN	100

typedef char HData;

// d1의 우선순위가 높다면 0보다 큰 값
// d2의 우선순위가 높다면 0보다 작은 값
// d1과 d2의 우선순위가 같다면 0을 반환
typedef int (*PriorityComp)(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

/*** Heap 관련 연산들 ****/
void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);

#endif
