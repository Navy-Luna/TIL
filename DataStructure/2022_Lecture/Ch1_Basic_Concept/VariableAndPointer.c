// Chapter1_Basic_Concept�� Self Study�� ���� C����
// Copyright By JYJ

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*	(1) ������ �������� Ȱ��01
		int i, *pi;
		pi = &i; // pi�� i�� �ּڰ��� ����.
		i = 10; *pi = 11;

		if (pi == NULL) // if(!pi)�� ��ġ�� ǥ�� -> pi�� Null�̸� �����ε� !�� ���� ������ �ٲ�
			printf("Fail to allocate memory!\n");

		printf("%d %d", i, *pi);
	*/


	/*	(2) ������ �������� Ȱ��02
		int i, * pi;
		float f, * pf;
		pi = (int*)malloc(sizeof(int)); // malloc�� ����Ͽ� ���ο� �޸� ������ �Ҵ� - �������� ���̴� i��� ������ ���� Ȱ��
		pf = (float*)malloc(sizeof(float));

		*pi = 1024;
		*pf = 3.14;

		printf("an integer = %d, a float = %f\n", *pi, *pf);
		free(pi); // �Ҵ� �� ����� ���� �޸𸮴� �����ؾ߸� �� - �޸� ���� ���� ���ؼ�
		free(pf);
	*/


	/*	(3) �޸� ���� �Ҵ�� ���ÿ� �Ҵ� �������� Ȯ��01
		int* pi;
		float* pf;

		if ((pi = (int*)malloc(sizeof(int))) == NULL || (pf = (float*)malloc(sizeof(float))) == NULL)
		{// ���� �ٸ��� ���� if ���� ���� ������ �Ҵ��ϸ鼭 �Ҵ��� �����ߴ��� Ȯ���ϱ� ����

			fprintf(stderr, "Insufficient memory"); // fprintf�� ���鼭 stderr�� ����ϸ� �ֿܼ� ���� string�� ���!
			exit(EXIT_FAILURE);
		}
		printf("memory is successfully allocated!");
	*/


	/*	(4) �޸� ���� �Ҵ�� ���ÿ� �Ҵ� �������� Ȯ��02
		int* pi;
		float* pf;

		if (!(pi = malloc(sizeof(int))) || !(pf = malloc(sizeof(float))))
		{ // ���� == Null���� ���̴� type casting�� ���� �ʿ� ����! pi�� �ڷ����� ���缭 �ڵ����� type casting��
			fprintf(stderr, "Insufficient memory!");
			exit(EXIT_FAILURE);
		}
	*/


	/*	(5) �޸� ���� �Ҵ�� ���ÿ� �Ҵ� �������� Ȯ��03 - ��ũ�� �Լ� �̿�(���� ���/�ڷ��� ������� ��밡���ؼ� ����..02�� ����)
		#define MALLOC(p,s) \				// p�� s�� ���� �����Ϳ� �Ҵ� size
			if(!((p) = malloc(s))) \		// ��ũ�� �Լ� �������� ������ ���� \ �ʿ�
			{ \
				fprintf(stderr, "Insufficient Error!); \
				exit(EXIT_FAILURE); \
			}

		MALLOC(pi,sizeof(int));
		MALLOC(pf,sizeof(float));			// �Լ�ȣ��X : ��ó���Ⱑ �̸� �������� �Ŀ� "ġȯ"�� �ϴ°��� : ���� ������ ����..
	*/


	return 0;
}
