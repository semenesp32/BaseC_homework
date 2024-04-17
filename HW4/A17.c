//Ввести номер месяца и вывести название времени года.
#include <stdio.h>
int a;

int main(void)

{
	scanf("%d",&a);
	if((a==12)||(a==1)||(a==2))
	{
		printf("winter");
	}
	if((a>=3)&&(a<=5))
	{
		printf("spring");
	}
	if((a>5)&&(a<=8))
	{
		printf("summer");
	}
	if((a>8)&&(a<=11)){
		printf("autumn");
	}
	
	return 0;
}
