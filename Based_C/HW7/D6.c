//Дана строка заканчивающаяся символом точка '.' Напечатать строку наоборот. 
//Реализуйте рекурсивную функцию, которая считывает и печатает строку наоборот.void reverse_string()
#include <stdio.h>
void reverse_string(void)
{
	char a;
	scanf("%c", &a);
	if (a != '.')
	{
		reverse_string();
		printf("%c", a);
	}
}


int main(void)

{
	reverse_string();
	return 0;
}
