//Упаковать массив
/*В программе реализована структура данных:
  struct puck_array
  {
    uint32_t array;//поле для хранения упакованного массива из 0 и 1
    uint32_t count0:8;//счетчик нулей в array
    uint32_t count1:8;//счетчик единиц в array
  }
  Необходимо реализовать только одну функцию, которая упаковывает переданный ей массив из 32-ух элементов из 0 и 1 в
  указанную структуру данных. Функция должна строго соответствовать прототипу: void array2struct(int [], struct pack_array *)*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct pack_array
{
    uint32_t array;//поле для хранения упакованного массива из 0 и 1
    uint32_t count0:8;//счетчик нулей в array
    uint32_t count1:8;//счетчик единиц в array
};

void array2struct(uint32_t *, struct pack_array *);

int main()
{
    uint32_t input_array[32];
    struct pack_array result;
    
    printf("Input array:\n");
    for (size_t i = 0; i < 32; ++i)
    {
        scanf("%u", &input_array[i]);
    }
    array2struct(input_array, &result);

    return 0;
}

void array2struct(uint32_t *arr, struct pack_array *result)
{
    result->array = 0;
    result->count0 = 0;
    result->count1 = 0;

    for (size_t i = 0; i < 32; ++i)
    {
        if (arr[i] == 0)
        {
			result->array = result->array << 1;
            result->count0++;
        }
        else if (arr[i] == 1)
        {
			result->array = (result->array << 1) | 1;
            result->count1++;
        }
    }

    printf("array = %08X\n", result->array);
    printf("count0 = %u\n", result->count0);
    printf("count1 = %u\n", result->count1);
}
