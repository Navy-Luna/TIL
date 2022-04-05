// Selection Sort(선택정렬) 구현을 위한 소스 코드
/*
  i. 배열의 원소 중 최솟값을 찾아 맨 앞에 나둔다.   
  ii. 두번째 원소를 기준으로 뒤의 배열 요소들과 크기를 비교한다. 만약 두번째 배열 요소보다 작은 수가 나오면 switch   
  iii. 기준이 되는 위치가 n-1에 도달했을때 종료..
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 101
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t) )

void sort(int list[], int n); // Selection_Sort

int main(void)
{
	int i, n;
	int list[MAX_SIZE];
	
	printf("Enter the number of numbers to generate: ");
	scanf("%d", &n);

	if (n<1 || n > MAX_SIZE) // 아무것도 입력X 혹은 최대 입력개수를 넘으면
	{
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < n; i++)
	{
		list[i] = rand() % 1000; // 랜덤함수 rand()의 표현범위 0~32767
	}

	sort(list, n);
	printf("Sorted Array : \n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}

void sort(int list[], int n) // Selection_Sort
{
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++)
	{
		min = i;		// 인덱스로 활용
		for (j = i + 1; j < n; j++)
			if (list[min] > list[j]) // 정렬되지 않은 배열 중에 제일 작은 것을 찾아낸다.
				min = j;
		SWAP(list[min], list[i], temp); // 정렬되지 않은 배열의 제일 처음과 그 뒤의 제일 작은것을 바꿈
	}
}