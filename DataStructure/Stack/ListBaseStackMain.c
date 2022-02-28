*	@ 윤성우의 열혈 자료구조(윤성우 저) 참고
	2022-02-26	Saturday
	구현된 연결리스트 기반 Stack을 사용해보는 main
*/
/*
	ListBaseStack.h, ListBaseStack.c
*/

#include <stdio.h>
#include "ListBaseStack.h"


int main(void)
{


	// Stack 생성 및 초기화
	Stack stack;
	StackInit(&stack);

	// 데이터 push
	SPush(&stack, 10);
	SPush(&stack, 20);
	SPush(&stack, 30);
	
	// 데이터 peek
	printf("%d\n", SPeek(&stack));


	// 데이터 pop
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	/* 예상 출력값
	* 30
	* 30 20 10
	*/

	return 0;
}