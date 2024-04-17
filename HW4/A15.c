//Определить уравнение прямой по координатам двух точек. Уравнение вида y=k*x+b
#include <stdio.h>
int X1,Y1, X2, Y2;

int main(void)

{
	scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
	float k = ((double)Y1-(double)Y2)/((double)X1-(double)X2);
	float b = (double)Y1 - (double)k*(double)X1;
 
  
	printf("%.2f %.2f", k, b);
	
	return 0;
}
