/*Последний номер символа
В файле input.txt дана строка из 1000 символов. 
Показать номера символов, совпадающих с последним символом строки. 
Результат записать в файл output.txt
*/
#include <stdio.h>
#define line_width 1000
int main(void)
{
	signed char c;
	int count =0;
	int pos = 0;
	char line[line_width];
	FILE *f;
	f = fopen("input.txt", "r");//открыли файл на чтение
	while (((c=fgetc(f))!=EOF)&&(c !='\n'))
	{
		line[count++] = c;
	}
	line[count] ='\0';
	fclose(f);
	f = fopen("output.txt", "w");
	for (int i = 0; i < count-1; i++)
	{
		if (line[i] == line[count - 1])
		{
			pos = i;
			fprintf(f, "%d ", pos);
		}
		
	}
	//fprintf(f, " %d", count);
	fclose(f);
	return 0;
}

