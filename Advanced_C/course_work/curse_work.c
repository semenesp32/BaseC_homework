/*

Программа является консольным приложением и рекомендуется запускать её из командной строки.
При запуске без указания ключей, программа кратко выведет информацию о своем назначении и
предложении ввести ключ «-h» для получения инструкций.

Программа допускает применение следующих ключей:
●	«-h» - получение информации о возможных ключах запуска с кратким описанием их назначения;
●  «-t» - проверка функций вычисления интеграла (метод прямоугольников и метод трапеций) на тестовой функции (квадрат)
●  «-p xx» - вывод точек пересечения функций и числа итераций для выбранного метода, где xx - метод вычисления:
   1 - метод линейного приближения;
   2 - метод хорд;
   3 - метод касательных;
   4 - комбинированный метод.
●  «-i» - вывод вычисленного интеграла, ограниченного функциями f(x)=0.6x+3, f(x)=(x-2)^3-1, f(x)=3/x.
   Интеграл вычисляется методом трапеции и методом прямоугольников   

Примеры написания командной строки для запуска:
.\prog -h
.\prog -t
.\prog -p 3
.\prog -i


Программа состоит из следующих файлов:
makefile – файл инструкция для утилиты сборки mingw32-make;
prog.exe – собранный исполняемый файл программы;
curse.c – основной файл программы с точкой входа, функцией main. Содержит только логику запуска функций и обработку ключей, поступающих от командной строки;

Папка info:
картинка с графиком функций
*/
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef float(*function)(float);

//Функции f(x)=0.6x+3 и f(x)=(x-2)^3-1 пересекаются в точке 3.8477602451151 итервал [3.5, 4]
//Функции f(x)=0.6x+3 и f(x)=3/x пересекаются в точке 0.8541019662497 итервал [0.5, 1]
//Функции f(x)=(x-2)^3-1 и f(x)=3/x пересекаются в точке 3.2439288539037 итервал [3, 3.5]
//функция f(x)=0.6x+3
float g(float x) {
    return 0.6*x+3;
}
//функция f(x)=(x-2)^3-1
float g2(float x) {
    return (x-2)*(x-2)*(x-2)-1;
}
//функция f(x)=3/x
float g3(float x) {
    return 3/x;
}
//разность функций f(x)=0.6x+3 и f(x)=(x-2)^3-1 
float f(float x) {
    return 0.6*x+3-((x-2)*(x-2)*(x-2)-1);
}
//разность функций f(x)=0.6x+3 и f(x)=3/x
float f2(float x) {
    return 0.6*x+3-3/x;
}
//разность функций f(x)=(x-2)^3-1 и f(x)=3/x
float f3(float x) {
    return ((x-2)*(x-2)*(x-2)-1)-3/x;
}

//---------------------------------------------------------------------------------------------
//производная от разности функций f(x)=0.6x+3 и f(x)=(x-2)^3-1, т.е от f(x)=0.6x+3-((x-2)^3-1)
//f'(x)=0.6-(3(x-2)^2)
float df(float x) {
    return 0.6-(3*(x-2)*(x-2));
}

//вторая производная от f'(x)=0.6-(3(x-2)^2) f''(x)=-6(x-2)
float ddf(float x) {
    return -6*(x-2);
}

//----------------------------------------------------------------------------------
//производная от разности функций f(x)=0.6x+3 и f(x)=3/x, т.е от f(x)=0.6x+3-3/x
//f'(x)=0.6+3/(x^2)
float df2(float x) {
    return 0.6+(3/(x*x));
}

//вторая производная от f'(x)=0.6+3/(x^2) f''(x)=6/(x^3)
float ddf2(float x) {
    return 6/(x*x*x);
}

//----------------------------------------------------------------------------------
//производная от разности функций f(x)=(x-2)^3-1 и f(x)=3/x, т.е от f(x)=(x-2)^3-1-3/x
//f'(x)=3(x-2)^2+3/(x^2)
float df3(float x) {
    return 3*(x-2)*(x-2)+(3/(x*x));
}

//вторая производная от f'(x)=3(x-2)^2+3/(x^2) f''(x)=6/(x^3)
float ddf3(float x) {
    return 6*(x-2)-(6/(x*x*x));
}
//функция для теста вычисления интеграла
float testf(float x){
    return 2; 
}
char method = 0;
//метод линейного приближения
float rootFindLineSearch(float xl, float xr, float eps, function f) {
    float x, minx = xl, nextstep;
    nextstep = fabs(xr-xl)/(1/eps); //разбиваем на отрезки интервал
    int stepcount=0; 
    for(x=xl; x<xr; x += nextstep, stepcount++) {
        if( fabs(f(x)) < fabs(f(minx)) )
            minx = x;
    }
    printf("Find Line Search root for %d steps\n",stepcount);
    return minx;
}

