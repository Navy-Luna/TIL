// 2022.04.26 YJY
// 삽입정렬(insertion Sort) 구현을 위한 코드 : 대부분이 정렬된 상태일 때 유리하다 -> O(n^2)

#include <stdio.h>

void InserSort(int arr[], int n)
{
	int i, j;
	int insData;
	
	/* 0까지 정렬된 상태라 가정하고 시작 */
	for (i = 1; i < n; i++)
	{
		insData = arr[i];   // 정렬 대상을 insData에 저장

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j];    // 비교 대상 한 칸 뒤로 밀기
			else
				break;   // 삽입 위치 찾았으니 탈출!
		}

		arr[j + 1] = insData;  // 찾은 위치에 정렬 대상 삽입!
	}
}


int main(void)
{
	int arr[5] = { 5, 3, 2, 4, 1 };
	int i;

	InserSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}