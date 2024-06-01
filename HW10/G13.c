/*Изменить расширение
В файле input.txt записан полный адрес файла (возможно, без расширения). 
Необходимо изменить его расширение на ".html" и записать результат в файл output.txt.
*/
#include <stdio.h>
#define STRLEN 1001

int InputString(FILE *input,char* str);
void change_to_html(char *addr, int len);

int main(void)
{
 
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");
    char addr[STRLEN] = {'\0'};
    int len = 0;

    len = InputString(input,addr);
    change_to_html(addr, len);
    fprintf(output, "%s", addr);

    fclose(input);
    fclose(output);

    return 0;
}
//функция замены расширения на ".html"
void change_to_html(char *addr, int len)
{
    char html[] = ".html";
    int dot_index = -1;
    for(int i = len-1; i >= 0 && addr[i] != '/'; i--)
    {
        if(addr[i] == '.')
        {
            dot_index = i;
            i = -1;
        }
    }

    if(dot_index == -1)
    {
        dot_index = len;
    }

    for(int i=0; i < 6; i++)
    {
        addr[dot_index+i] = html[i];
    }
}
//функция чтения строки из файла
int InputString(FILE *input, char* str)
{
    int i = 0;
    char c = 0;
    while((c = fgetc(input)) != EOF)
    {
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == '/') || (c == '.')) 
        {
            str[i++] = c;
        }
    }
    str[i] = '\0';
    return i;
}
