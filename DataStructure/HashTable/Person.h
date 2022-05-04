// 2022.05.04 YJY : HashTable
// 해쉬 테이블에 사용될 사람에 대한 정보를 담을 구조체와 함수

#ifndef __PERSON_H__
#define __PERSON_H__

#define STR_LEN    50

typedef struct _person
{
	int ssn;    // 주민등록번호 
	char name[STR_LEN];    // 이름
	char addr[STR_LEN];    // 주소
} Person;

// 주민등록번호를 반환
int GetSSN(Person* p);

// 사람의 정보를 출력
void ShowPerInfo(Person* p);

// 사람에 대한 정보를 입력한다.
Person* MakePersonData(int ssn, char* name, char* addr);

#endif