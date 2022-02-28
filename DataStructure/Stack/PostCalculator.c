/*	@ 윤성우의 열혈 자료구조(윤성우 저) 참고
	2022-02-26	Saturday
	후위연산식을 통해 연산을 진행하기 위한 코드
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
		ch = exp[i]; // 글자 추출

		if (isdigit(ch)) // 숫자
			SPush(&stack, ch - '0'); // 문자 하나를 정수로 바꾸는 방법
		else // 문자
		{
			int pop1 = SPop(&stack); // 처음 pop된 것 : 두 번째 연산자
			int pop2 = SPop(&stack); // 두번째 pop된 것 : 첫 번째 연산자
			int result = 0; // 연산 결과

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