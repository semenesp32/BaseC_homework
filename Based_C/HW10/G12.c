/*Разобрать на слова
В файле input.txt дано предложение требуется разобрать его на отдельные слова. 
Напечатать каждое слово на отдельной строке в файл output.txt.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");
    
    char c;
    _Bool flag = 1;

    while((c = fgetc(input)) != EOF)
    {
        if(c == ' ' && flag == 0)
        {
            flag = 1;
            fputc('\n', output);
        }
        else if((c >= 'a' && c <= 'z') || (c >= 'A' &&  c <= 'Z'))
        {
            flag = 0;
            fputc(c,output);
        }
    } 
    fclose(input);
    fclose(output);
    return 0;
}

