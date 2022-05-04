// 2022.05.05 YJY : HashTable
// 체이닝 기반 해쉬 테이블 구현을 위한 코드

#ifndef __TABLE2_H__
#define __TABLE2_H__

#include "Slot2.h"
#include "DLinkedList.h"

#define MAX_TBL     100

typedef int HashFunc(Key k);

typedef struct _table
{
	//	Slot tbl[MAX_TBL];
	List tbl[MAX_TBL]; // 열린 어드레싱과 달리 slot 배열을 list형태로 변경
	HashFunc* hf;
} Table;

void TBLInit(Table* pt, HashFunc* f);
void TBLInsert(Table* pt, Key k, Value v);
Value TBLDelete(Table* pt, Key k);
Value TBLSearch(Table* pt, Key k);

#endif