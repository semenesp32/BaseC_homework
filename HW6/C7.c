//Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления.
// N ≥ 0 и 2 ≥ P ≥ 9
#include <stdio.h>


int f_convert(int n, int p);


int main(void)
{
    int n, p;

    scanf("%d %d", &n, &p);
    printf("%d\n", f_convert(n, p));

    return 0;
}


int f_convert(int n, int p)
{
    int digit;
    int place_number = 1;
    int result = 0;

    while(n > 0)
    {
        digit  = n % p;
        result += digit * place_number;
        place_number *= 10;
        n = n/p;
    }

    return result;
}
