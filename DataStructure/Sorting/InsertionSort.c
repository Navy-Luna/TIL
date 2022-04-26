// 2022.04.26 YJY
// ��������(insertion Sort) ������ ���� �ڵ� : ��κ��� ���ĵ� ������ �� �����ϴ� -> O(n^2)

#include <stdio.h>

void InserSort(int arr[], int n)
{
	int i, j;
	int insData;
	
	/* 0���� ���ĵ� ���¶� �����ϰ� ���� */
	for (i = 1; i < n; i++)
	{
		insData = arr[i];   // ���� ����� insData�� ����

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j];    // �� ��� �� ĭ �ڷ� �б�
			else
				break;   // ���� ��ġ ã������ Ż��!
		}

		arr[j + 1] = insData;  // ã�� ��ġ�� ���� ��� ����!
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