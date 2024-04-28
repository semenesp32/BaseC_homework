//Составить функцию, которая переводит латинскую строчную букву в заглавную. И показать пример ее использования.
#include <stdio.h>
char function_up(char a)
{
	char result;
	if ((a >= 'a')&&(a <= 'z'))
	{
		result = a - 32;
	}
	else
	{
		result = a;
	}
	return result;
	
}
int main(void)

{
	char a;
	for (;;)
	{
		scanf("%c", &a);
		if (a == '.')
			break;
		printf("%c", function_up(a));
	}
	return 0;
}
