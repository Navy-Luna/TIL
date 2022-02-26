/*
	2022-02-26 Saturday
	중위 표현식을 후위 표현식으로 바꾼 뒤에 연산하기 위한 소스 코드
*/
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h" // ConvToRPNExp 함수의 호출을 위해서 
#include "PostCalculator.h" // EvalRPNExp 함수의 호출을 위해서

int EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	int ret;
	char* expcpy = (char*)malloc(len + 1);		// 문자열 저장공간 마련
	strcpy(expcpy, exp);						// exp를 expcpy에 복사

	ConvToRPNExp(expcpy);						// 후위 표기법의 수식으로 변환
	ret = EvalRPNExp(expcpy);					// 변환된 수식의 계산

	free(expcpy);		// 문자열 저장공간 해제
	return ret;
}

