// 2022.04.13 Polynomial
// chain�� �̿��Ͽ� polynomial addition ���α׷��� �ۼ��϶�.

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
void printList(polyPointer first); // ü�� first�� ��ȸ�ϸ� ���׽� ������ ����Ѵ�.
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

	if (type == 'd') // ���������� ���
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d %d", &cof, &exp);
			MALLOC(newNode, sizeof(polyNode)); // ���ο� �����͸� ���� ���
			newNode->coef = cof;
			newNode->expon = exp;
			newNode->link = NULL;

			
			if (*p == NULL)
			{ // �ƿ� �� ����Ʈ�̸�
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
	else // ���������� ���
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d %d", &cof, &exp);
			MALLOC(newNode, sizeof(polyNode)); // ���ο� �����͸� ���� ���
			newNode->coef = cof;
			newNode->expon = exp;
			newNode->link = NULL;

			if (*p == NULL) // �ƿ� �� ����Ʈ�̸�
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

void printList(polyPointer first) // ü�� first�� ��ȸ�ϸ� ���׽� ������ ����Ѵ�.
{
	for (; first; first = first->link)
	{
		if (first->coef > 0)
		{
			int exp = first->expon;

			if (exp != 0) // ������ 0�� �ƴϸ�
				printf("	+%dx^%d", first->coef, first->expon);
			else
				printf("	+%d", first->coef);
		}
		else
		{
			int exp = first->expon;

			if (exp != 0) // ������ 0�� �ƴϸ�
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