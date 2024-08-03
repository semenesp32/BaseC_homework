//Весы

#include <stdio.h>
#include <inttypes.h>

int count_weights(int mass)
{
	if (mass > 1000000000)
	{
		return -1;
	}
	int count = 0;
	int weight = 1;
	
	while (mass > 0)
	{
		if (mass >= weight)
		{
			mass = mass - weight;
			count++;
		}
		weight *=3;
	}
	return count;
}

int main(void)
{
	int mass;
	scanf("%d", &mass);
	printf("%d\n", count_weights(mass));
	return 0;
}

