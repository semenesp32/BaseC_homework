//Не пара
/*Преподаватели Geek Brains создали набор, содержащий N (1<=N<=1000000) натуральных чисел, не превосходящих 1000000.
  Известно, что ровно одно число в этом наборе встречается один раз, остальные - ровно по два раза. Помогите им найти это число.
  Входные данные: в первой входной строке вводится число N, затем по одному числу в строке вводятся N  натуральных чисел,
  не превосходящих 2 000 000 000. Выходные данные: ваша программа должна определить число, встречающееся один раз и вывести его
  на экран.*/
#include <stdio.h>
#include <inttypes.h>

int n;
int k;
int res =0;

int main(void)
{
	scanf("%u", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%u", &k);
		res^=k;
	}
	
	printf("%u\n", res);
	return 0;
}
