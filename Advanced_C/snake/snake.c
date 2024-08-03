#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  2 //Отступ по оси Y для терминала
// Нумерованный список для хранения кодов управления
enum {
		LEFT = 1, 				// Код движения налево = 1
		UP = 2, 				// Код движения вверх = 2
		RIGHT = 3, 				// Код движения направо = 3
		DOWN = 4, 				// Код движения вниз = 4
		STOP_GAME=KEY_F(10), 	// кнопка для выхода из игры
		CONTROLS = 3
		};
// Нумерованный список для хранения игровых параметров
enum {
		MAX_TAIL_SIZE=100,      // Максимальная длина хвоста
		START_TAIL_SIZE=3, 		// Начальная длина хвоста
		MAX_FOOD_SIZE=20, 		// Максимальное количество еды
		FOOD_EXPIRE_SECONDS=10, // Интервал обновления еды на экране
		SEED_NUMBER = 3			// Начальное количество еды
		};


// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;					// Код движения вниз
    int up;						// Код движения вверх
    int left;					// Код движения налево
    int right;					// Код движения направо
}control_buttons;

// Структура для хранения кодов управления змейкой по умолчанию.
struct control_buttons default_controls[CONTROLS] = {
    {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT},
    {'s', 'w', 'a', 'd'},
    {'S', 'W', 'A', 'D'}
};

/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    //struct control_buttons controls;
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;

//структура еды
/*Еда - это массив точек, состоящий из координат х,у, времени
  когда данная точка была установлена, и поля, сигнализирующего
  была ли данная точка съедена*/
struct food
{
	int x;
	int y;
	time_t put_time;
	char point;
	uint8_t enable;
}food[MAX_FOOD_SIZE];  

//Инициализация еды
void initFood(struct food f[], size_t size)
{
	struct food init_f = {0,0,0,0,0};
	for (size_t i = 0; i < size; i++)
	{
		f[i]=init_f;
	}
}
/*Обновить/разместить текущее зерно на поле*/
void putFoodSeed(struct food *fp)
{
	int max_x=0, max_y=0;
	char spoint[2]={0};
	getmaxyx(stdscr, max_y, max_x);// берем макс. размеры экрана
	mvprintw(fp->y, fp->x, " ");// затираем то, что было на пред. месте
	fp->x = rand() % (max_x - 1);//берем случайные координаты где будет расположена еда
	fp->y = rand() % (max_y - 2)+1;//не занимаем верхнюю строку
	fp->put_time = time(NULL); //записываем текущее время
	fp->point = '$'; //символ еды
	fp->enable = 1;
	spoint[0] = fp->point;// записываем координаты
	mvprintw(fp->y, fp->x, "%s", spoint);//прорисовываем еду
}
/* разместить еду на поле количество зерен и размер зерен*/
void putFood(struct food f[], size_t number_seeds)
{
	for (size_t i = 0; i < number_seeds; i++)
	{
		putFoodSeed(&f[i]);
	}
}
/*обновить еду*/
void refreshFood(struct food f[], int nfood)
{
	for (size_t i = 0; i < nfood; i++)
	{
		if (f[i].put_time)
		{
			if (!f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS)
			{
				putFoodSeed(&f[i]);
			}
		}
	}
}

// Функция увеличения хвоста
void addTail(snake_t *head) {
    ++(head -> tsize);
}

//функция захвата еды
void haveEat(snake_t *head, struct food f[]) {
    for(size_t i = 0; i < MAX_FOOD_SIZE; i++) {
        if(f[i].x == head -> x && f[i].y == head -> y) {//если координаты еды и головы змейки совпадают
            addTail(head);//увеличиваем хвост
        }
    }
}

//инициализируем хвост
void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t={0,0};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}
//Инициализируем голову
void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;// координата х
    head->y = y;// координата y
    head->direction = RIGHT;// направление
}
// инициализируем змейку, передаем голову, размер и начальные координаты
void initSnake(snake_t *head, size_t size, int x, int y)
{
	// выделяем память под хвост через malloc
tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);// проинициализировали хвост
    initHead(head, x, y); // проинициализировали голову
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size+1; // размер змейки хвост + 1(голова)
    //head->controls = default_controls;// назначили управление
}

/*
 Движение головы с учетом текущего направления движения
 */
