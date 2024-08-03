#include "temp_functions.h"
// функция преобразования номера месяца в его название
void MonthName(char* month, int number){
    switch (number)
    {
    case 1:
        strcpy(month, "January");
        break;
    case 2:
        strcpy(month, "February");
        break;
    case 3:
        strcpy(month, "March");
        break;
    case 4:
        strcpy(month, "April");
        break;
    case 5:
        strcpy(month, "May");
        break;
    case 6:
        strcpy(month, "June");
        break;
    case 7:
        strcpy(month, "July");
        break;
    case 8:
        strcpy(month, "August");
        break;
    case 9:
        strcpy(month, "September");
        break;
    case 10:
        strcpy(month, "October");
        break;
    case 11:
        strcpy(month, "November");
        break;
    case 12:
        strcpy(month, "December");
        break;
    default:
        strcpy(month, "NON");
        break;
    }
}
// функция перестановки одного элемента с другим
void changeIJ(sensor *info, int i, int j)
{
    sensor temp;
    temp = info[i];
    info[i] = info[j];
    info[j] = temp;
}
// функция сортировки по температуре
void SortByTemp(sensor *info, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (info[i].temperature >= info[j].temperature)
            {
                changeIJ(info, i, j);
            }
        }
    }
}
// функция преобразования даты в число
unsigned long long DateToInt(sensor *info)
{
    return ((unsigned long long)info->year << 32) | (info->month << 24) | (info->day << 16) | (info->hour << 8) | info->minute;
}
// функция сортировки по дате
void SortByDate(sensor *info, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (DateToInt(info + i) >= DateToInt(info+j))
            {
                changeIJ(info, i, j);
            }
        }
    }
}
// функция добавления данных в структуру
void AddRecord(sensor info[], int *number, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t temperature)
{
    info[*number].year = year;
    info[*number].month = month;
    info[*number].day = day;
    info[*number].hour = hour;
    info[*number].minute = minute;
    info[*number].temperature = temperature;
    (*number)++;
}

void Print(sensor *info, int number)
{
    printf("=================================================================\n");
    for (int i = 0; i < number; i++)
    {
        printf("|\t %04d-%02d-%02d\t|\t%02d:%02d\t|\tt =%3d\t\t|\n",
               info[i].year,
               info[i].month,
               info[i].day,
               info[i].hour,
               info[i].minute,
               info[i].temperature);
    }
    printf("=================================================================\n");
}
// функция статистики за месяц
void StatisticsInMonths(sensor *info, int number)
{
    //создаем двумерный массив, где первый элемент - номер месяца,
    //второй - [0] = sum, [1] = min, [2] = max
    int months[12][3] = {0}; 
    int counts[12] = {0};
    char mouth_name[20];

    for (int i = 0; i < number; ++i)
    {
        int month = info[i].month - 1;
        if (counts[month] == 0)
        {
            months[month][1] = months[month][2] = info[i].temperature;
        }
        months[month][0] += info[i].temperature;
        if (info[i].temperature < months[month][1])
        {
            months[month][1] = info[i].temperature;
        }
        if (info[i].temperature > months[month][2])
        {
            months[month][2] = info[i].temperature;
        }
        counts[month]++;
    }

    for (int i = 0; i < 12; ++i)
    {
        if (counts[i] > 0)
        {
            MonthName(mouth_name, i+1);
            printf("Month    | Min| Max | Average |\n");
            printf("%9s| %d| %d | %.2f  |\n", mouth_name, months[i][1], months[i][2], (float)months[i][0] / counts[i]);
            
        }
        
    }
    
    printf("==================================================================\n");
}
// функция статистики за год
void StatisticsForYear(sensor *info, int number)
{
    int SumTemp = 0; 
    int MinTemp = info[0].temperature, MaxTemp = info[0].temperature;
    for (int i = 0; i < number; ++i)
    {
        SumTemp += info[i].temperature;
        if (info[i].temperature < MinTemp)
        {
            MinTemp = info[i].temperature;
        }
        if (info[i].temperature > MaxTemp)
        {
            MaxTemp = info[i].temperature;
        }
    }
    printf("==================================================================\n");
    printf("Min Max Average\n");
    printf("%d %d %.2f\n", MinTemp, MaxTemp, (float)SumTemp / number);
    printf("==================================================================\n");
}
//функция чтения входного csv-файла
void InputFileRead(const char *filename, sensor **info, int *number)
{
    //открываем файл на чтение
    FILE *INPUT_file = fopen(filename, "r");
    // проверяем существует ли файл
    if (INPUT_file==NULL)
    {
        printf("Could not open file");
        return;
    }
    //создаем массив для строки из файла
    char buffer_line[256];
    //размер памяти
    size_t memory = 10;
    //выделяем память под нашу структуру
    *info = (sensor *)malloc(memory * sizeof(sensor));
    //если недостаточно памяти - выводим сообщение и закрываем файл
    if (!(*info))
    {
        printf("Could not allocate memory");
        fclose(INPUT_file);
        return;
    }

    *number = 0;
    //номер строки в файле
    int line_number = 0;

    while (fgets(buffer_line, sizeof(buffer_line), INPUT_file))
    {
        line_number++;
        uint16_t year;
        uint8_t month, day, hour, minute;
        int temperature;
        //проверяем полученный массив строки
        // если в нем ошибка то выводим соответствующий номер строки в файле
        if (sscanf(buffer_line, "%4hu;%2hhu;%2hhu;%2hhu;%2hhu;%d",
                   &year, &month, &day, &hour, &minute, &temperature) != 6)
        {
            printf("A data format error in line No.%d\n", line_number);
            continue;
        }
         //если количество данных больше выделенной памяти,то переопределяем память
        if (*number >= (int)memory)
        {
            //увеличиваем размер памяти в 2 раза
            memory *= 2;
            sensor *new_info = (sensor *)realloc(*info, memory * sizeof(sensor));
            //если выделенной памяти недостаточно выводим сообщение об ошибке, освобождаем память и закрываем файл
            if (!new_info)
            {
                perror("Could not reallocate memory");
                free(*info);
                fclose(INPUT_file);
                return;
            }
            *info = new_info;
        }

        //записываем считанные данные в нашу структуру
        (*info)[*number].year = year;
        (*info)[*number].month = month;
        (*info)[*number].day = day;
        (*info)[*number].hour = hour;
        (*info)[*number].minute = minute;
        (*info)[*number].temperature = temperature;
        (*number)++;
    }

    fclose(INPUT_file);
}

