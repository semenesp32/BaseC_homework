#include <stdio.h>
#include <locale.h>
int a;

int main(void)

{
	//setlocale(LC_ALL, "Rus");
	//printf("Введите трехзначное число:\n");
	scanf("%d",&a);
	int p = (a%10)+((a/10)%10)+((a/100)%10);
	printf("%d", p);
	
	return 0;
}
