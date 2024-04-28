//Составить логическую функцию, которая определяет, что текущий символ это цифра. 
//Написать программу считающую количество цифр в тексте. int is_digit(char c)
#include <stdio.h>
int is_digit(char c)
{
	int count = 0;
	do
    {
        if(c >= '0' && c <= '9')
        {
            count ++;
        }
    }
    while((c = getchar()) != '\n' && c != '.');
    return printf("%d", count);
}

int main(void)

{
	char n;
	scanf("%c", &n);
	is_digit(n);
	return 0;
}
