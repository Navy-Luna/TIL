// 2020110249 윤주영
// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

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

	FILE* output = fopen("output2.txt", "w");

	/* times for n=0, 10, ... , 100, 200, ... , 1000 */
	printf("     n     repetition     times\n");
	fprintf(output, "     n     repetition     times\n");

	for (n = 0; n <= 2000; n += step)
	{	/* get time for size n*/
		long repetitions = 0;
		clock_t start = clock();
		do
		{
			repetitions++;

			/* initialize with worst-case data */
			for (i = 0; i < n; i++)
				a[i] = n - i;

			sort(a, n);
		} while (clock() - start < 1000);
		/* repeat until enough time has elapsed */
		
		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		duration /= repetitions;

		printf("%6d   %9d     %f\n", n, repetitions, duration);
		fprintf(output, "%6d   %9d     %f\n", n, repetitions,duration);

		if (n == 100) step = 100;
	}

	fclose(output);

	return 0;
}