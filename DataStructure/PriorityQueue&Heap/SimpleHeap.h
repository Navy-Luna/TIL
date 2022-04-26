// 2022.04.26 YJY
// 간단한 힙을 구현하기 위한 코드

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

/* 자유롭게 데이터 변경 가능 */
typedef char HData;
typedef int Priority;

/* heap의 element */
typedef struct _heapElem
{
	Priority pr;	// 값이 작을수록 높은 우선순위
	HData data;
}HeapElem;

/* heap 구조체 정의 */
typedef struct _heap
{
	int numOfData;		// 힙에 포함된 데이터 개수
	HeapElem heapArr[HEAP_LEN];

}Heap;


void HeapInit(Heap* ph);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data, Priority pr);
HData HDelete(Heap* ph);
