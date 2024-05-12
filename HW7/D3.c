//Дано целое не отрицательное число N. Выведите все его цифры по одной, в обратном порядке, разделяя их пробелами или новыми строками. 
//Составить рекурсивную функцию.
#include <stdio.h>
void recursion(int n)
{
	if(n < 10)
    {
        printf("%d ", n);
    }
    else
    {
        printf("%d ", n % 10);
        recursion(n / 10);
    }
	
}


int main(void)

{
	int n;
	scanf("%d", &n);
	recursion(n);
	return 0;
}
