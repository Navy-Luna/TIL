// Binary Search 구현을 위한 코드
/*
  i. 배열의 처음과 끝을 first, last 그리고 middle = (first+last)/2로 정의   
  ii. 찾으려는 숫자와 list[middle]의 숫자크기를 비교   
  iii. 만약 searchnum == list[middle]이면 종료, searchnum이 더 크면 first = middle+1로 바꾸고 재탐색
	   작으면 last = middle-1로 바꾸고 재탐색(오름차순일때..)
*/

#include <stdio.h>
#include <stdlib.h>

#define COMPARE(x,y) ( ((x)>(y)) ? 1 : ((x)==(y)) ? 0 : -1 )


int main()
{
	int searchnum = 3;
	int searchnum2 = 20;
	int list[10] = { 1,3,4,5,6,7,8,9,10,17 };

	int result = binsearch(list, searchnum, 0, 9);
	int result2 = binsearch(list, searchnum2, 0, 9);

	if (result == -1)
		printf("Cannot find number...\n");
	else
		printf("Number is found in index = %d\n", result);

	if (result2 == -1)
		printf("Cannot find number...\n");
	else
		printf("Number is found in index = %d", result2);

	return 0;
}

int binsearch(int list[], int searchnum, int left, int right)
{
	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		switch (COMPARE(searchnum, list[middle]))
		{
		case 1: // 재귀적 호출을 사용할 경우 binsearch(list, searchnum, middle+1, right);
			left = middle + 1;	// 찾으려는 수가 middle의 오른쪽편에 있음
			break;
		case 0:
			return middle; // 찾으면 해당 인덱스 반환
		case -1: // 재귀적 호출을 사용할 경우 binsearch(list, searchnum, left, middle-1);
			right = middle - 1;
			break;
		}
	}

	return -1; // 찾지 못한 경우


}

