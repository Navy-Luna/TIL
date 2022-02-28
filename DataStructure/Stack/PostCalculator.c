/*	@ �������� ���� �ڷᱸ��(������ ��) ����
	2022-02-26	Saturday
	����������� ���� ������ �����ϱ� ���� �ڵ�
*/

#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
	Stack stack;
	StackInit(&stack);
	
	int idx = 0;
	int len = (int)strlen(exp);
	char ch;

	for (int i = 0; i < len; i++)
	{
		ch = exp[i]; // ���� ����

		if (isdigit(ch)) // ����
			SPush(&stack, ch - '0'); // ���� �ϳ��� ������ �ٲٴ� ���
		else // ����
		{
			int pop1 = SPop(&stack); // ó�� pop�� �� : �� ��° ������
			int pop2 = SPop(&stack); // �ι�° pop�� �� : ù ��° ������
			int result = 0; // ���� ���

			switch (ch)
			{
			case '*':
				result = pop1 * pop2;
				break;
			case '/':
				result = pop2 / pop1;
				break;
			case '+':
				result = pop1 + pop2;
				break;
			case '-':
				result = pop2 - pop1;
				break;
			}

			SPush(&stack, result);
		}
	}
	return SPop(&stack);
}