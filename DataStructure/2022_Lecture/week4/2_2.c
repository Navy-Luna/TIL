/* 2020110249 윤주영
   본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
	int id;			// unique id
	char name[MAX_STACK_SIZE]; // last name
}element;

element stack[MAX_STACK_SIZE];
int top = -1;

void push(element item);
element pop();
void stackFull();
element stackEmpty();

int main()
{
	char input[80];
	char* delimiter = " \n";
	char* op = NULL;
	element student;
	int cnt;

	while (1)
	{
		gets(input);
		op = strtok(input, delimiter);

		if (!strcmp(op, "push"))
		{
			sscanf(input + strlen(op) + 1, "%d%s", &student.id, student.name);
			push(student);
		}
		else if (!strcmp(op, "pop"))
		{
			element item;
			item = pop();
			if (item.id == -1)
				exit(EXIT_FAILURE);
		}
		else if (!strcmp(op, "quit"))
			break;
		else
			printf("wrong command! try again!\n");

	}

	return 0;
}




void push(element item)
{	// add an item to the global stack
	if (top >= MAX_STACK_SIZE-1)
		stackFull();

	stack[++top] = item;
}

element pop()
{
	// delete and return the top element from the stack
	if (top == -1)
		return stackEmpty();

	return stack[top--];
}

void stackFull()
{
	printf("stack is full, cannot add element\n");
	printf("current stack elements :");

	while (1)
	{
		if (top == -1)
		{
			break;
		}

		element result = pop();
		printf("\n%d %s", result.id, result.name);
	}
}

element stackEmpty()
{

	element empty;
	empty.id = -1;

	printf("Stack is empty!!\n");

	return empty;
}

