/*Удалить повторяющиеся символы
В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов. 
Требуется удалить из нее повторяющиеся символы и все пробелы. 
Результат записать в файл output.txt.
*/
#include <stdio.h>
#include <string.h>
#define STRLEN 1001
int main(void)
{
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");

    char str[STRLEN];
    int str_len = 0, count = 0;
    fscanf(input, "%[0-9a-zA-Z ,.?!:;\"\"\'\']s", str);
    str_len = strlen(str);
    for(int i = 0; i < str_len; i++)
    {
        for(int j = i; j >= 0;j--)
        {
         if(str[j] == str[i])
          {
          count++;
          }
        }
        if(count == 1  && str[i] != ' ')
        {
         fprintf(output, "%c", str[i]);
        }
         count = 0;
    }
    printf("%s",str);
   
    fclose(input);
    fclose(output);
    return 0;
}
