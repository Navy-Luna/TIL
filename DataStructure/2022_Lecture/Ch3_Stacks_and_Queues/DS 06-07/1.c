/* 
   2022.04.12 : Stacks
   정적할당배열을 사용한 스택의 구현
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
	char* delimiter = " \n";  // 자르는 기준을 여러개 넣을 수 있음! 여기서는 공백과 줄바꿈
	char* op = NULL;
	element student;

	while (1)
	{
		gets(input);
		/* strtok는 문자열 자르기 함수(<string.h> include필요) 첫번째 문자열을 두번재의 것들을 기준으로 자른다 */
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

