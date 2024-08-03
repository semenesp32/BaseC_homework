/*Упаковать строку
Дана строка состоящая из маленьких латинских букв 'a'..'z'. В конце строки точка. 
Необходимо заменить повторяющиеся буквы на <буква><количество повторений>*/

#include <stdio.h>
#include <inttypes.h>
#define SIZE 30

int Input(int len, char arr[])
{
	char input;
	int count = 0;
	while (count < len)
	{
		scanf("%c", &input);
		if (input == '.')
		{
			return count;
			arr[count++] = input;
		}
	}
	return count;
}

void PrintSymbolsCount(int len, char symbols[], int count[])
{
	for (int i = 0; i < len; i++)
	{
		printf("%c%d",symbols[i], count[i]);
		printf("\n");
	}
}

int CountSymbols(int len, char arr[], char symbols[], int count[])
{
	int countSymbol = 1;
	int outCount = 0;
	int i;
	for (i = 0; i < len -1; i++)
			if (arr[i] == arr[i + 1])
		{
			countSymbol++;
		}
		else
		{
			symbols[outCount] = arr[i];
			count[outCount++] = countSymbol;
			countSymbol = 1;
		}
		symbols[outCount] = arr[i];
		count[outCount++] = countSymbol; 
		return outCount;
}
int main()
{
	char buffer[SIZE], symbols[SIZE];
	int count[SIZE];
	int len = Input(SIZE, buffer);
	int lenCount = CountSymbols(len, buffer, symbols,count);
	PrintSymbolsCount(lenCount, symbols, count);
	return 0;
}
