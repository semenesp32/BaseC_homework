/*Самое длинное слово
В файле input.txt дана строка слов, разделенных пробелами. 
Найти самое длинное слово и вывести его в файл output.txt. Случай, когда самых длинных слов может быть несколько, не обрабатывать.
*/
#include <stdio.h>
#define STRLEN 1001
int InputString(FILE *inp,char* str);
int main(void)
{
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");
   
    char str[STRLEN];
    int str_len = 0, max1 = 0, max2 = 0, pos1 = 0, tmp = 0;
    str_len = InputString(input,str);

    for(int i=0; i < str_len;)
    {
        while(i < str_len && str[i++] != ' ')
        {
            tmp++;
        }
        if(tmp > max1)
        {
            max1 = tmp;
            pos1 = i - tmp-1;
            if(pos1 < 0)
            {
                pos1 = 0;
            }
        }
        else if(tmp > max2)
        {
            max2 = tmp;
        }
        tmp=0;
    }
    if(max1 > max2)
    {
        for(int i = pos1; i < pos1 + max1; i++)
        {
            fputc(str[i], output);
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
//функция чтения строки из файла
int InputString(FILE *input, char* str)
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
