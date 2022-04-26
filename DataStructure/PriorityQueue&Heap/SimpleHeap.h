// 2022.04.26 YJY
// ������ ���� �����ϱ� ���� �ڵ�

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

/* �����Ӱ� ������ ���� ���� */
typedef char HData;
typedef int Priority;

/* heap�� element */
typedef struct _heapElem
{
	Priority pr;	// ���� �������� ���� �켱����
	HData data;
}HeapElem;

/* heap ����ü ���� */
typedef struct _heap
{
	int numOfData;		// ���� ���Ե� ������ ����
	HeapElem heapArr[HEAP_LEN];

}Heap;


void HeapInit(Heap* ph);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data, Priority pr);
HData HDelete(Heap* ph);
