//Ввести целое число и определить, верно ли, что в его записи есть   
 //две одинаковые цифры, стоящие рядом.
#include <stdio.h>
#include <math.h>


int main(void)
{

    int numbers, digit, _digitals, flag = 0;

    scanf("%d", &numbers);
    int length = (int)log10(numbers) + 1;

    for (int i = length; i > 1; i--)
    {
        digit = numbers % 10;
        _digitals = numbers / 10;

        while (_digitals > 0)
        {
            if(digit == _digitals % 10)
            {
                flag = 1;
                break;
            }
            _digitals /= 10;
        }

        numbers /= 10;
    }

    flag == 1 ? printf("YES") : printf("NO");
    return 0;
}
