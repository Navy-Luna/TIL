// 2022.04.26 YJY
// ��������(Merge Sort)�� �����ϱ� ���� �ڵ�

#include <stdio.h>
#include <stdlib.h>

/* ���ĵ� �� �迭�� �����ϴ� �Լ� */
void MergeTwoArea(int arr[], int left, int mid, int right)
{
	// ������ ������ �� ������ ù ��° ��ġ������ ���
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	// ���� �� ����� ���� �迭 sortArr�� ���� �Ҵ�
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sIdx = left;

	// fldx�� mid�� ������ �պκ� �迭�� �Ǿհ� �ǵ�
	// rldx�� right�� ������ �޺κ� �迭�� �Ǿհ� �ǵ�
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
	// �ٸ��迭�� �����ؼ� �Űܵа� �ٽ� ������
	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		// �߰� ������ ����Ѵ�.
		mid = (left + right) / 2;

		// �ѷ� ������ ������ �����Ѵ�.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		// ���ĵ� �� �迭�� �����Ѵ�.
		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void)
{
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	int i;

	// �迭 arr�� ��ü ���� ���� 
	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < 7; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}