/*
*	2022-02-26 Saturday : ���� ��ȭ(����)
*	���� ������� ���� ��������� ��ȯ��Ű�� ���� �ڵ�
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

int GetOpPrech(char op) // �������� �켱������ ���ڷ� �ٲ�
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

int WhoPrecOp(char op1, char op2) // �����ڳ��� �켱 ���� ��
{
	int pre1 = GetOpPrech(op1);
	int pre2 = GetOpPrech(op2);

	if (pre1 == -1 || pre2 == -1) // +,-,*,/�� �ƴ� �ٸ� �����ڴ� ����
	{
		printf("There is no such operation!");
		exit(-1);
	}

	if (pre1 > pre2) { // op1�� ���� ������ ����
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
	int idx = 0; // index���� ������Ű�� ���� ����
	char ch, pop;
	int len = strlen(exp);
	char* chstr = (char*)malloc(len + 1); // ������ \0 ���� +1 ����� ����

	/* �޸��� ����(��)�� ���ϴ� ũ�⸸ŭ Ư�� ������ �����ϴ� �Լ�
	   #include <string.h>	*/
	memset(chstr, 0, sizeof(char) * len + 1);
	StackInit(&stack);

	for (int i = 0; i < len; i++)
	{
		ch = exp[i];

		if (isdigit(ch)) // �ǿ�����
			chstr[idx++] = ch;
		else // �������� ���
		{
			switch (ch)
			{
			case '(':
				SPush(&stack, ch);
				break;

			case ')': // ) �����鼭 ������ ���ÿ� �׾Ƶ� �� ( ���������� ����
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
					chstr[idx++] = SPop(&stack); // ������� �ʰ� ������ �����ڰ� �켱������ ���� ��..
					printf("check\n");
				}

				SPush(&stack, ch);
				break;
			}

		}
	}

	while (!SIsEmpty(&stack)) // stack�� �����ִ� �� ��� �̵�
		chstr[idx++] = SPop(&stack);

	
	/* 
	*	sizeof�� strlen ���� �ľ�
	*	sizeof(exp) = 8 �� ���� exp�� �����ͷμ� 64bit ��Ű���Ŀ��� 8����Ʈ�� ������ ����
	*	printf("%d %d\n", strlen(exp), strlen(chstr));
	*	printf("%d %d\n", sizeof(exp), sizeof(chstr));
	*/
	
	strcpy(exp,chstr);


	free(chstr);
}