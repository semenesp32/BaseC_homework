#include <stdio.h>
#include <locale.h>
int a, b, c;

int main(void)

{
	//setlocale(LC_ALL, "Rus");
	//printf("Введите три целых числа:\n");
	scanf("%d%d%d",&a, &b, &c);
	
	double r = ((double)a+(double)b+(double)c)/3;
	printf("%.2f", r);
	
	return 0;
}
