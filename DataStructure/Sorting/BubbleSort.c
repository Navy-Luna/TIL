// 2022.04.26 YJY
// 버블정렬 구현 코드 -> 비교/이동 : O(n^2)
#include <stdio.h>

/* Bubble Sorting */
void BubbleSort(int arr[], int n)
{ // n is length of array
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < (n-i)-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main()
{
	int arr[4] = { 3,2,4,1 };
	int i;

	BubbleSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	return 0;




	return 0;
}