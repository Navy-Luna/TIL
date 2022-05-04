// 2022.05.04 YJY : HashTable
// 해쉬 테이블에 사용될 사람에 대한 정보를 담을 구조체와 함수

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person* p)
{
	return p->ssn;
}

void ShowPerInfo(Person* p)
{
	printf("주민등록번호: %d \n", p->ssn);
	printf("이름: %s \n", p->name);
	printf("주소: %s \n\n", p->addr);
}

Person* MakePersonData(int ssn, char* name, char* addr)
{
	Person* newP = (Person*)malloc(sizeof(Person));

	newP->ssn = ssn;
	strcpy(newP->name, name);
	strcpy(newP->addr, addr);
	return newP;
}
