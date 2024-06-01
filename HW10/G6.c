/*Проверка на палиндром
В файле input.txt символьная строка не более 1000 символов. 
Необходимо проверить, является ли она палиндромом (палиндром читается одинаково в обоих направлениях). 
Реализовать логическую функцию is_palindrom(str) и записать ответ в файл output.txt.
*/
#include <stdio.h>
#define STRLEN 10001
int InputString(FILE *input,char* str);
int is_palindrom(char *str,int len);

int main(void)
{
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");
    char strin[STRLEN]= {'\0'};
    int len = InputString(input, strin);
    fprintf(output,"%s",is_palindrom(strin, len) ? "YES":"NO");
    fclose(input);
    fclose(output);

    return 0;
}
//функция чтения строки из файла
int InputString(FILE *input,char* str)
{
    int i = 0;
    char c = 0;
    while((c = fgetc(input)) != EOF)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <='Z'))
        {
            str[i++] = c;
        }
    }
    str[i] = '\0';
    return i;
}
//функция проверки на палиндром
int is_palindrom(char *str,int len)
{
   _Bool flag=1;
   for(int i = 0; i + i < len && flag; i++)
   {
     if(str[i]!=str[len-i-1])
      flag=0;
   }
   return flag;
}

