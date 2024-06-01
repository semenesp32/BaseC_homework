/*Количество букв
В файле input.txt считать символьную строку, не более 10 000 символов. 
Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. Учитывать только английские буквы. 
Результат записать в файл output.txt.
*/
#include <stdio.h>
#include <string.h>
#define str_width 10001

int main(void)
{
	int count_small_letter = 0;
	int count_large_letter = 0;
	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");
	if (input == NULL || output == NULL)
	{
		printf("Open_Error\n");
		return 1;
	}
	
	char string[str_width];
	if (fgets(string, sizeof(string), input) !=NULL)
	{
		int _length = strlen(string);
		if (_length > 0 && string[_length - 1] == '\n')
		{
			string[_length - 1]= '\0';
			_length--;
		}
		for (int i = 0; i < _length; i++)
		{
			if (string[i]>= 'a' && string[i] <= 'z')
			{
				count_small_letter++;
			}
			if (string[i]>= 'A' && string[i] <= 'Z')
			{
				count_large_letter++;
			}
		}
		printf("%d %d", count_small_letter, count_large_letter);
		fprintf(output, "%d %d", count_small_letter, count_large_letter);
	}
	fclose(input);
	fclose(output);
	return 0;
}

