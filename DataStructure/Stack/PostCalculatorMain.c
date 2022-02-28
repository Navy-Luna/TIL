/*	@ 윤성우의 열혈 자료구조(윤성우 저) 참고
	2022-02-26	Saturday
	후위연산식을 통해 연산을 진행해보는 main
*/
/*
	스택의 활용					: ListBaseStack.h, ListBaseStack.c
	변환된 후위식을 계산		: PostCalculator.h, PostCalculator.c
*/

#include <stdio.h>
#include "PostCalculator.h"

int main(void)
{
	char postExp1[] = "42*8+";
	char postExp2[] = "123+*4/";

	printf("%s = %d \n", postExp1, EvalRPNExp(postExp1));
	printf("%s = %d \n", postExp2, EvalRPNExp(postExp2));

	return 0;
}