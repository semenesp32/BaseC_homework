//Составить программу для вычисления НОД с помощью алгоритма Евклида. 
//Даны два натуральных числа. Найти наибольший общий делитель.
#include <stdio.h>


int main()
{
	
int a, b, nod;
scanf("%d %d", &a, &b);

	while (b!=0)
	{
		nod = b;
		b = a % b;
		a = nod;
		
	}
	printf("%d", nod);
	return 0;
}
