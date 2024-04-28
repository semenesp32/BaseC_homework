//Составить функцию, которая преобразует текущий символ цифры в число. 
//Написать программу считающую сумму цифр в тексте. int digit_to_num(char c)
#include <stdio.h>
int digit_to_num(char c)
{
	int sum = 0;
	do
    {
        if(c >= '0' && c <= '9')
        {
            sum += c - '0';
        }
    }
    while((c = getchar()) != '\n' && c != '.');
    return printf("%d", sum);
}

int main(void)

{
	char n;
	scanf("%c", &n);
	digit_to_num(n);
	return 0;
}
