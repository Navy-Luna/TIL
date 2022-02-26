/*
	2022-02-26 Saturday
	구현한 배열 기반 Stack을 사용해보는 main 함수 
*/
/*
	ArrayBaseStack.h, ArrayBaseStack.c
*/

#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void)
{
	// Stack의 생성 및 초기화
	Stack stack;
	StackInit(&stack); // Stack 초기화 필수

	// 데이터 넣기 : Put
	SPush(&stack, 1);
	SPush(&stack, 12);
	SPush(&stack, 9);

	// top의 데이터 확인하기 : Peek
	printf("%d\n", SPeek(&stack));

	// 데이터 꺼내기 : Pop
	while (!SIsEmpty(&stack))
	{
		printf("%d ", SPop(&stack));
	}

	/*	예상 출력값 : 출력은 역순 출력됨
		9
		9 12 1
	*/

	return 0;
}