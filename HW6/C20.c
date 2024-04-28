//Проверить строку состоящую из скобок "(" и ")" на корректность.
#include <stdio.h>
#include <stdio.h>
#define MAX_LENGTH 1002


int main(void)
{
    char c;
    c = getchar();

    int flag = 0;
    int count =  0;
    int first_character = 0;

    if(c == '(')
    {
        first_character = 1;
    }

    do
    {
        if(c == '(')
        {
            flag++;
            count++;
        }
        if(c == ')')
        {
            flag--;
            count++;
        }
    }
    while((c = getchar()) != '\n' && c != '.');

    ((flag == 0) && (count <  MAX_LENGTH)) && (first_character == 1) ? printf("YES\n") : printf("NO\n");


    return 0;
}
