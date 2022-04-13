// 2022.04.13 : Singly linked Circular list with header node 
// 헤더노드를 가진 단일연결 환형리스트를 이용한 다항식 더하기 프로그램

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

/* 헤더노드를 가진 다항식 (단일연결 환형리스트) */
polyPointer a = NULL, b = NULL, c = NULL;
/* 다항식 a와 b에 대한 last 포인터 */
polyPointer lastA, lastB;
/* 노드풀 (체인) */
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
	polyPointer headerA = getNode(); // 헤더 포인터 생성
	polyPointer headerB = getNode();

	headerA->expon = -1;
	headerB->expon = -1;
	headerA->link = headerA;
	headerB->link = headerB; // 처음 헤더는 자기 자신을 가리킨다.

	a = headerA; b = headerB; // 각각은 헤더를 가리킴!
	lastA = headerA; lastB = headerB;

	/* 다항식 만들기 */
	inputPolyCL("a.txt", &headerA, &lastA);
	inputPolyCL("b.txt", &headerB, &lastB);

	printf("   a : ");
	printCList(headerA);
	printf("   b : ");
	printCList(headerB);


	/* 다항식 C 만들기 */
	c = cpadd(a, b);
	printf("   c : ");
	printCList(c);

	/* 다항식 a,b,c를 avail에 반환한다. */
	cerase(&a);
	cerase(&b);
	cerase(&c);

	/* avail를 삭제한다. */
	erase(&avail);

	return 0;
}

/* ptr이 가리키는 체인을 삭제하는 함수이다. */
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

/* ptr이 가리키는 체인을 삭제하는 함수 */
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

/* 헤더노드를 가진 단일 연결 환형리스트 구현 */
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
	int cof, exp; // 파일에 입력된 계수와 차수를 받는다.

	fscanf(fp, "%c", &type);
	if (type == 'd')
	{
		while (!(feof(fp)))
		{
			fscanf(fp, "%d %d", &cof, &exp);
			newNode = getNode();
			newNode->coef = cof;
			newNode->expon = exp;

			insertLastCL(last, newNode); // 마지막에 추가
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

			insertFrontCL(last, newNode); // 마지막에 추가
		}
	}

}

/* 체인으로 구현된 노드풀로부터 노드를 하나 가져온다. */
polyPointer getNode(void)
{
	polyPointer node;
	if (avail) // avail 머리 꼭다리 반환
	{
		node = avail;
		avail = avail->link;
	}
	else // 비어있는 경우
		MALLOC(node, sizeof(*node));
	return node;
}

/* 헤더노드를 가진 단일연결 환형리스트의 마지막에 노드를 추가한다. */
void insertLastCL(polyPointer* last, polyPointer node)
{

	if (!(*last)) // 리스트가 비어있는 경우
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

/* 헤더노드를 가진 단일연결 환형리스트의 첫 노드로 추가한다. */
void insertFrontCL(polyPointer* last, polyPointer node)
{
	if (!(*last)) // 리스트가 비어있는 경우
	{
		*last = node;
		node->link = node;
	}
	else
	{  // 헤더 다음에 추가를 해야함

		node->link = (*last)->link->link;
		(*last)->link->link = node;

		if (*last == a) // 마지막이 곧 헤더라면..
			*last = (*last)->link;
	}
}

/* 헤더노드를 가진 단일연결 환형리스트로 표현된 다항식을 출력한다. */
void printCList(polyPointer header)
{

	header = header->link; // 헤더파일 다음으로 넘어감

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

/* circular list 끼리의 합을 구하는 문제 */
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

/* circular list 맨 뒤에 새로운 노드를 붙이는 함수 */
void attach(int cof, int expo, polyPointer* ptr)
{
	polyPointer temp;
	temp = getNode();
	temp->coef = cof;
	temp->expon = expo;

	insertLastCL(ptr, temp);
}