// 2022.04.13 Single Linked List / Chain
// 입력파일로부터 데이터를 받아 정렬된 체인을 만드는 프로그램

#define _CRT_SECURE_NO_WARNINGS
#define COMPARE(x,y) ( ((x)>(y)) ? 1 : ((x)==(y)) ? 0 : -1)
#define MALLOC(p,s){\
	if(!((p) = malloc(s))) {\
		printf("Fail to allocate!"); \
	} \
}


#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;

typedef struct listNode
{
	int data;
	listPointer link;
}listNode;

listPointer first = NULL;

void find(listPointer first, listPointer* x, int data);
void insert(listPointer* first, listPointer x, int data);
void printList(listPointer first);
void delete(listPointer* first, listPointer trail, listPointer x);

int main()
{
	int data;
	listPointer x, trail;

	MALLOC(x, sizeof(listNode));		// 메모리 공간 할당할때 조심.. sizeof(포인터)는 고정 4바이트!
	MALLOC(trail, sizeof(listNode));

	// data input for each node
	FILE* fp;
	if ((fp = fopen("input.txt", "r")) == NULL)
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fscanf(fp, "%d", &data);
	while (!feof(fp))
	{
		find(first, &x, data);
		insert(&first, x, data);
		fscanf(fp, "%d", &data);
	}


	printList(first);
	trail = first;
	x = first->link;
	printf("\nAfter deleting nodes with data less than and equal to 50\n");

	while (x)
	{
		if (x->data <= 50)
		{
			delete(&first, trail, x);
			x = trail->link;
		}
		else
		{
			x = x->link;
			trail = trail->link;
		}
	}

	listPointer deleNode;
	MALLOC(deleNode, sizeof(listNode));
	if (first->data <= 50)
	{
		deleNode = first;
		first = first->link;
		free(deleNode);
	}

	printList(first);

	// 체인의 모든 노드를 삭제한다.
	x = first;
	while (x)
	{
		deleNode = x;
		x = x->link;
		free(deleNode);
	}
	printf("\nCompletely delete the chain!");

	fclose(fp);

	return 0;
}

void find(listPointer first, listPointer* x, int data)
{
	listPointer front;
	MALLOC(front, sizeof(listNode));

	if (first == NULL) // empty list
		*x = NULL;
	else // not empty list
	{
		*x = first;

		if ((first->link == NULL) && (((*x)->data) >= data)) // 노드가 하나이고 제일 앞에 가야할 때..
			*x = NULL;

		while ((*x)->link)
		{
			if (first->data >= data)
			{
				*x = NULL;
				break;
			}
			
			switch (COMPARE(data, (*x)->data))
			{
			case 1:
				front = *x;
				(*x) = (*x)->link;
				if (((*x)->link == NULL) && (data <= (*x)->data))
				{
					*x = front;
					return;
				}
				break;
			case 0:
				return;
			case -1:
				(*x) = front;
				return;
			}

		}

	}

}

void delete(listPointer* first, listPointer trail, listPointer x)
{
	if (trail)
		trail->link = x->link;
	else
		*first = (*first)->link;
	free(x);
}

void insert(listPointer* first, listPointer x, int data)
{
	listPointer newNode = (listPointer)malloc(sizeof(listNode));	// make a New Node
	newNode->data = data;
	newNode->link = NULL;

	if (*first == NULL)
		*first = newNode;
	else
	{
		if (x == NULL)		// 첫 노드 추가
		{
			newNode->link = *first;		// 첫 노드로 추가
			*first = newNode;
		}
		else
		{
			newNode->link = x->link;
			x->link = newNode;
		}
	}
}

void printList(listPointer first)
{
	int count = 0;
	printf("The ordered list contains: \n");
	for (; first; first = first->link)
	{
		if (count == 10)
		{
			printf("\n");
			count = 0;
		}

		printf("%4d", first->data);
		count++;
	}
	printf("\n");
}

