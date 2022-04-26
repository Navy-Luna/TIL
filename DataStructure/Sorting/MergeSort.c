// 2022.04.26 YJY
// 병합정렬(Merge Sort)를 구현하기 위한 코드

#include <stdio.h>
#include <stdlib.h>

/* 정렬된 두 배열을 병합하는 함수 */
void MergeTwoArea(int arr[], int left, int mid, int right)
{
	// 각각은 병합할 두 영역의 첫 번째 위치정보가 담김
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	// 병합 한 결과를 담을 배열 sortArr의 동적 할당
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sIdx = left;

	// fldx와 mid는 정렬할 앞부분 배열의 맨앞과 맨뒤
	// rldx와 right는 정렬할 뒷부분 배열의 맨앞과 맨뒤
	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if (fIdx > mid)
	{
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else
	{
		for (i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	// 다른배열에 정렬해서 옮겨둔거 다시 가져옴
	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		// 중간 지점을 계산한다.
		mid = (left + right) / 2;

		// 둘로 나눠서 각각을 정렬한다.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		// 정렬된 두 배열을 병합한다.
		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void)
{
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	int i;

	// 배열 arr의 전체 영역 정렬 
	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < 7; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}