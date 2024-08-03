//Найти наименьшее из пяти чисел
#include <stdio.h>
int a, b, c, d, f, min;

int main(void)

{
	scanf("%d%d%d%d%d",&a, &b, &c, &d, &f);
	min = a < b ? a:b;
	min = min < c ? min:c;
	min = min < d ? min:d;
	min = min < f ? min:f;
	printf("%d", min);
	
	return 0;
}
