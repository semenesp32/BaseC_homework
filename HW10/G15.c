/*Cao заменить на Ling
В файле input.txt дано предложение. Необходимо заменить все имена «Cao» на «Ling» и записать результат в файл output.txt.
*/
#include <stdio.h>
#include <string.h>
#define STRLEN 1001
int main(void)
{
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");
  
    char buffer[4] = {'\0'};
    char c = 0;
    int i = 0;

    while((c = fgetc(input)) != EOF)
    {
        if(c == 'o')
        {
            if(((ftell(input)) > 2) && (!fseek(input, -3, SEEK_CUR)))
            {
                do
                {
                    c = fgetc(input);
                    buffer[i++] = c;
                }
                while(i < 3);
                i = 0;
                if(!strcmp(buffer,"Cao"))
                {
                    if(!fseek(output, -2, SEEK_CUR))
                    {
                        fputs("Ling", output);
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


