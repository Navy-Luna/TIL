/*
	Chap1_Basic_Concept : C Programming Basic
	�� ���� ������ malloc�� ���� ���� �Ҵ��� �����϶� : if���� ���� �Ҵ� �׸��� ��ũ�� �Լ��� ���� �Ҵ�
*/
#define MALLOC(p, s) {\
	if(!((p) = malloc(s))){ \
		fprintf(stderr, "Fail to allocate the memory");\
		exit(-1);\
	}\
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	// 1. if ���� ���ÿ� �޸� �Ҵ� ����

	int* pi;
	float* pf;

	if (!(pi = malloc(sizeof(int))) || !(pf = malloc(sizeof(float))))
	{
		fprintf(stderr, "Fail to allocate the memory");
		exit(-1);
	}
	printf("Success!\n");

	*pi = 1024;
	*pf = 3.14;

	printf("an integer = %d, a float = %.2f\n", *pi, *pf);

	free(pi);
	free(pf);

	// 2. ��ũ�� �Լ��� ���� ���� �޸� �Ҵ� ����

	int* pi2;
	float* pf2;
	

	MALLOC(pi2, sizeof(int));
	MALLOC(pf2, sizeof(float));
	printf("Success2!\n");
	*pi2 = 20;
	*pf2 = 4.59;

	printf("an integer = %d, a float = %.2f", *pi2, *pf2);

	free(pi2);
	free(pf2);

	return 0;
}
