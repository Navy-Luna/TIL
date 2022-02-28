/*	@ 윤성우의 열혈 자료구조(윤성우 저) 참고
	2022-02-26 Saturday : 스택 심화(계산기)
	중위 연산식을 후위 연산식으로 변환시킨 코드를 확인하기 위한 main
*/
/*
	스택의 활용					: ListBaseStack.h, ListBaseStack.c
	중위식을 후위식으로 변환	: InfixToPostfix.h, InfixToPostifix.c
*/

#include <stdio.h>
#include <string.h>
#include "InfixToPostfix.h"

int main(void)
{

	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);

	printf("%s \n", exp1);
	printf("%s \n", exp2);
	printf("%s \n", exp3);
}