//метод хорд
float rootFindChord(float xl, float xr, float eps, function f) {
    int stepcount=0; 
    while(fabs(xr - xl) > eps) {
        xl = xr - (xr - xl) * f(xr) / (f(xr) - f(xl));
        xr = xl - (xl - xr) * f(xl) / (f(xl) - f(xr));
        stepcount++;
    }
    printf("Find Chord Search root for %d steps\n",stepcount);
    return xr;
}
//метод касательных
float rootFindTangent(float xn, float eps, function f, function df ) {
    float x1  = xn - f(xn)/df(xn);
    float x0  = xn;
    int stepcount=0;    
    while(fabs(x0-x1) > eps) {
        x0 = x1;
        x1 = x1 - f(x1)/df(x1);
        stepcount++;    
    }
    printf("Find Tangent Search root for %d steps\n",stepcount);   
    return x1;
}
//комбинированный метод
float rootFindCombine(float xl, float xr, float eps, function f, function df, function ddf ) {
   int stepcount=0;    
   while(fabs(xl-xr) > 2*eps) {
       if( f(xl)*ddf(xl)<0 )
           xl = xl - (f(xl)*(xl - xr))/(f(xl) - f(xr));
       else
           xl = xl - f(xl)/df(xl);
       if( f(xr)*ddf(xr)<0 )
           xr = xr - (f(xr)*(xr - xl))/(f(xr) - f(xl));
       else
           xr = xr - f(xr)/df(xr);
       stepcount++;        
   } printf("Find Combine Search root for %d steps\n",stepcount); return (xl+xr)/2;
}

// считаем интеграл методом прямоугольников
float calcIntegralSquare(float xl, float xr, size_t n, function f) {
    float sum = 0;
    float h = (xr-xl)/n;
    for(size_t i=0; i<n; i++) {
        sum += f(xl);
        xl  += h;
    }
    return sum*h;
}
// считаем интеграл методом трапеций
float calcIntegralTrap(float xl, float xr, size_t n, function f) {
    float sum = 0;
    float h = (xr-xl)/n;
    for(float x=xl+h; x<xr-h; x+=h) {
        sum += 0.5*h*(f(x)+f(x+h));
    }
    return sum;
}

