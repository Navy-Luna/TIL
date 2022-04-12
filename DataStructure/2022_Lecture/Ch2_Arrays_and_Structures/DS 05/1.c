// 2022.04.12 : Polynomial addition
// �� ���׽��� ������ ���Ϸκ��� �޾� ���׽� ���ϱ⸦ ������ �� ����� ����ϴ� ���α׷�

#define _CRT_SECURE_NO_WARNINGS
#define MAX_TERMS 100
#define COMPARE(x,y) (((x)>(y)) ? 1 : ((x)==(y)) ? 0 : -1)

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float coef;
	int exp;
}term;

term terms[MAX_TERMS];
int avail = 0;

void padd(int startA, int finishA, int startB, int finishB, int* startC, int* finishC);
void attach(float coefficient, int exponent);
void printPoly(int start, int finish);

int main()
{
	// �� ���� ���۰� ���� ����� ����
	int startA=0, finishA, startB, finishB, startC, finishC;

	// ���Ϸκ��� ������ �о�帮��(���� ����)
	FILE* fp = fopen("input.txt", "r");

	fscanf(fp,"%d", &startB);
	finishA = startB - 1;
	fscanf(fp,"%d", &finishB);
	finishB = finishB + finishA;

	avail = finishB + 1;

	// ���׽� ���� �ޱ�
	for (int i = 0; i <= finishA; i++)
		fscanf(fp,"%f %d", &terms[i].coef, &terms[i].exp);
	for (int i = startB; i <= finishB; i++)
		fscanf(fp,"%f %d", &terms[i].coef, &terms[i].exp);

	// ���׽� ���ϱ�
	padd(startA, finishA, startB, finishB, &startC, &finishC);
	
	printf("two input polynomials ...\n");
	printf("A(x) = ");
	printPoly(startA, finishA);
	printf("B(x) = ");
	printPoly(startB, finishB);

	printf("\nthe result of polynomial addition ...\n");
	printf("C(x) = A(x) + B(x) =\n");
	printPoly(startC, finishC);

	fclose(fp);
	return 0;
}

/* �� ���׽��� ������ �����ϴ� �Լ� : O(m+n) */
void padd(int startA, int finishA, int startB, int finishB, int* startC, int* finishC)
{
	*startC = avail;
	float sum = 0;

	while (startA <= finishA && startB <= finishB)
	{
		switch (COMPARE(terms[startA].exp, terms[startB].exp))
		{
		case 1: // a�� ���� > b�� ����
			attach(terms[startA].coef, terms[startA].exp);
			startA++;
			break;
		case 0: // a�� ���� = b�� ����
			sum = terms[startA].coef + terms[startB].coef;
			if (sum)
				attach(sum, terms[startA].exp);
			startA++; startB++;
			break;
		case -1: // a�� ���� < b�� ����
			attach(terms[startB].coef, terms[startB].exp);
			startB++;
			break;
		}
	}
	/* ���� ���׽ĵ� �о�� */
	for (; startA <= finishA; startA++) attach(terms[startA].coef, terms[startA].exp);
	for (; startB <= finishB; startB++) attach(terms[startB].coef, terms[startB].exp);

	*finishC = avail - 1;
}

/* ���ϱ��� ������� �迭�� �����ϴ� �Լ� */
void attach(float coefficient, int exponent)
{
	if (avail >= MAX_TERMS)
	{ // ��밡���� ������ �Ѿ ���
		fprintf(stderr, "Insufficient Memory!");
		exit(EXIT_FAILURE);
	}
	terms[avail].coef = coefficient;
	terms[avail++].exp = exponent;
}

/* �ϳ��� ���׽��� �޾� ����ϴ� �Լ� */
void printPoly(int start, int finish)
{
	for (int i = start; i <= finish; i++)
	{
		if (terms[i].exp == 0)
			printf("  %+.1f", terms[i].coef);
		else
			printf("  %+.1fx^%d", terms[i].coef, terms[i].exp);
	}
	printf("\n");
}