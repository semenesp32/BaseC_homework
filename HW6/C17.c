//Составить логическую функцию, которая определяет, верно ли, что в заданном числе сумма цифр равна произведению.
//int is_happy_number(int n)
#include <stdio.h>
int is_happy_number(int n)
{
	int sum = 0, p;
	while(n != 0)
	{    
		sum = sum + n%10;
		p = p * n%10; 
        n= n / 10;
	}
	return (sum == p)? printf("YES"):printf("NO");
}

int main(void)

{
	int n;
	scanf("%d", &n);
	is_happy_number(n);
	return 0;
}
