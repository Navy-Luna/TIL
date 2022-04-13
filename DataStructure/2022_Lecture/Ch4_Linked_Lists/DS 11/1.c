// 2022.04.13 Polynomial
// chain을 이용하여 polynomial addition 프로그램을 작성하라.

#define _CRT_SECURE_NO_WARNINGS
#define MALLOC(p,s){\
	if(!((p)=malloc(s))) {\
		printf("Allocating is failed!\n");\
	}\
}

#define COMPARE(x,y) (((x)>(y)) ? 1 : ((x)==(y)) ? 0 : -1)

#include <stdio.h>
#include <stdlib.h>


typedef struct polyNode* polyPointer;
typedef struct polyNode
{
	int coef;
	int expon;
	polyPointer link;
}polyNode;

polyPointer a = NULL, b = NULL , c = NULL;

void attach(int coefficient, int exponent, polyPointer* ptr);
void inputPoly(char* filename, polyPointer* p);
void printList(polyPointer first); // 체인 first를 순회하며 다항식 정보를 출력한다.
polyPointer padd(polyPointer a, polyPointer b);
void erase(polyPointer* ptr);

int main()
{
	inputPoly("a.txt", &a);
	inputPoly("b.txt", &b);


	printf("a :	");
	printList(a);
	printf("b :	");
	printList(b);


	c = padd(a, b);
	printf("c :	");
	printList(c);

	erase(&a);
	erase(&b);
	erase(&c);
}

void erase(polyPointer* ptr)
{
	polyPointer temp;
	while (*ptr)
	{
		temp = *ptr;
		*ptr = (*ptr)->link;
		free(temp);
	}
}

void inputPoly(char* filename, polyPointer *p)
{
	FILE* fp = fopen(filename, "r");
	char type;
	int cof;
	int exp;
	polyPointer heads = NULL;
	polyPointer newNode;
	
	
	fscanf(fp, "%c", &type);

	if (type == 'd') // 내림차순일 경우
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d %d", &cof, &exp);
			MALLOC(newNode, sizeof(polyNode)); // 새로운 데이터를 담을 노드
			newNode->coef = cof;
			newNode->expon = exp;
			newNode->link = NULL;

			
			if (*p == NULL)
			{ // 아예 빈 리스트이면
				*p = newNode;
				heads = newNode;
			}
			else
			{
				(*p)->link = newNode;
				*p = (*p)->link;
			}
		}
		*p = heads;
	}
	else // 오름차순일 경우
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d %d", &cof, &exp);
			MALLOC(newNode, sizeof(polyNode)); // 새로운 데이터를 담을 노드
			newNode->coef = cof;
			newNode->expon = exp;
			newNode->link = NULL;

			if (*p == NULL) // 아예 빈 리스트이면
				*p = newNode;
			else
			{
				newNode->link = *p;
				*p = newNode;
			}
		}
	}

}

void attach(int coefficient, int exponent, polyPointer* ptr)
{
	polyPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->coef = coefficient;
	temp->expon = exponent;
	temp->link = NULL;

	(*ptr)->link = temp;
	(*ptr) = temp;
}

void printList(polyPointer first) // 체인 first를 순회하며 다항식 정보를 출력한다.
{
	for (; first; first = first->link)
	{
		if (first->coef > 0)
		{
			int exp = first->expon;

			if (exp != 0) // 차수가 0이 아니면
				printf("	+%dx^%d", first->coef, first->expon);
			else
				printf("	+%d", first->coef);
		}
		else
		{
			int exp = first->expon;

			if (exp != 0) // 차수가 0이 아니면
				printf("	%dx^%d", first->coef, first->expon);
			else
				printf("	%d", first->coef);
		}
	}
	printf("\n");
}

polyPointer padd(polyPointer a, polyPointer b)
{
	polyPointer c, rear, temp;
	int sum;
	MALLOC(rear, sizeof(*rear));
	c = rear;
	while (a && b)
	{
		switch (COMPARE(a->expon, b->expon))
		{
		case -1:
			attach(b->coef, b->expon, &rear);
			b = b->link;
			break;
		case 0:
			sum = a->coef + b->coef;
			if (sum) attach(sum, a->expon, &rear);
			a = a->link; b = b->link; break;
		case 1:
			attach(a->coef, a->expon, &rear);
			a = a->link;
		}
	}
	for (; a; a = a->link) attach(a->coef, a->expon, &rear);
	for (; b; b = b->link) attach(b->coef, b->expon, &rear);
	rear->link = NULL;
	temp = c; c = c->link; free(temp);
	return c;
}