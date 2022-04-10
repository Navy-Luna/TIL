// 2020110249 윤주영
// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

#include "selectionSort.h"

void sort(int list[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
}