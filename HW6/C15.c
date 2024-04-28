//Составить функцию логическую функцию, которая определяет, верно ли, что в заданном числе все цифры стоят по возрастанию. 
//Используя данную функцию решить задачу.int grow_up(int n)
#include <stdio.h>
int grow_up(int a)
{
	int n, n2, flag =0;
	
	while (a!=0)
	{
		n = a%10;
		n2 = (a/10)%10;
		if (n <= n2)
		{
			flag++;
		}
		a/=10;
	}
	return (flag == 0)? printf("YES"):printf("NO");
}

int main(void)

{
	int n;
	scanf("%d", &n);
	grow_up(n);
	return 0;
}
