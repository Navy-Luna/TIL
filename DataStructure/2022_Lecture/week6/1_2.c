// 2020110249 윤주영
// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

#define _CRT_SECURE_NO_WARNINGS
#define MAX_EXPR_SIZE 80
#define MAX_STACK_SIZE 80

#include <stdio.h>
#include <stdlib.h>

char expr[MAX_EXPR_SIZE]; // input expression

typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;
void push(precedence element);
precedence pop();
void postfix(void);
precedence getToken(char* symbol, int* n);
void printToken(precedence element);


int isp[] = { 0,19,12,12,13,13,13,0 };
int icp[] = { 20,19,12,12,13,13,13,0 };

precedence stack[MAX_STACK_SIZE];
top = -1;

FILE* fout;


int main(void)
{
	FILE* fp;
	fout = fopen("output.txt", "w");
	
	int i = 0;

	if ((fp = fopen("input2.txt", "r")) == NULL)
	{
		fprintf(stderr, "Cannot open the file.");
		exit(EXIT_FAILURE);
	}

	fscanf(fp, "%c ", &expr[i++]);
	while (!feof(fp))
		fscanf(fp, "%c ", &expr[i++]);

	printf("<<<<<<<< infix to postfix >>>>>>>>\n");
	printf("infix expression : %s\n", expr);
	printf("postfix expression : ");
	postfix();

	fclose(fout);

	return 0;
}


void push(precedence element)
{
	if (top == MAX_STACK_SIZE - 1)
		printf("Stack is full!");

	stack[++top] = element;
}

precedence pop()
{
	if (top == -1)
		printf("Stack is empty!");

	return stack[top--];
}



void postfix(void)
{

	char symbol;
	precedence token;
	int n = 0;
	top = 0;
	stack[0] = eos;
	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
	{
		if (token == operand)
		{
			printf("%c", symbol);
			fprintf(fout, "%c", symbol);
		}
		else if (token == rparen)
		{
			while (stack[top] != lparen)
				printToken(pop());
			pop();
		}
		else
		{
			while (isp[stack[top]] >= icp[token])
				printToken(pop());
			push(token);
		}
	}
	
	while ((token = pop()) != eos)
		printToken(token);

	printf("\n");

}

void printToken(precedence element)
{


	if (element == plus)
	{
		printf("%c",'+');
		fprintf(fout, "%c", '+');
	}
	else if (element == minus)
	{
		printf("%c", '-');
		fprintf(fout, "%c", '-');
	}
	else if (element == times)
	{
		printf("%c", '*');
		fprintf(fout, "%c", '*');
	}
	else if (element == divide)
	{
		printf("%c", '/');
		fprintf(fout, "%c", '/');
	}
	else if (element == mod)
	{
		printf("%c", '%');
		fprintf(fout, "%c", '%');
	}
	else
	{
		// eos
	}

}

precedence getToken(char* symbol, int* n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;
	}


}




