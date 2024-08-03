//Составить функцию, которая определяет наибольший общий делитель двух натуральных и привести пример ее использования. int nod(int a, int b)
#include <stdio.h>
int nod(int a, int b)
{
	int t;
	while (b!=0)
	{
		t =b;
		b = a%b;
		a = t;
	}	
	return a;
}

int main(void)

{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", nod(a, b));
	return 0;
}
