// 2022.04.12 : Queues
// 정적할당배열을 이용한 선형큐를 구현하기

#define _CRT_SECURE_NO_WARNINGS
#define MAX_QUEUE_SIZE 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;			// unique id
	char name[MAX_QUEUE_SIZE]; // last name
}element;

element queue[MAX_QUEUE_SIZE];
element items;
int rear = -1;
int front = -1;

void addq(element item);
void queueFull();
element deleteq();
element queueEmpty();

int main()
{
	char input[80];
	char* delimiter = " \n";
	char* op = NULL;
	element student;
	int cnt;

	printf("<< linear queue operations where MAX_QUEUE_SIZE is 5\n\n");

	while (1)
	{
		gets(input);
		op = strtok(input, delimiter);

		if (!strcmp(op, "add"))
		{
			sscanf(input + strlen(op) + 1, "%d%s", &student.id, student.name);
			addq(student);
		}
		else if (!strcmp(op, "delete"))
		{
			element item;
			item = deleteq();
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

void addq(element item)
{

	if (rear == MAX_QUEUE_SIZE - 1)
		queueFull();

	queue[++rear] = item;
}

void queueFull()
{
	if (front == -1)
	{
		printf("Queue is full, cannot add element!\n");
		while (1)
		{
			element result;
			result = deleteq();

			if (result.id == -1)
				exit(EXIT_FAILURE);

			printf("%d %s\n", result.id, result.name);
		}
	}
	else
	{
		printf("array shifting...\n");
		int i, j = 0;
		for (i = front + 1; i <= rear; i++)
			queue[j++] = queue[i];

		queue[j] = items;
		front = -1;
		rear = j - 1;

	}
}

element deleteq()
{
	if (front == rear)
		return queueEmpty();

	return queue[++front];
}

element queueEmpty()
{
	printf("Queue is empty\n");
	element wrong = { -1, NULL };
	return wrong;
}
