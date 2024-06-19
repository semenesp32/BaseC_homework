#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Создаем структуру для описания данных
typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} sensor;

void changeIJ(sensor *info, int i, int j);
// функция сортировки по температуре
void SortByTemp(sensor *info, int n);
// функция преобразования даты в число
unsigned long long DateToInt(sensor *info);
// функция сортировки по дате
void SortByDate(sensor *info, int n);
// функция добавления данных в структуру
void AddRecord(sensor *info, int *number, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t temperature);
// функция вывода на печать
void Print(sensor *info, int number);
// функция статитики по месяцам
void StatisticsInMonths(sensor *info, int number);
// функция статистики за год
void StatisticsForYear(sensor *info, int number);
// функция чтения csv файла с данными
void InputFileRead(const char *filename, sensor **info, int *number);
// функция работы программы по аргументам из командной строки
void ArgsCommandLine(int argc, char *argv[], sensor **info, int *number);

#endif