/*
   2022.04.11
   정적할당 배열, 동적할당 배열, 구조체 학습을 복습하기 위한 코드
   (4) 두 구조체의 동등성을 체크하는 프로그램을 만들어보자(포인터 이용)
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
	
	scanf("%c", &c); // null 문자 삭-제

	printf("Input person2's name, age, salary :\n");
	gets(person2.name);		// gets를 사용할 때는 항상 이전에 \n문자로 인한 오류를 조심하자!!!
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
	if (strcmp(person1->name, person2->name) != 0) // 대소문자 구별함 -> if) 대소문자 구별x 려면 stricmp를 사용
		return FALSE;
	if (person1->age != person2->age)
		return FALSE;
	if (person1->salary != person2->salary)
		return FALSE;

	return TRUE;
}