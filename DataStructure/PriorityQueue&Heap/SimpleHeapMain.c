// 2022.04.26 YJY
// 구현한 단순 힙 : 우선순위 큐에 맞춘 힙 을 사용해보는 main 함수

#include <stdio.h>
#include "SimpleHeap.h"

int main(void)
{
	Heap heap;
	HeapInit(&heap);

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));

	while (!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0;
}
