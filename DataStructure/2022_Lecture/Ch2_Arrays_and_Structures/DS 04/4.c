/*
   2022.04.11
   �����Ҵ� �迭, �����Ҵ� �迭, ����ü �н��� �����ϱ� ���� �ڵ�
   (4) �� ����ü�� ����� üũ�ϴ� ���α׷��� ������(������ �̿�)
 */

#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1	
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[20];
	int age;
	float salary;
}humanbeing;

int main()
{
	char c;
	humanbeing person1, person2;
	printf("Input person1's name, age, salary :\n");
	gets(person1.name);
	scanf("%d", &person1.age);
	scanf("%f", &person1.salary);

	printf("\n");
	
	scanf("%c", &c); // null ���� ��-��

	printf("Input person2's name, age, salary :\n");
	gets(person2.name);		// gets�� ����� ���� �׻� ������ \n���ڷ� ���� ������ ��������!!!
	scanf("%d", &person2.age);
	scanf("%f", &person2.salary);

	if (humansEqual(&person1, &person2))
		printf("The two human beings are the same.");
	else
		printf("The two human beings are not the same.");

	return 0;
}

int humansEqual(humanbeing* person1, humanbeing* person2)
{
	if (strcmp(person1->name, person2->name) != 0) // ��ҹ��� ������ -> if) ��ҹ��� ����x ���� stricmp�� ���
		return FALSE;
	if (person1->age != person2->age)
		return FALSE;
	if (person1->salary != person2->salary)
		return FALSE;

	return TRUE;
}