//Ввести три числа и определить, верно ли, что они вводились в порядке возрастания.
#include <stdio.h>
int a, b, c, min, mean, max;

int main(void)

{
	scanf("%d%d%d",&a,&b,&c);
	if((a>b)&&(a>c))
	{
		max = a;
	}
	if(((a>b)&&(a<c))||((a>c)&&(a<b)))
	{
		mean = a;
	}
	if((a<b)&&(a<c))
	{
		min = a;
	}
	if((b>a)&&(b>c))
	{
		max = b;
	}
	if(((b>a)&&(b<c))||((b>c)&&(b<a)))
	{
		mean = b;
	}
	if ((b<a)&&(b<c))
	{
		min = b;
	}
	if((c>a)&&(c>b))
	{
		max = c;
	}
	if(((c>a)&&(c<b))||((c>b)&&(c<a)))
	{
		mean = c;
	}
	if ((c<a)&&(c<b))
	{
		min = c;
	}
	if((min==a)&&(mean==b)&&(max==c)&&(a!=b)&&(a!=c)&&(b!=c))
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	
	return 0;
}
