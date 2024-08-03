/*Удалить пробелы из текста
В файле input.txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы). 
Для решения задачи разработать функцию. 
Результат записать в output.txt.
*/
#include <stdio.h>
#include <string.h>
#define STRLEN 1001
int InputString(FILE *input,char* str);
void delete_spacebar(char *in, char *out,int str_len);

int main(void)
{
    
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");
    char strin[STRLEN] = {'\0'};
    char strout[STRLEN] = {'\0'};

    InputString(input, strin);
    delete_spacebar(strin, strout, STRLEN);
    fclose(input);

    fprintf(output, "%s", strout);
    fclose(output);

    return 0;
}

void delete_spacebar(char *in, char *out,int str_len)
{
    int j = 0;
    for(int i = 0; i < str_len; i++)
    {
        if(i==0 && in[i] == ' ')
        {
            while(in[++i] == ' ');
            out[j++] = in[i];
        }
        else
        if(i > 0 && in[i-1] == ' ' && in[i]!=' ')
        {
            out[j++] = ' ';
            out[j++] = in[i];
        }
        else
        if(in[i] != ' ')
        {
            out[j++] = in[i];
        }
    }
}

int InputString(FILE *input, char* str)
{
    int res = 0;
    res = fscanf(input, "%[a-zA-Z0-9 ,.;:!?-\'\")(]s", str);
    return res;
}

