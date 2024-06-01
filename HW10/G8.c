/*Числа в массив
В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы. 
Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив. 
Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. 
Вывести массив по возрастанию в файл output.txt.
*/
#include <stdio.h>
#define STRLEN 500
//int InputString(FILE *input,char* str);
int get_numbers_from_string(FILE *input, int *arr);
void BubbleSort(int len,int arr[]);
void print_digits(FILE *output,int n,int *arr);

int main(void)
{
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");

    int arr[STRLEN]= {0}, 
        n = 0;

    n = get_numbers_from_string(input,arr);
    BubbleSort(n,arr);
    print_digits(output,n,arr);

    fclose(input);
    fclose(output);

    return 0;
}

int get_numbers_from_string(FILE *input, int *arr)
{
    int i = 0;
    char c = 0, letter = 'a';
         
    while((c = fgetc(input)) != EOF)
    {
        if(c>= '0' && c <= '9')
        {
            arr[i] *= 10;
            arr[i] += c - 0x30;
        }
        else if(letter >='0' && letter <= '9')
        {
            i++;
        }
        letter = c;
    }
    return i;

}
void print_digits(FILE *output,int n,int *arr)
{
    for(int i=0; i < n; i++)
    {
        fprintf(output, "%d ", arr[i]);
    }
}
//функция перестановки одного элемента с другим
void SwapArr(int arr[],int i,int j)
{
		int temp = arr[i];
		arr[i]   = arr[j];
		arr[j]   = temp;
}
// функция сортировки массива
void BubbleSort(int len,int arr[])
{
	int noSwap;
    for (int i = 0; i < len; i++)
    {
		 noSwap = 1;
		for (int j = len-1; j > i; j--)
        {
			if(arr[j-1]>arr[j])
            {
                SwapArr(arr,j-1,j);
                noSwap = 0;
            }
        }
        if(noSwap)
            break;
    }
}
//~ //функция чтения строки из файла
//~ int InputString(FILE *input,char* str)
//~ {
    //~ int res = 0;
    //~ res = fscanf(input, "%[a-zA-Z0-9 ,.;:!?-\'\")(]s", str);
    
    //~ return res;
//}
