// 2022.04.12 : Queues
// 동적할당 배열을 이용한 환형큐를 구현하기

#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME_SIZE 30


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC(p,s){\
	if(!((p)=malloc(s))){ \
		printf("Error!"); \
		exit(-1); \
	}\
}

typedef struct {
	int id;
	char name[MAX_NAME_SIZE];
}element;

element* queue;
int capacity = 2;
int rear = 0;
int front = 0;

void copy(element* a, element* b, element* c);
element deleteq();
element queueEmpty();
void queueFull();
void addq(element item);

int main()
{
	MALLOC(queue, capacity * sizeof(element));

	char input[80];
	char* delimiter = " \n";
	char* op = NULL;
	element student;


	printf("<< circular queue operations where capacity is 2\n\n");

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

void copy(element* a, element* b, element* c)
{
	while (a != b)
		*c++ = *a++;
}

void addq(element item)
{
	rear = (rear + 1) % capacity;
	if (front == rear)
		queueFull();
	queue[rear] = item;
}

element deleteq()
{
	element item;
	if (front == rear)
		return queueEmpty();
	front = (front + 1) % capacity;
	printf("Delete item : %d %s\n", queue[front].id, queue[front].name);
	return queue[front];
}

element queueEmpty()
{
	element error = { -1, NULL };
	printf("Queue is empty\n");
	return error;
}

void queueFull()
{
	int start;
	// allocate an array with twice the capacity
	element* newQueue;
	MALLOC(newQueue, 2 * capacity * sizeof(*queue));

	// copy from queue to newQueue
	start = (front + 1) % capacity; rear--;
	if (start < 2)
		// no wrap around
		copy(queue + start, queue + start + capacity - 1, newQueue);
	else
	{	// queue wraps around
		copy(queue + start, queue + capacity, newQueue);
		copy(queue, queue + rear + 1, newQueue + capacity - start);
	}

	// switch to newQueue
	front = 2 * capacity - 1;
	rear = capacity - 1;
	capacity *= 2;

	printf("Queue size is doubled\n");
	printf("Current queue size is %d\n", capacity);
	free(queue);
	queue = newQueue;
}