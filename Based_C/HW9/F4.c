/*Цифры в строке
Написать только одну функцию. Всю программу отправлять не надо. 
Вывести в порядке возрастания цифры, входящие в строку. Цифра - количество. 
Функция должно строго соответствовать прототипу:void print_digit(char s[])*/

#include <stdio.h>
#include <inttypes.h>
#define SIZE 1000

void print_digit(char s[])
{
    char ch;
    int count =0;
    while ((ch = getchar())!= '\n' && (ch >= '0' && ch <= '9'))
    {
        s[count++] = ch - '0';
    }

    char digit[10] = {0};

    for(int i = 0; i < count; i++)
    {
        digit[s[i]]++;
    }

    for(int i = 0; i <= 9; i++)
    {
        if(digit[i] != 0)
        {
            printf("%d %d\n", i, digit[i]);
        }
    }




}

int main(void)
{
    char s[SIZE];
    print_digit(s);
    return 0;
}

