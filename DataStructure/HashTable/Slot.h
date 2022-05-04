// 2022.05.04 YJY : HashTable
// 테이블을 이루는, 데이터를 저장할 수 있는 각각의 공간인 슬롯의 헤더파일

#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key;
typedef Person* Value;

enum SlotStatus { EMPTY, DELETED, INUSE }; // 각각 비어있음, 저장된적 있는데 지금은 없음, 있음 으로 구분한다.

typedef struct _slot
{
	Key key;	// 주민등록번호
	Value val;  // Person 구조체 변수의 주소 값
	enum SlotStatus status;  // 슬롯 상태를 나타내는 멤버
}Slot;

// Slot과 관련해서는 별도의 함수를 정의하지 않는다.
#endif