void go(struct snake_t *head)
{
    char ch = '@'; // символ головы
    int max_x=0, max_y=0; // Переменные для хранения размеров окна терминала
    getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ (удаляем текущую голову)
    switch (head->direction) //анализ направления движения
    {
        case LEFT:
            if(head->x <= 0) // Если змейка достигла левой границы
                {head->x = max_x;} // Переходим на противоположную (правую) сторону
            mvprintw(head->y, --(head->x), "%c", ch); // Перемещаем голову налево
        break;
        case RIGHT:
			if(head->x >= max_x) // Если змейка достигла правой границы
                {head->x = 0;} // Переходим на противоположную (левую) сторону
            mvprintw(head->y, ++(head->x), "%c", ch); // Перемещаем голову направо
        break;
        case UP:
			if(head->y <= 0) // Если змейка достигла верхней границы
                {head->y = max_y;} // Переходим на противоположную (нижнюю) сторону
            mvprintw(--(head->y), head->x, "%c", ch); // Перемещаем голову вниз
        break;
        case DOWN:
			if(head->y >= max_y) // Если змейка достигла нижней границы
                {head->y = 0;} // Переходим на противоположную (верхнюю) сторону
            mvprintw(++(head->y), head->x, "%c", ch); // Перемещаем голову вверх
        break;
        default:
        break;
    }
    refresh(); //обновление экрана
}
//функция проверки направление движения параметры - структура snake и ключ нажатой кнопки
int checkDirection(snake_t* snake, int32_t key) {
    int flag = 0;
    for(size_t i = 0; i < CONTROLS; i++) {
        if (key ==  default_controls[i].down) { // если нажата кнопка вниз и если текущее направление не вверх
            if(snake -> direction != UP)
                flag = 1; // тогда возвращаем 1
        }
        else if (key ==  default_controls[i].up) { // если нажата кнопка вверх и если текущее направление не вниз
            if(snake -> direction != DOWN)
                flag = 1; // тогда возвращаем 1
        }
        else if (key ==  default_controls[i].right) { // если нажата кнопка вправо и если текущее направление не влево
            if(snake -> direction != LEFT)
                flag = 1; // тогда возвращаем 1
        }

        else if (key ==  default_controls[i].left) { // если нажата кнопка влево и если текущее направление не вправо
            if(snake -> direction != RIGHT)
                flag = 1; // тогда возвращаем 1
        }

    }
    return flag;
}

//смена направления параметры - структура snake и ключ нажатой кнопки
//Функция проверяет нажатую клавишу и изменяет направление движения змейки в соответствии с управлением.
//Управление определяется полем `controls` в структуре змейки.
void changeDirection(snake_t *snake, const int32_t key) {
    if(checkDirection(snake, key)) { //если можно менять направление
        for(size_t i = 0; i < CONTROLS; i++) {
            if (key ==  default_controls[i].down) {//если нажата кнопка вниз
                snake -> direction = DOWN; // двигаемся вниз
            }
            else if (key ==  default_controls[i].up) { //если нажата кнопка вверх
                snake -> direction = UP; //двигаемся вверх
            }
            else if (key ==  default_controls[i].right) {// если нажата кнопка вправо
                snake -> direction = RIGHT; //двигаемся вправо
            }

            else if (key ==  default_controls[i].left) {// если нажата кнопка влево
                snake -> direction = LEFT; // двигаемся влево
            }

        }
    }
}
/*void changeDirection(struct snake_t* snake, const int32_t key)
{
    if ((key == snake->controls.down||( key == 115)||(key == 83))&&(snake->direction!=UP))
        snake->direction = DOWN;
    else if ((key == snake->controls.up||( key == 119)||(key == 87))&&(snake->direction!=DOWN))
        snake->direction = UP;
    else if ((key == snake->controls.right ||( key == 100)||(key == 68))&&(snake->direction!=LEFT))
        snake->direction = RIGHT;
    else if ((key == snake->controls.left||( key == 97)||(key == 65))&&(snake->direction!=RIGHT))
        snake->direction = LEFT;
}*/

/*
 Движение хвоста с учетом движения головы
 */
void goTail(struct snake_t *head)
{
    char ch = 'o';//символ хвоста
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");//стираем последний элемент
    for(size_t i = head->tsize-1; i>0; i--) //переставляем все элементы, не считая 0
    {
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
        /*if ((head->x == head->tail[i].x) &&(head->y == head->tail[i].y))
		{
			mvprintw(1, 1,"game over");
		}  */  
    }
    head->tail[0].x = head->x;// где раньше был хвост там стала голова
    head->tail[0].y = head->y;
}
//Функция проверки столкновения головы и хвоста змейки
void CheckCollisionWithTail(struct snake_t *head)
{
	for(size_t i = 1; i < head -> tsize; i++) {
        if ((head->x == head->tail[i].x) &&(head->y == head->tail[i].y)) { // если координаты головы и хвоста совпадают
				clear();                                        // Очищает экран терминала
				mvprintw(0, 1, "You lose! Restart in 3 seconds..."); // Выводит сообщение о проигрыше
				refresh();                                      // Обновляет экран, чтобы отобразить изменения
				sleep(3);                                       // Задержка на 3 секунды
				// Перезапуск игры
				clear();                                        // Очищает экран терминала
				snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
				initSnake(snake, START_TAIL_SIZE, 10, 10);      // Инициализирует змейку с начальным размером и позициями
				mvprintw(0, 1, "Use arrows for control. Press 'F10' for EXIT"); // Инструкции для управления
				refresh();                                      // Обновляет экран, чтобы отобразить изменения
		} 
		}
}


int main()
{
snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
    initSnake(snake,START_TAIL_SIZE,10,10); //инициализируем змейку
    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Отключаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    mvprintw(0, 0,"Use arrows or WSAD for control. Eat %d '$' for grow up. Press 'F10' for EXIT");
    //timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    initFood(food, MAX_FOOD_SIZE);
    putFood(food, SEED_NUMBER);// КЛАДЕМ ЗЕРНА
    int key_pressed=0;
    while( key_pressed != STOP_GAME )
    {
        key_pressed = getch(); // Считываем клавишу
        go(snake);
        goTail(snake);
        haveEat(snake, food);
        CheckCollisionWithTail(snake);
        timeout(100); // Задержка при отрисовке
        refreshFood(food, SEED_NUMBER);// ОБНОВЛЯЕМ ЕДУ
        changeDirection(snake, key_pressed);
    }
    free(snake->tail);//освобождаем память под хвост
    free(snake);//освобождаем память под змейку
    endwin(); // Завершаем режим curses mod
    return 0;
}
