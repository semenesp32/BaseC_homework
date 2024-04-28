//Составить функцию логическую функцию, которая определяет, верно ли, что число простое. 
//Используя функцию решить задачу.int is_prime(int n)
#include <stdio.h>

int is_prime(int n)
{
	int flag = 1;

    if (n > 1)
    {
        for(int i = 2; i < n; i++)
        {
            if(n % i == 0)
            {
                flag = 0;
                break;
            }
        }
    }
    else
    {
        flag = 0;
    }

    return flag == 0 ? printf("NO") : printf("YES");   	
}

int main()
{
	int n;
	scanf("%d",&n);   
	is_prime (n);
}
