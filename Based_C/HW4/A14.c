//Дано трехзначное число, напечатать максимальную цифру
#include <stdio.h>
int a, n1, n2, n3, max;

int main(void)

{
	scanf("%d",&a);
	n1 = (a%10);
	n2 = (a/10)%10;
	n3 = (a/100)%10;
	max = n1 > n2 ? n1:n2;
	max = max > n3 ? max:n3; 
  
	printf("%d", max);
	
	return 0;
}
