//Составить функцию логическую функцию, которая определяет, верно ли, что сумма его цифр – четное число. 
//Используя эту функцию решить задачу.
#include <stdio.h>
int sum_digit(int n)
{
	int sum;
	while(n != 0)
	{    
		sum = sum +n%10;
        n= n / 10;
	}
	return (sum%2 == 0)? printf("YES"):printf("NO");
}

int main(void)

{
	int n;
	scanf("%d", &n);
	sum_digit(n);
	return 0;
}
