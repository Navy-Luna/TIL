// 2022.05.04 YJY : HashTable
// ���̺��� �̷��, �����͸� ������ �� �ִ� ������ ������ ������ �������

#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key;
typedef Person* Value;

enum SlotStatus { EMPTY, DELETED, INUSE }; // ���� �������, ������� �ִµ� ������ ����, ���� ���� �����Ѵ�.

typedef struct _slot
{
	Key key;	// �ֹε�Ϲ�ȣ
	Value val;  // Person ����ü ������ �ּ� ��
	enum SlotStatus status;  // ���� ���¸� ��Ÿ���� ���
}Slot;

// Slot�� �����ؼ��� ������ �Լ��� �������� �ʴ´�.
#endif
