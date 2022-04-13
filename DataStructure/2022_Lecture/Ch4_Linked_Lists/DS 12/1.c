// 2022.04.13 : Singly linked Circular list with header node 
// �����带 ���� ���Ͽ��� ȯ������Ʈ�� �̿��� ���׽� ���ϱ� ���α׷�

#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC(p,s){\
	if(!((p) = malloc(s))) \
	{\
		printf("alloced memory fail!"); \
		exit(-1); \
	}\
}

#define COMPARE(x,y) (((x)>(y)) ? 1 : ((x)==(y)) ? 0 : -1)

typedef struct polyNode* polyPointer;
typedef struct polyNode
{
	int coef;
	int expon;
	polyPointer link;
}polyNode;

/* �����带 ���� ���׽� (���Ͽ��� ȯ������Ʈ) */
polyPointer a = NULL, b = NULL, c = NULL;
/* ���׽� a�� b�� ���� last ������ */
polyPointer lastA, lastB;
/* ���Ǯ (ü��) */
polyPointer avail = NULL;

polyPointer getNode(void);
void insertLastCL(polyPointer* last, polyPointer node);
void insertFrontCL(polyPointer* last, polyPointer node);
void inputPolyCL(char* filename, polyPointer* header, polyPointer* last);
void printCList(polyPointer header);
void attach(int cof, int expo, polyPointer* ptr);
polyPointer cpadd(polyPointer a, polyPointer b);
void cerase(polyPointer* ptr);
void erase(polyPointer* ptr);


int main()
{
	polyPointer headerA = getNode(); // ��� ������ ����
	polyPointer headerB = getNode();

	headerA->expon = -1;
	headerB->expon = -1;
	headerA->link = headerA;
	headerB->link = headerB; // ó�� ����� �ڱ� �ڽ��� ����Ų��.

	a = headerA; b = headerB; // ������ ����� ����Ŵ!
	lastA = headerA; lastB = headerB;

	/* ���׽� ����� */
	inputPolyCL("a.txt", &headerA, &lastA);
	inputPolyCL("b.txt", &headerB, &lastB);

	printf("   a : ");
	printCList(headerA);
	printf("   b : ");
	printCList(headerB);


	/* ���׽� C ����� */
	c = cpadd(a, b);
	printf("   c : ");
	printCList(c);

	/* ���׽� a,b,c�� avail�� ��ȯ�Ѵ�. */
	cerase(&a);
	cerase(&b);
	cerase(&c);

	/* avail�� �����Ѵ�. */
	erase(&avail);

	return 0;
}

/* ptr�� ����Ű�� ü���� �����ϴ� �Լ��̴�. */
void cerase(polyPointer* ptr)
{	// erase the circular list pointed to by ptr
	polyPointer temp;
	if (*ptr)
	{
		temp = (*ptr)->link;
		(*ptr)->link = avail;
		avail = temp;
		*ptr = NULL;
	}

}

/* ptr�� ����Ű�� ü���� �����ϴ� �Լ� */
void erase(polyPointer* ptr)
{
	polyPointer delNode;
	while (*ptr)
	{
		delNode = *ptr;
		*ptr = (*ptr)->link;
		free(delNode);
	}
}

/* �����带 ���� ���� ���� ȯ������Ʈ ���� */
void inputPolyCL(char* filename, polyPointer* header, polyPointer* last)
{
	if (!(*header))
	{
		printf("header is empty!");
		exit(-1);
	}

	polyPointer newNode;
	FILE* fp = fopen(filename, "r");
	char type;
	int cof, exp; // ���Ͽ� �Էµ� ����� ������ �޴´�.

	fscanf(fp, "%c", &type);
	if (type == 'd')
	{
		while (!(feof(fp)))
		{
			fscanf(fp, "%d %d", &cof, &exp);
			newNode = getNode();
			newNode->coef = cof;
			newNode->expon = exp;

			insertLastCL(last, newNode); // �������� �߰�
		}

	}
	else // type a
	{
		while (!(feof(fp)))
		{
			fscanf(fp, "%d %d", &cof, &exp);
			newNode = getNode();
			newNode->coef = cof;
			newNode->expon = exp;

			insertFrontCL(last, newNode); // �������� �߰�
		}
	}

}

/* ü������ ������ ���Ǯ�κ��� ��带 �ϳ� �����´�. */
polyPointer getNode(void)
{
	polyPointer node;
	if (avail) // avail �Ӹ� ���ٸ� ��ȯ
	{
		node = avail;
		avail = avail->link;
	}
	else // ����ִ� ���
		MALLOC(node, sizeof(*node));
	return node;
}

/* �����带 ���� ���Ͽ��� ȯ������Ʈ�� �������� ��带 �߰��Ѵ�. */
void insertLastCL(polyPointer* last, polyPointer node)
{

	if (!(*last)) // ����Ʈ�� ����ִ� ���
	{
		*last = node;
		node->link = node;
	}
	else
	{
		node->link = (*last)->link;
		(*last)->link = node;
		*last = node;
	}

}

/* �����带 ���� ���Ͽ��� ȯ������Ʈ�� ù ���� �߰��Ѵ�. */
void insertFrontCL(polyPointer* last, polyPointer node)
{
	if (!(*last)) // ����Ʈ�� ����ִ� ���
	{
		*last = node;
		node->link = node;
	}
	else
	{  // ��� ������ �߰��� �ؾ���

		node->link = (*last)->link->link;
		(*last)->link->link = node;

		if (*last == a) // �������� �� ������..
			*last = (*last)->link;
	}
}

/* �����带 ���� ���Ͽ��� ȯ������Ʈ�� ǥ���� ���׽��� ����Ѵ�. */
void printCList(polyPointer header)
{

	header = header->link; // ������� �������� �Ѿ

	for (; header; header = header->link)
	{
		if (header->expon == -1)
			break;

		if (header->expon != 0)
			printf("   %+dx^%d", header->coef, header->expon);
		else
			printf("   %+d", header->coef);
	}
	printf("\n");
}

/* circular list ������ ���� ���ϴ� ���� */
polyPointer cpadd(polyPointer a, polyPointer b)
{
	polyPointer startA, c, lastC;
	int sum, done = FALSE;
	startA = a;		/* record start of a */
	a = a->link;	/* skip header node for a and b */
	b = b->link;
	c = getNode();
	c->expon = -1; lastC = c;
	do {
		switch (COMPARE(a->expon, b->expon))
		{
		case -1: // a < b
			attach(b->coef, b->expon, &lastC);
			b = b->link;
			break;
		case 0: // a = b
			if (startA == a) done = TRUE;
			else
			{
				sum = a->coef + b->coef;
				if (sum) attach(sum, a->expon, &lastC);
				a = a->link; b = b->link;
			}
			break;
		case 1: // a > b
			attach(a->coef, a->expon, &lastC);
			a = a->link;
		}


	} while (!done);
	lastC->link = c;
	return c;
}

/* circular list �� �ڿ� ���ο� ��带 ���̴� �Լ� */
void attach(int cof, int expo, polyPointer* ptr)
{
	polyPointer temp;
	temp = getNode();
	temp->coef = cof;
	temp->expon = expo;

	insertLastCL(ptr, temp);
}