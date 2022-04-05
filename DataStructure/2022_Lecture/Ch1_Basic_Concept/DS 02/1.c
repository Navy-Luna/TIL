// Chap1_Basic_Concept : Performace Analysis and Measurment
// sum과 rsum을 이용하여 스택에 할당되는 공간과 변수들을 디버깅으로 확인하여 S(p)=c+Sp(I)를 계산해보자

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int list[], int n) // 고정적으로 c=20 / Ssum(n) = 0 -> 따라서 Sp=20
{
	int tempsum = 0;
	int i;
	for (i = 0; i < n; i++)
		tempsum += list[i];

	return tempsum;
}

int rsum(int list[], int n) // 고정적으로는 12 / Ssum(n) = 12*n -> 따라서 Sp=12n+12
{
	if (n) return rsum(list, n - 1) + list[n - 1];
	return 0;
}

int main(void)
{
	int list[20];
	int num;
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++)
		list[i] = i + 1;
	
	printf("%d\n",sum(list, num));
	printf("%d",rsum(list, num));

	return 0;
}