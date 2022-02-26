/*
*	2022-02-26 Saturday : 스택 심화(계산기)
*	중위 연산식을 후위 연산식으로 변환시키기 위한 코드
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

int GetOpPrech(char op) // 연산자의 우선순위를 숫자로 바꿈
{

	switch (op)
	{
	case '*':
	case '/':
		return 7;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}

	return -1;
}

int WhoPrecOp(char op1, char op2) // 연산자끼리 우선 순위 비교
{
	int pre1 = GetOpPrech(op1);
	int pre2 = GetOpPrech(op2);

	if (pre1 == -1 || pre2 == -1) // +,-,*,/가 아닌 다른 연산자는 무시
	{
		printf("There is no such operation!");
		exit(-1);
	}

	if (pre1 > pre2) { // op1의 연산 순위가 높음
		return 1;
	}
	else if (pre1 < pre2)
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[])
{
	Stack stack;
	int idx = 0; // index값을 증가시키며 값을 참조
	char ch, pop;
	int len = strlen(exp);
	char* chstr = (char*)malloc(len + 1); // 마지막 \0 위해 +1 까먹지 말기

	/* 메모리의 내용(값)을 원하는 크기만큼 특정 값으로 세팅하는 함수
	   #include <string.h>	*/
	memset(chstr, 0, sizeof(char) * len + 1);
	StackInit(&stack);

	for (int i = 0; i < len; i++)
	{
		ch = exp[i];

		if (isdigit(ch)) // 피연산자
			chstr[idx++] = ch;
		else // 연산자인 경우
		{
			switch (ch)
			{
			case '(':
				SPush(&stack, ch);
				break;

			case ')': // ) 만나면서 이전에 스택에 쌓아둔 것 ( 만날때까지 빼냄
				while (1)
				{
					pop = SPop(&stack);
					if (pop == '(')
						break;
					chstr[idx++] = pop;
				}
				break;

			case '+':case'-':
			case '*':case'/':
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), ch) >= 0) {
					chstr[idx++] = SPop(&stack); // 비어있지 않고 스택의 연산자가 우선순위가 높은 한..
					printf("check\n");
				}

				SPush(&stack, ch);
				break;
			}

		}
	}

	while (!SIsEmpty(&stack)) // stack에 남아있는 것 모두 이동
		chstr[idx++] = SPop(&stack);

	
	/* 
	*	sizeof과 strlen 차이 파악
	*	sizeof(exp) = 8 인 것은 exp가 포인터로서 64bit 아키텍쳐에서 8바이트를 가지기 때문
	*	printf("%d %d\n", strlen(exp), strlen(chstr));
	*	printf("%d %d\n", sizeof(exp), sizeof(chstr));
	*/
	
	strcpy(exp,chstr);


	free(chstr);
}