// функция работы программы по аргументам из командной строки
void ArgsCommandLine(int argc, char *argv[], sensor **info, int *number)
{
    //если в коммандную строку ввели -h выводим сообщение с назначением программы и основными коммандами
    if (argc == 1 || strcmp(argv[1], "-h") == 0)
    {
        printf("Usage: %s [-h] [-f <filename.csv>] [-m <month number>] [-q]\n", argv[0]);
        printf("Options:\n");
        printf("  -h\t\tDisplay this help message\n");
        printf("  -f <filename.csv>\tInput CSV file for analyzing\n");
        printf("  -m <month number>\tDisplay statistics only in the entering number of month\n");
        return;
    }

    char *filename = NULL;
    int month = -1;
    //обработка основных комманд из командной строки
    for (int i = 1; i < argc; ++i)
    {
        if (argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
            case 'f':
                if (i + 1 < argc)
                {
                    filename = argv[++i];
                }
                else
                {
                    printf("Missing argument for -f\n");
                    return;
                }
                break;
            case 'm':
                if (i + 1 < argc)
                {
                    month = atoi(argv[++i]);
                }
                else
                {
                    printf("Missing argument for -m\n");
                    return;
                }
                break;
            default:
                printf("Invalid option: %s\n", argv[i]);
                return;
            }
        }
    }

    if (filename != NULL)
    {
        char filepath[256];
        snprintf(filepath, sizeof(filepath), "data/%s", filename);
        InputFileRead(filepath, info, number);

        if (*info == NULL)
        {
            printf("Failed to read the CSV file: %s\n", filename);
            return;
        }

        if (month != -1)
        {
            printf("Statistics for month %d\n", month);
            int month_count = 0;
            sensor *month_info = (sensor *)malloc(*number * sizeof(sensor));

            if (!month_info)
            {
                perror("Could not allocate memory for month info");
                return;
            }

            for (int i = 0; i < *number; ++i)
            {
                if ((*info)[i].month == month)
                {
                    month_info[month_count++] = (*info)[i];
                }
            }

            if (month_count > 0)
            {
                StatisticsInMonths(month_info, month_count);
            }
            else
            {
                printf("No data available for month %d\n", month);
            }

            free(month_info);
            return;
        }

        printf("\nStatistics For Year\n");
        StatisticsForYear(*info, *number);

        printf("\nStatistics In Months\n");
        StatisticsInMonths(*info, *number);
    }
    else
    {
        printf("No input file specified. Use -h for help.\n");
    }
}

