//сколько раз встречается максимум
#include <stdio.h>


int n;
int max, current;
int count =0;

int main(void)
{
	scanf("%d", &n);
	scanf("%d", &max);
	current = max;
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &current);
		if (current > max)
		{
			max = current;
			count = 1;
		}else if (current==max)
			{	
				count++;
			}
	}
		
	printf("%d\n", count);
	return 0;
}

