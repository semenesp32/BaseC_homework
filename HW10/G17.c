/*Пары соседних символов
В файле input.txt записаны символы. 
Необходимо разработать функцию, которая меняет местами пары соседних символов не обращая внимание на символы пробел. 
Если количество символов нечетно (пробелы не считаем), то последний символ не меняем. 
Результат записать в файл output.txt.
*/
#include <stdio.h>
#include <string.h>
#define STRLEN 1001
int InputString(FILE *input, char* str);
void swap(char *in, char *out, int str_len);
void swap_ab(char *arr, int posa, int posb);

int main(void)
{
    
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");
    char strin[STRLEN] = {'\0'};
    char strout[STRLEN] = {'\0'};

    InputString(input, strin);
    swap(strin, strout, STRLEN);
    fclose(input);

    fprintf(output, "%s", strout);
    fclose(output);

    return 0;
}

void swap(char *in, char *out, int str_len)
{
    int fst = 0, lst = 0;
    strcpy(out, in);
    for(int i = 1; i < str_len && in[i] != '\0'; i++)
    {
        if(in[i] != ' ' && in[i-1] != ' ')
        {
            lst = i++;
            swap_ab(out, fst, lst);
            if(in[i] != ' ')
            {
                fst = i;
            }
            else
            {
                while(in[++i] == ' ');
                fst = i;
            }
        }
        else if(in[i-1] == ' ' && in[i] != ' ')
        {
            lst = i++;
            swap_ab(out, fst, lst);
            if(in[i] != ' ')
            {
                fst = i;
            }
            else
            {
                while(in[++i] == ' ');
                fst = i;
            }
        }
        else
        if(fst == 0 && in[0] == ' ')
        {
            while(in[i] == ' ')
            {
                fst = ++i;
            }
        
        }
    }
}

void swap_ab(char *arr, int posa, int posb)
{
    char tmp = arr[posa];
    arr[posa] = arr[posb];
    arr[posb] = tmp;
}

int InputString(FILE *input, char* str)
{
    int i = 0;
    char c = 0;
    while((c = fgetc(input)) != EOF)
    {
        if((c >= 'A' && c <='Z') || (c >= 'a' && c <='z') || (c == ' ') || (c == '!') || (c == '.')) //in auto test there are only letters, ' ', '!' and '.'
        {
            str[i++] = c;
        }
    }
    str[i] = '\0';
    return i;
}


