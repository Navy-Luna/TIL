// 2020110249 ���ֿ�
// ������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include "selectionSort.h"
#define MAX_SIZE 2001

void main(void)
{
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;
	clock_t start;

	FILE* output = fopen("output1.txt", "w");


	/* times for n=0, 10, ... , 100, 200, ... , 1000 */
	printf("     n     times\n");
	fprintf(output,"     n     times\n");

	for (n = 0; n <= 2000; n += step)
	{	/* get time for size n*/
		/* initialize with worst-case data */
		for (i = 0; i < n; i++)
			a[i] = n - i;

		start = clock();

		sort(a, n);
		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		printf("%6d     %f\n", n, duration);
		fprintf(output, "%6d     %f\n", n, duration);

		if (n == 100) step = 100;
	}

	fclose(output);

	return 0;
}