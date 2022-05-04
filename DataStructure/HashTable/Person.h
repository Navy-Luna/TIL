// 2022.05.04 YJY : HashTable
// �ؽ� ���̺� ���� ����� ���� ������ ���� ����ü�� �Լ�

#ifndef __PERSON_H__
#define __PERSON_H__

#define STR_LEN    50

typedef struct _person
{
	int ssn;    // �ֹε�Ϲ�ȣ 
	char name[STR_LEN];    // �̸�
	char addr[STR_LEN];    // �ּ�
} Person;

// �ֹε�Ϲ�ȣ�� ��ȯ
int GetSSN(Person* p);

// ����� ������ ���
void ShowPerInfo(Person* p);

// ����� ���� ������ �Է��Ѵ�.
Person* MakePersonData(int ssn, char* name, char* addr);

#endif