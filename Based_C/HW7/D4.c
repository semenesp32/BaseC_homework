//Дано натуральное число N. Выведите все его цифры по одной, в прямом порядке, разделяя их пробелами или новыми строками. 
//Необходимо реализовать рекурсивную функцию. void print_num(int num)
#include <stdio.h>
int rev_num = 0;
int reverce_num(int num)
{
	if (num > 0)
	{
		rev_num = rev_num * 10 + num % 10;
		reverce_num(num/10);
		//printf("%d ", rev_num);
	}
	return rev_num;
}

/*void print_num(int num)	
{
	if(rev_num < 10)
    {
        printf("%d ", rev_num);
    }
    else
    {
        printf("%d ", rev_num % 10);
        print_num(rev_num / 10);
    }
}*/

int main(void)

{
	int n;
	scanf("%d", &n);
	reverce_num(n);
	printf("%d ", n);
	return 0;
}
