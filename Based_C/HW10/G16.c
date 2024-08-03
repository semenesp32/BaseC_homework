/*Ling заменить на Cao
В файле input.txt дано предложение. Необходимо заменить все имена «Ling» на «Cao» и записать результат в файл output.txt.
*/
#include <stdio.h>
#include <string.h>
#define STRLEN 1001
int main(void)
{
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");
  
    char buffer[5] = {'\0'};
    char c = 0;
    int i = 0;

    while((c = fgetc(input)) != EOF)
    {
        if(c == 'g')
        {
            if(((ftell(input)) > 3) && (!fseek(input, -4, SEEK_CUR)))
            {
                do
                {
                    c = fgetc(input);
                    buffer[i++] = c;
                }
                while(i < 4);
                i = 0;
                if(!strcmp(buffer,"Ling"))
                {
                    if(!fseek(output, -3, SEEK_CUR))
                    {
                        fputs("Cao", output);
                    }
                }
                else
                {
                    fputc(c, output);
                }
            }
            else
            {
                fputc(c, output);
            }
        }
        else
        {
            fputc(c, output);
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}


