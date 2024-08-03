//циклический сдвиг
#include <stdio.h>
#include <inttypes.h>

int32_t n;
int k;

int main(void)
{
	scanf("%u%u", &n, &k);
	printf("%u\n", (n>>k)|(n << (32-k)));
	return 0;
}

