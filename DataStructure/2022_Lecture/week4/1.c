/* 2020110249 ���ֿ�
   ������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_TERMS 100
#define COMPARE(x,y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0: 1)

#include <stdio.h>
#include <stdlib.h>

void inputPoly(char* fname, int* startA, int* finishA, int* startB, int* finishB);
void printPoly(int start, int finish);
void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD);
void attach(float coefficient, int exponent);

typedef struct
{
	float coef;
	int exp;
}term;

term terms[MAX_TERMS];
int avail = 0;

int main(void)
{
	int startA, finishA, startB, finishB, startD, finishD;
	char* name = "input.txt";

	printf("two input polynomials ...\n");
	inputPoly(name, &startA, &finishA, &startB, &finishB);

	printf("A(x) = ");
	printPoly(startA, finishA);

	printf("B(x) = ");
	printPoly(startB, finishB);

	printf("\nthe result of polynomial addition ...\n");
	printf("D(x) = A(x) + B(x) = \n");

	padd(startA, finishA, startB, finishB, &startD, &finishD);

	printPoly(startD, finishD);

}

void inputPoly(char* fname, int* startA, int* finishA, int* startB, int* finishB)
{

	FILE* fp = fopen(fname, "r");
	
	*startA = 0;
	fscanf(fp, "%d", finishA);
	*startB = *finishA;
	*finishA = *finishA - 1;
	fscanf(fp, "%d", finishB);
	*finishB = *finishA + *finishB;

	for (int i = *startA; i <= *finishA; i++) // ���׽� A �б�
	{
		fscanf(fp, "%f", &terms[i].coef);
		fscanf(fp, "%d", &terms[i].exp);
	}

	for (int i = *startB; i <= *finishB; i++) // ���׽� B �б�
	{
		fscanf(fp, "%f", &terms[i].coef);
		fscanf(fp, "%d", &terms[i].exp);
	}

	avail = *finishB + 1;


	fclose(fp);
}

void printPoly(int start, int finish) // �ϳ��� ���׽��� ���޹޾� ȭ������ ���
{
		for (int i = start; i < finish; i++)
		{
			printf("%.1fx^%d + ", terms[i].coef, terms[i].exp);
		}

	
		if (terms[finish].exp == 0)
			printf("%.1f\n", terms[finish].coef);
		else
			printf("%.1f^%d\n", terms[finish].coef, terms[finish].exp);

}

void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD)
{
	// add A(x) and B(x) to obtain D(x)
	float coefficient;
	*startD = avail;

	while (startA <= finishA && startB <= finishB)
	{

		switch (COMPARE(terms[startA].exp, terms[startB].exp))
		{
		case -1: // a expo < b expo
			attach(terms[startB].coef, terms[startB].exp);
			startB++;
			break;
		case 1: // a expo > b expo
			attach(terms[startA].coef, terms[startA].exp);
			startA++;
			break;
		case 0: // a expo = b expo
			coefficient = terms[startA].coef + terms[startB].coef;
			if (coefficient)
			{
				attach(coefficient, terms[startA].exp);
			}
			startA++;
			startB++;
		}
	}

	// add in remaining terms of A(x)
	for (; startA <= finishA; startA++)
		attach(terms[startA].coef, terms[startA].exp);
	for (; startB <= finishB; startB++)
		attach(terms[startB].coef, terms[startB].exp);

	*finishD = avail - 1;
}

void attach(float coefficient, int exponent)
{ // add a new term to the polynomial
	if (avail >= MAX_TERMS)
	{
		fprintf(stderr, "Too many terms in the polynomial\n");
		exit(EXIT_FAILURE);
	}

	terms[avail].coef = coefficient;
	terms[avail++].exp = exponent;
}
