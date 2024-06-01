/*Заменить a на b
В файле input.txt дана символьная строка не более 1000 символов.  
Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в output.txt.
*/
#include <stdio.h>
#include <string.h>
#define str_width 1001

int main(void)
{
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
			switch (string[i])
			{
				case 'a':
					string[i] = 'b';
					break;
				case 'b':
					string[i] = 'a';
					break;
				case 'A':
					string[i] = 'B';
					break;
				case 'B':
					string[i] = 'A';
					break;
			}
			printf("%c", (char) string[i]);
			fprintf(output, "%c", (char) string[i]);
		}
	}
	fclose(input);
	fclose(output);
	return 0;
}

