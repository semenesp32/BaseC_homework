/*Hello name
В файле input.txt в одной строке фамилию, имя и отчество. Сформировать файл приветствие output.txt, где останутся имя и фамилия
*/
#include <stdio.h>
#define STRLEN 101
int main(void)
{
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    char name[STRLEN] = {'\0'};
    char surname[STRLEN] = {'\0'};

    fscanf(input, "%s%s", surname, name);
    fclose(input);

    fprintf(output, "Hello, %s %s!", name, surname);
    fclose(output);
    return 0;
}

