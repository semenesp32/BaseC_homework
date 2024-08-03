//Проверить число на простоту.
#include <stdio.h>


int main()
{
	int n;
	scanf("%d",&n); 
	int flag = 1;

    if (n > 1)
    {
        for(int i = 2; i < n; i++)
        {
            if(n % i == 0)
            {
                flag = 0;
                break;
            }
        }
    }
    else
    {
        flag = 0;
    }

    return flag == 0 ? printf("NO") : printf("YES");
}
