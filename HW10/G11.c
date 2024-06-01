/*Заканчивается на a
В файле input.txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'. 
Ответ записать в файл output.txt.
*/
#include <stdio.h>
#define STRLEN 10001

int InputString(FILE *input, char str[])
{
    int i = 0;
    char c = 0;
    while((c = fgetc(input)) != EOF)
    {
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ' '))
        {
            str[i++] = c;
        }
    }
    str[i] = '\0';
    return i;
}

int main(void)
{
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");
  
    char str[STRLEN];
    int str_len = 0, count = 0;

    str_len = InputString(input, str);
    fclose(input);

    printf("%s\n", str);
    for(int i = 0; i < str_len;)
    {

        while(i < str_len && str[i++] != ' ');
        if(i < str_len && str[i - 2] == 'a')
        {
            count++;
        }
        else if(i == str_len && str[i-1] == 'a')
        {
            count++;
        }
    }
    fprintf(output, "%d", count);
    fclose(output);
    return 0;
}

