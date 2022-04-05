/*
	Chap1_Basic_Concept : C Programming Basic
	
	다음과 같은 프로그램을 두가지 버전으로 작성하기
	1) 사용자로부터 난수생성 개수(n)을 입력받는다.
	2) 정수 난수를 n개 발생시켜 1차원 배열에 저장한다.
	3) 1차원 배열에 대해 "선택정렬(selection sort)"를 수행한다.
	4) 사용자로부터 임의의 정수를 입력받는다
	5) 입력받은 정수가 배열에 있는지 이진탐색(binary Search)를 수행하여 그 결과를 출력한다.
*/

////////////////////////////////////
// 함수를 이용한 compare과 swap 구현
////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);
void sort(int list[], int n);
int compare(int x, int y);
int search(int list[], int searchnum, int start, int last);

int main()
{
	int ary[100];

	int searchnum;
	int n; // 입력받을 난수 갯수

	printf("Enter the number of numbers to generate: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) // 0~999까지의 숫자를 받는다.
		ary[i] = rand() % 1000;

	for (int i = 0; i < n; i++) // 생성된 배열 출력
		printf("%d ", ary[i]);
	printf("\n\n");

	sort(ary, n); // 선택 정렬

	printf("Sorted array:\n"); // 정렬된 배열 출력
	for (int i = 0; i < n; i++)
		printf("%d ", ary[i]);
	printf("\n");

	printf("\nEnter the number to search : ");
	scanf("%d", &searchnum); // 찾을 숫자 입력

	if (search(ary, searchnum, 0, n - 1) != -1)
		printf("The search number is present in ary[%d]", search(ary, searchnum, 0, n - 1));
	else
		printf("The search number is not present");

	return 0;
}

void sort(int list[], int n) // 선택정렬( 배열과 배열의 원소 갯수 )
{
	int min;

	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (list[min] > list[j])
				min = j;
		}
		swap(&list[min], &list[i]); // 주솟값 넣는것 조심하자..! 매크로 함수는 그냥 바뀜!!!!!!!!!!!!
	}
}


void swap(int* a, int* b)
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

int compare(int x, int y) // 숫자 2개를 비교하는 함수
{
	if (x > y) return 1;
	else if (x == y) return 0;
	else return -1;
}

int search(int list[], int searchnum, int start, int last) // 이진 탐색
{

	while (start <= last)
	{
		int mid = (start + last) / 2;
		switch (compare(searchnum, list[mid]))
		{
		case 0:
			return mid;
		case 1:
			start = mid + 1;
			break;
		case -1:
			last = mid - 1;
			break;
		}
	}
	return -1;
}