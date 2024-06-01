/*Цифры по возрастанию
Написать функцию и программу демонстрирующую работу данной функции. 
Вывести в порядке возрастания цифры, входящие в десятичную запись натурального числа N, не более 1000 цифр. 
Цифра пробел сколько раз данная цифра встречается в числе.*/

#include <stdio.h>
#include <inttypes.h>
#define SIZE 1000

void big_number(int num[])
{
    int count = 0;
    char ch;

    while ((ch = getchar())!= '\n')
    {
        num[count++] = ch - '0';
    }

    int digit[10] = {0};

    for(int i = 0; i < count; i++)
    {
        digit[num[i]]++;
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
    int num[SIZE];
    big_number(num);
    return 0;
}

