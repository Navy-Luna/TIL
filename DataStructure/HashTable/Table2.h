// 2022.05.05 YJY : HashTable
// ü�̴� ��� �ؽ� ���̺� ������ ���� �ڵ�

#ifndef __TABLE2_H__
#define __TABLE2_H__

#include "Slot2.h"
#include "DLinkedList.h"

#define MAX_TBL     100

typedef int HashFunc(Key k);

typedef struct _table
{
	//	Slot tbl[MAX_TBL];
	List tbl[MAX_TBL]; // ���� ��巹�̰� �޸� slot �迭�� list���·� ����
	HashFunc* hf;
} Table;

void TBLInit(Table* pt, HashFunc* f);
void TBLInsert(Table* pt, Key k, Value v);
Value TBLDelete(Table* pt, Key k);
Value TBLSearch(Table* pt, Key k);

#endif