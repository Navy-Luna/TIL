// 2022.04.26 YJY
// 단순 힙의 구현을 위한 소스코드 : 우선순위 큐에 맞게 힙을 구현

#include "SimpleHeap.h"

void HeapInit(Heap* ph)		// 힙의 초기화
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph)		// 힙이 비었는지 확인
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx)	// 부모 노드의 인덱스 반환
{
	return idx / 2;
}

int GetLChildIDX(int idx)	// 왼쪽 자식 노드의 인덱스 반환
{
	return idx * 2;
}

int GetRChildIDX(int idx)	// 오른쪽 자식 노드의 인덱스 반환
{
	return GetLChildIDX(idx) + 1;
}

/* 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환 */
int GetHiPriChildIDX(Heap* ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData)    // 자식 노드가 없다면
		return 0;

	else if (GetLChildIDX(idx) == ph->numOfData)    // 왼쪽 자식 노드가 마지막 노드라면
		return GetLChildIDX(idx);

	else   // 왼쪽 자식 노드와 오른쪽 자식 노드의 우선순위를 비교
	{
		if (ph->heapArr[GetLChildIDX(idx)].pr
						> ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

/* 힙에서 데이터 저장 */
void HInsert(Heap* ph, HData data, Priority pr)
{
	int idx = ph->numOfData + 1;
	HeapElem nelem = { pr, data };

	while (idx != 1)
	{
		if (pr < (ph->heapArr[GetParentIDX(idx)].pr))
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}

	ph->heapArr[idx] = nelem;
	ph->numOfData += 1;
}

/* 힙에서 데이터 삭제 */
HData HDelete(Heap* ph)
{
	HData retData = (ph->heapArr[1]).data;    // 삭제할 데이터 임시 저장(Root)
	HeapElem lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;    // 루트 노드의 Index
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		if (lastElem.pr <= ph->heapArr[childIdx].pr)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}