// функция работы программы по аргументам из командной строки
void ArgsCommandLine(int argc, char *argv[])
{
    //если в коммандную строку ввели -h выводим сообщение с назначением программы и основными командами
    if (argc == 1 || strcmp(argv[1], "-h") == 0)
    {
        printf("Usage: %s [-h] [-p <method number>] [-i] [-t]\n", argv[0]);
        printf("Options:\n");
        printf("  -h\t\tDisplay this help message\n");
        printf("  -t\t\tTest calcIntegralSquare and calcIntegralTrap functions\n");
        printf("  -p\t\tDisplay points between functions f(x)=0.6x+3, f(x)=(x-2)^3-1 and f(x)=3/x\n");
        printf("  -i\t\tDisplay CalcIntegral between functions f(x)=0.6x+3, f(x)=(x-2)^3-1 and f(x)=3/x\n");
        return;
    }
    //обработка основных комманд из командной строки
    for (int i = 1; i < argc; ++i)
    {
        if (argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
            case 't':
               //тест работы функций calcIntegralSquare and calcIntegralTrap functions
               printf("-----------------------------------------------------------------\n");
               printf("Test calcIntegralSquare and calcIntegralTrap functions\n");
               printf("calcIntegralSquare integral %f\n", calcIntegralSquare(0,2,1000,testf));
               printf("calcIntegralTrap = %f\n", calcIntegralTrap(0,2,1000,testf));
               break;
            case 'p':
                if (i + 1 < argc)
                {
                    method = atoi(argv[++i]);
                }
                else
                {
                    printf("Missing argument for -p\n");
                    return;
                }
                if (method == 1)//метод линейного приближения
                {
                  //ищем точку пересечения функций f(x)=0.6x+3 и f(x)=(x-2)^3-1
	               printf("Find point between f(x)=0.6x+3 and f(x)=(x-2)^3-1\n");
                  printf("Line Search root = %f\n",rootFindLineSearch(3.5,4,0.001,f));
                  printf("--------------------------------------------------\n");
                  //ищем точку пересечения функций f(x)=0.6x+3 и f(x)=3/x
	               printf("Find point between f(x)=0.6x+3 and f(x)=3/x\n");
	               printf("Line Search root = %f\n",rootFindLineSearch(0.5,1,0.001,f2));
                  printf("--------------------------------------------------\n");
                  //ищем точку пересечения функций f(x)=(x-2)^3-1 и f(x)=3/x
	               printf("Find point between f(x)=(x-2)^3-1 and f(x)=3/x\n");
	               printf("Line Search root = %f\n",rootFindLineSearch(3,3.5,0.001,f3));
                }
                else if (method==2) //метод хорд
                {
                  //ищем точку пересечения функций f(x)=0.6x+3 и f(x)=(x-2)^3-1
	               printf("Find point between f(x)=0.6x+3 and f(x)=(x-2)^3-1\n");
                  printf("Find Chord Search root = %f\n", rootFindChord(3.5,4,0.001,f));
                  printf("--------------------------------------------------\n");
                  //ищем точку пересечения функций f(x)=0.6x+3 и f(x)=3/x
	               printf("Find point between f(x)=0.6x+3 and f(x)=3/x\n");
	               printf("Find Chord Search root = %f\n",rootFindChord(0.5,1,0.001,f2));
                  printf("--------------------------------------------------\n");
                  //ищем точку пересечения функций f(x)=(x-2)^3-1 и f(x)=3/x
	               printf("Find point between f(x)=(x-2)^3-1 and f(x)=3/x\n");
	               printf("Find Chord Search root = %f\n",rootFindChord(3,3.5,0.001,f3));
                }
                else if (method==3) //метод касательных
                {
                  //ищем точку пересечения функций f(x)=0.6x+3 и f(x)=(x-2)^3-1
	               printf("Find point between f(x)=0.6x+3 and f(x)=(x-2)^3-1\n");
                  printf("Find Tangent root = %f\n", rootFindTangent(3.5,0.001,f,df));
                  printf("--------------------------------------------------\n");
                  //ищем точку пересечения функций f(x)=0.6x+3 и f(x)=3/x
	               printf("Find point between f(x)=0.6x+3 and f(x)=3/x\n");
	               printf("Find Tangent root = %f\n", rootFindTangent(0.5,0.001,f2,df2));
                  printf("--------------------------------------------------\n");
                  //ищем точку пересечения функций f(x)=(x-2)^3-1 и f(x)=3/x
	               printf("Find point between f(x)=(x-2)^3-1 and f(x)=3/x\n");
	               printf("Find Tangent root = %f\n", rootFindTangent(3,0.001,f3,df3));
                }
                else if (method==4) //комбинированный метод
                {
                  //ищем точку пересечения функций f(x)=0.6x+3 и f(x)=(x-2)^3-1
	               printf("Find point between f(x)=0.6x+3 and f(x)=(x-2)^3-1\n");
                  printf("Find Combine root = %f\n", rootFindCombine(3.5,4,0.001,f, df, ddf)); 
                  printf("--------------------------------------------------\n");
                  //ищем точку пересечения функций f(x)=0.6x+3 и f(x)=3/x
	               printf("Find point between f(x)=0.6x+3 and f(x)=3/x\n");
	               printf("Find Combine root = %f\n", rootFindCombine(0.5,1,0.001,f2, df2, ddf2));
                  printf("--------------------------------------------------\n");
                  //ищем точку пересечения функций f(x)=(x-2)^3-1 и f(x)=3/x
	               printf("Find point between f(x)=(x-2)^3-1 and f(x)=3/x\n");
	                printf("Find Combine root = %f\n", rootFindCombine(3,3.5,0.001,f3, df3, ddf3));
                } 
               break;
            case 'i':
               printf("-----------------------------------------------------------------\n");
               printf("---------------CalcIntegralSquare method-----------------------------\n");
               printf("calcIntegralSquare under function f(x)=0.6x+3 between point [0.854017,3.8477] = %f\n", calcIntegralSquare(0.854017,3.8477,1000,g));
               printf("calcIntegralSquare under function f(x)=3/x between point [0.854017,3.243929] = %f\n", calcIntegralSquare(0.854017,3.243929,1000,g3));
               printf("calcIntegralSquare under function f(x)=(x-2)^3-1 between point [3.243929,3.8477] = %f\n", calcIntegralSquare(3.243929,3.8477,1000,g2));
               float_t totalIntegralSquare = calcIntegralSquare(0.854017,3.8477,1000,g) - calcIntegralSquare(0.854017,3.243929,1000,g3) - calcIntegralSquare(3.243929,3.8477,1000,g2); 
               printf("calcIntegralSquare total integral =%f\n", totalIntegralSquare);
    
               printf("-----------------------------------------------------------------\n");
               printf("---------------CalcIntegralTrap method-----------------------------\n");
               printf("calcIntegralTrap under function f(x)=0.6x+3 between point [0.854017,3.8477] = %f\n", calcIntegralTrap(0.854017,3.8477,1000,g));
               printf("calcIntegralTrap under function f(x)=3/x between point [0.854017,3.243929] = %f\n", calcIntegralTrap(0.854017,3.243929,1000,g3));
               printf("calcIntegralTrap under function f(x)=(x-2)^3-1 between point [3.243929,3.8477] = %f\n", calcIntegralTrap(3.243929,3.8477,1000,g2));
               float_t totalIntegralTrap = calcIntegralTrap(0.854017,3.8477,1000,g) - calcIntegralTrap(0.854017,3.243929,1000,g3) - calcIntegralTrap(3.243929,3.8477,1000,g2); 
               printf("calcIntegralTrap total integral =%f\n", totalIntegralTrap);
               break;

            default:
                printf("Invalid option: %s\n", argv[i]);
                return;
            }
        }
    }
}


int main(int argc, char *argv[]) {
	
     while (1)
    {
        ArgsCommandLine(argc, argv);

        char input[256];
        if (!fgets(input, sizeof(input), stdin))
        {
            break;
        }

        argc = 0;
        char *token = strtok(input, " \n");
        while (token && argc < 256)
        {
            argv[argc++] = token;
            token = strtok(NULL, " \n");
        }
    }

    return 0;    
}
