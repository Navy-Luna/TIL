// 2022.05.04 YJY : HashTable
// 실질적인 Table을 구현해보는 코드 : "충돌"문제를 고려하지 않고 코딩

#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

void TBLInit(Table* pt, HashFunc* f)
{
	int i;

	for (i = 0; i < MAX_TBL; i++)
		(pt->tbl[i]).status = EMPTY;

	pt->hf = f;
}

void TBLInsert(Table* pt, Key k, Value v)
{
	// 해쉬 함수에 넣어서 key값을 새롭게 반환
	int hv = pt->hf(k);
	pt->tbl[hv].val = v;
	pt->tbl[hv].key = k;
	pt->tbl[hv].status = INUSE;
}

Value TBLDelete(Table* pt, Key k)
{
	int hv = pt->hf(k);

	if ((pt->tbl[hv]).status != INUSE)
	{
		return NULL;
	}
	else
	{
		(pt->tbl[hv]).status = DELETED;
		return (pt->tbl[hv]).val;
	}
}

Value TBLSearch(Table* pt, Key k)
{
	int hv = pt->hf(k);

	if ((pt->tbl[hv]).status != INUSE)
		return NULL;
	else
		return (pt->tbl[hv]).val;
}