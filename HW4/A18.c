//Ввести два числа. Если первое число больше второго, то программа печатает слово Above. 
//Если первое число меньше второго, то программа печатает слово Less. 
//А если числа равны, программа напечатает сообщение Equal.
#include <stdio.h>
int a, b;

int main(void)

{
	scanf("%d%d",&a, &b);
	if(a>b)
	{
		printf("Above");
	}
	if(a<b)
	{
		printf("Less");
	}
	if (a==b)
	{
		printf("Equal");
	}
	
	return 0;
}
