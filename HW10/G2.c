/*Строка и цифры
Считать число N из файла input.txt. Сформировать строку из N символов. N четное число, не превосходящее 26. 
На четных позициях должны находится четные цифры в порядке возрастания, кроме 0, 
на нечетных позициях - заглавные буквы в порядке следования в английском алфавите. Результат записать в файл output.txt*/
#include <stdio.h>

int main(void)
{
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");

    char str[27]= {'\0'};
    int num=0, cnt_num = 2,cnt_lett = 1;
    fscanf(input,"%d",&num);
    fclose(input);
    for(int i = 0; i < num; i++)
    {
		//если цифры четные
        if(i % 2)
        {
            str[i] = 0x30 + cnt_num;
            cnt_num += 2;
            if(cnt_num > 9)
            {
                cnt_num = 2;
            }
        }
        else
        {
			//если нечетные, то меняем на буквы
            str[i] = 0x40 + cnt_lett++;
            if(cnt_lett > 26)
             cnt_lett = 1;
        }
    }
    fprintf(output,"%s",str);
    fclose(output);
    return 0;
}
