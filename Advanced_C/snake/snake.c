#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  2 //Отступ по оси Y для терминала
#define MAX_PLAYERS 2 // Количество игроков
bool AI = 0;
int8_t PLAYERS = 2;
int8_t MENU = 1;
int8_t COUNT = 0;
// Нумерованный список для хранения кодов управления
enum {
		LEFT = 1, 				// Код движения налево = 1
		UP = 2, 				// Код движения вверх = 2
		RIGHT = 3, 				// Код движения направо = 3
		DOWN = 4, 				// Код движения вниз = 4
		STOP_GAME=KEY_COMMAND, 	// кнопка для выхода из игры
		CONTROLS = 3
		};
// Нумерованный список для хранения игровых параметров
enum {
		MAX_TAIL_SIZE=100,      // Максимальная длина хвоста
		START_TAIL_SIZE=3, 		// Начальная длина хвоста
		MAX_FOOD_SIZE=20, 		// Максимальное количество еды
		FOOD_EXPIRE_SECONDS=10, // Интервал обновления еды на экране
		SEED_NUMBER = 3,			// Начальное количество еды
		WIN_COUNT = 10,
		LOSE = 99,
		WIN = 100,
		PLR_1_WIN = 101,
		PLR_2_WIN = 102,
		PLR_AI_WIN = 111
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
typedef struct food_t
{
	int x;
	int y;
	time_t put_time;
	char point;
	uint8_t enable;
}food_t;  

//Инициализация еды
void initFood(food_t f[], size_t size)
{
	food_t init_f = {0,0,0,0,0};
	for (size_t i = 0; i < size; i++)
	{
		f[i]=init_f;
	}
}
/* Функция добавления цветов*/
void setColor(int objectType) {
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    attroff(COLOR_PAIR(4));

    switch (objectType) {
    case 1: {
        attron(COLOR_PAIR(1));
        break;
    }
    case 2: {
        attron(COLOR_PAIR(2));
        break;
    }
    case 3: {
        attron(COLOR_PAIR(3));
        break;
    }
    case 4: { 
        attron(COLOR_PAIR(4));
        break;
    }
    default:
        attron(COLOR_PAIR(1));
    }

}
/*Обновить/разместить текущее зерно на поле*/
void putFoodSeed(food_t *fp)
{
	int max_x=0, max_y=0;
	char spoint[2]={0};
	setColor(2); //устанавливаем цвет для еды
	getmaxyx(stdscr, max_y, max_x);// берем макс. размеры экрана
	mvprintw(fp->y, fp->x, " ");// затираем то, что было на пред. месте
	fp->x = rand() % (max_x - 1);//берем случайные координаты где будет расположена еда
	fp->y = rand() % (max_y - 2)+2;//не занимаем верхнюю строку
	fp->put_time = time(NULL); //записываем текущее время
	fp->point = '$'; //символ еды
	fp->enable = 1;
	spoint[0] = fp->point;// записываем координаты
	mvprintw(fp->y, fp->x, "%s", spoint);//прорисовываем еду
}
/* разместить еду на поле количество зерен и размер зерен*/
void putFood(food_t f[], size_t number_seeds)
{
	for (size_t i = 0; i < number_seeds; i++)
	{
		putFoodSeed(&f[i]);
	}
}
/*обновить еду*/
void refreshFood(food_t f[], int nfood)
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
void haveEat(snake_t *head, food_t f[]) {
	
    for(size_t i = 0; i < MAX_FOOD_SIZE; i++) {
        if(f[i].x == head -> x && f[i].y == head -> y) {//если координаты еды и головы змейки совпадают
			//apple++;
            addTail(head);//увеличиваем хвост
            beep();
            
        }
    }
    //return apple;
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
int checkDirection(snake_t *snake, int32_t key, uint8_t player) {
    int flag = 0;
    //for(size_t i = 0; i < CONTROLS; i++) {
        if (key ==  default_controls[player].down) { // если нажата кнопка вниз и если текущее направление не вверх
            if(snake -> direction != UP)
                flag = 1; // тогда возвращаем 1
        }
        else if (key ==  default_controls[player].up) { // если нажата кнопка вверх и если текущее направление не вниз
            if(snake -> direction != DOWN)
                flag = 1; // тогда возвращаем 1
        }
        else if (key ==  default_controls[player].right) { // если нажата кнопка вправо и если текущее направление не влево
            if(snake -> direction != LEFT)
                flag = 1; // тогда возвращаем 1
        }

        else if (key ==  default_controls[player].left) { // если нажата кнопка влево и если текущее направление не вправо
            if(snake -> direction != RIGHT)
                flag = 1; // тогда возвращаем 1
        }

   // }
    return flag;
}

//смена направления параметры - структура snake и ключ нажатой кнопки и игрок
//Функция проверяет нажатую клавишу и изменяет направление движения змейки в соответствии с управлением.
//Управление определяется полем `controls` в структуре змейки.
void changeDirection(snake_t *snake, const int32_t key, uint8_t player) {
    if(checkDirection(snake, key, player)) { //если можно менять направление
            if (key ==  default_controls[player].down) {//если нажата кнопка вниз
                snake -> direction = DOWN; // двигаемся вниз
            }
            else if (key ==  default_controls[player].up) { //если нажата кнопка вверх
                snake -> direction = UP; //двигаемся вверх
            }
            else if (key ==  default_controls[player].right) {// если нажата кнопка вправо
                snake -> direction = RIGHT; //двигаемся вправо
            }

            else if (key ==  default_controls[player].left) {// если нажата кнопка влево
                snake -> direction = LEFT; // двигаемся влево
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
int CheckCollisionWithTail(struct snake_t *head)
{
	int resultGame = 0;
	for(size_t i = 1; i < head -> tsize; i++) 
	{
        if ((head->x == head->tail[i].x) &&(head->y == head->tail[i].y)) { // если координаты головы и хвоста совпадают
			resultGame = LOSE;
			} 
	}
	if(head -> tsize > WIN_COUNT + START_TAIL_SIZE - 1 && resultGame != LOSE) {
		resultGame = WIN;
    }
    return resultGame;
}

void startMenu() {

    int max_x = 0, max_y = 0;
    int width = 50, height = 5;
    char c = 0;
    getmaxyx(stdscr, max_y, max_x);
    WINDOW *menu = newwin(height, width, max_y/2 - height/2, max_x/2 - width/2);
    box(menu,0,0);
    setColor(3);
    refresh();
    wrefresh(menu);
    mvprintw(max_y/2 - 1, max_x/2 - width/2 + 5, "Press '1' for SINGLE PLAYER");
    mvprintw(max_y/2, max_x/2 - width/2 + 5, "Press '2' for TWO PLAYERS");
    mvprintw(max_y/2 + 1, max_x/2 - width/2 + 5, "Press '3' for AI mode");
    //mvprintw(max_y/2 + 2, max_x/2 - width/2 + 5, "Press '4' for choose level");

    wrefresh(menu);
    do {
        c = getch();
    }
    while( c!= '1' && c!='2' && c!= '3');

    switch(c) {
    case '1':
        PLAYERS = 1;
        break;
    case '2':
        PLAYERS = 2;
        break;
    case '3':
        PLAYERS = 2;
        AI = TRUE;
        break;
     /*case '4':
        //PLAYERS = 2;
        MENU = 2;
        //AI = TRUE;
        break;  */ 
    default:
        PLAYERS = 1;
    }

    wborder(menu, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    mvprintw(max_y/2 - 1, max_x/2 - width/2 + 5, "                            ");
    mvprintw(max_y/2, max_x/2 - width/2 + 5, "                         ");
    mvprintw(max_y/2 + 1, max_x/2 - width/2 + 5, "                        ");
    mvprintw(max_y/2 + 2, max_x/2 - width/2 + 5, "                        ");
    wrefresh(menu);
    delwin(menu);
    refresh();
}

int lwr_case(int key_pressed) {
    int res = 0;
    switch(key_pressed) {
    case 'W':
        res = 'w';
        break;
    case 'S':
        res = 's';
        break;
    case 'A':
        res = 'a';
        break;
    case 'D':
        res = 'd';
        break;
    }
    return res > 0 ? res: key_pressed;
}

void repairSeed(food_t f[], size_t nfood, struct snake_t *head)
{
	for(size_t s = 0; s < PLAYERS; s++){
    for( size_t i=0; i<head->tsize; i++ )
        for( size_t j=0; j<nfood; j++ )
        {
            /* Если хвост совпадает с зерном */
            //...нужно написать код...//
            if (f[j].x == head[s].tail[i].x && f[j].y == head[s].tail[i].y) 
			{
				putFoodSeed(&f[j]);
				//refreshFood(food, SEED_NUMBER);// Обновляем еду
			}
        }
    for( size_t i=0; i<nfood; i++ )
        for( size_t j=0; j<nfood; j++ )
        {
            /* Если два зерна на одной точке */
            //...нужно написать код...//
            if (i!=j && f[j].x==f[i].x && f[j].y == f[i].y)
			{
				putFoodSeed(&f[j]);
				//refreshFood(food_t, SEED_NUMBER);// Обновляем еду
			}
        }
	}
}

//======Добавление ИИ========================================================   

int distance(const snake_t snake, const struct food_t food) {   // вычисляет количество ходов до еды
    return (abs(snake.x - food.x) + abs(snake.y - food.y));
}
//Для автоизменения направления напишем функцию
//Она определяет ближайшую к себе еду и движется по направлению к ней
void autoChangeDirection(snake_t *snake, food_t food[], int foodSize)
{
    int pointer = 0;
    for (int i = 1; i < foodSize; i++) {   // ищем ближайшую еду
        pointer = (distance(*snake, food[i]) < distance(*snake, food[pointer])) ? i : pointer;
    }
    if ((snake->direction == RIGHT || snake->direction == LEFT) &&
        (snake->y != food[pointer].y)) {  // горизонтальное движение
        snake->direction = (food[pointer].y > snake->y) ? DOWN : UP;
    } else if ((snake->direction == DOWN || snake->direction == UP) &&
               (snake->x != food[pointer].x)) {  // вертикальное движение
        snake->direction = (food[pointer].x > snake->x) ? RIGHT : LEFT;
    }
}
//========================================================================   

int32_t update(snake_t *head, food_t *food) {
	
    int key_pressed = 0;
    int res = 0;
    while( key_pressed !=  STOP_GAME && !res ) {
        key_pressed = getch();
        key_pressed = lwr_case(key_pressed);
        repairSeed(food, SEED_NUMBER, head);

        for(uint8_t i = 0; i < PLAYERS && !res; i++) {
            setColor(i + 1);
            go(&head[ i ]);
            goTail(&head[ i ]);
            haveEat(&head[ i ], food);
            res = CheckCollisionWithTail(&head[ i ]);

            if(res == WIN && PLAYERS == 2) {
                switch(i) {
                case 0:
                    res = PLR_1_WIN;
                    break;
                case 1:
                    res = PLR_2_WIN;
                    break;
                }
            }
            else if(res == LOSE && PLAYERS == 2) {
                switch(i) {
                case 0:
                    res = PLR_2_WIN;
                    break;
                case 1:
                    res = PLR_1_WIN;
                    break;
                }
            }

            timeout(100);
            changeDirection(&head[ i ], key_pressed, i);

            if( i > 0 && AI == TRUE ) {
                autoChangeDirection(head, food, SEED_NUMBER);
            }
            if (i > 0 && MENU == 2)
			{
				clear();
				/*wborder(menu, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    mvprintw(max_y/2 - 1, max_x/2 - width/2 + 5, "                            ");
    mvprintw(max_y/2, max_x/2 - width/2 + 5, "                         ");
    mvprintw(max_y/2 + 1, max_x/2 - width/2 + 5, "                        ");
    mvprintw(max_y/2 + 2, max_x/2 - width/2 + 5, "                        ");
    wrefresh(menu);
    delwin(menu);
    refresh();*/
			}
        }
        refreshFood(food, SEED_NUMBER);// Обновляем еду
    }
    return res;
}



void init_game(snake_t *head, food_t *food) {

    for(uint8_t i = 0; i < PLAYERS; i++) {
        initSnake( &head[ i ], START_TAIL_SIZE, 10 * (i + 1), 10 * (i + 1) );
    }
    initFood(food, MAX_FOOD_SIZE);
    putFood(food, SEED_NUMBER);// Кладем зерна
}

void init_screen() {

    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);

    curs_set(FALSE);    //Отключаем курсор
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    mvprintw(0, 5, "Movement: ARROWS for PLAYER 1; WSAD for PLAYER 2. Eat %d '$' for VICTORY! Press 'F10' for EXIT", WIN_COUNT);
    //mvprintw(1, 6, "count: %d",count_food());

}

void EndGame(int resultGame) {
    int max_x = 0, max_y = 0;
    snake_t *snake = ( snake_t* ) malloc( PLAYERS * sizeof( snake_t ) );
	food_t *food = ( food_t* ) malloc( MAX_FOOD_SIZE * sizeof( food_t ) );
	int32_t game_result = 0;
    getmaxyx(stdscr, max_y, max_x);
    switch(resultGame) {
    case LOSE:
        clear();                                        // Очищает экран терминала
        setColor(3);
		mvprintw(max_y / 2, max_x / 2, "You LOSE! Restart in 3 seconds..."); // Выводит сообщение о проигрыше
		refresh();                                      // Обновляет экран, чтобы отобразить изменения
		sleep(3);                                       // Задержка на 3 секунды
		// Перезапуск игры
		clear();                                        // Очищает экран терминала
		startMenu();
		init_game(snake, food);
		game_result = update(snake, food);
		EndGame(game_result);
    
		//snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
		//initSnake(snake, START_TAIL_SIZE, 10, 10);      // Инициализирует змейку с начальным размером и позициями
		//mvprintw(0, 1, "Use arrows for control. Press 'F10' for EXIT"); // Инструкции для управления
		//refresh();                                      // Обновляет экран, чтобы отобразить изменения
        //mvprintw(max_y / 2, max_x / 2, "YOU LOSE");
        //while(getch() != STOP_GAME);
        break;
    case WIN:
        /*setColor(4);
        mvprintw(max_y / 2, max_x / 2, "VICTORY");
        while(getch() != STOP_GAME);*/
         clear();                                        // Очищает экран терминала
        setColor(3);
		mvprintw(max_y / 2, max_x / 2, "You WIN! Restart in 3 seconds..."); // Выводит сообщение о проигрыше
		refresh();                                      // Обновляет экран, чтобы отобразить изменения
		sleep(3);                                       // Задержка на 3 секунды
		// Перезапуск игры
		clear();                                        // Очищает экран терминала
		startMenu();
		//init_game(snake, food);
		//game_result = update(snake, food);
		EndGame(game_result);
        break;
    case PLR_1_WIN:
        clear();                                        // Очищает экран терминала
        setColor(3);
		mvprintw(max_y / 2, max_x / 2, "PLAYER 1 WIN! Restart in 3 seconds..."); // Выводит сообщение о проигрыше
		refresh();                                      // Обновляет экран, чтобы отобразить изменения
		sleep(3);                                       // Задержка на 3 секунды
		// Перезапуск игры
		clear();                                        // Очищает экран терминала
		startMenu();
		init_game(snake, food);
		game_result = update(snake, food);
		EndGame(game_result);
        break;
    case PLR_2_WIN:
        clear();                                        // Очищает экран терминала
        setColor(3);
		mvprintw(max_y / 2, max_x / 2, "PLAYER 2 WIN! Restart in 3 seconds..."); // Выводит сообщение о проигрыше
		refresh();                                      // Обновляет экран, чтобы отобразить изменения
		sleep(3);                                       // Задержка на 3 секунды
		// Перезапуск игры
		clear();                                        // Очищает экран терминала
		startMenu();
		init_game(snake, food);
		game_result = update(snake, food);
		EndGame(game_result);
        break;
    case STOP_GAME:
		break;
    }

}
int main()
{
	init_screen();
    startMenu();

    snake_t *snake = ( snake_t* ) malloc( PLAYERS * sizeof( snake_t ) );
    food_t *food = ( food_t* ) malloc( MAX_FOOD_SIZE * sizeof( food_t ) );
    int32_t game_result = 0;

    init_game(snake, food);
    game_result = update(snake, food);
    EndGame(game_result);

    for(uint8_t i = 0; i < PLAYERS; i++) {
        free(snake[ i ].tail);
    }
    free(snake);
    endwin(); // Завершаем режим curses mod
    return 0;
/*snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
    initSnake(snake,START_TAIL_SIZE,10,10); //инициализируем змейку
    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Отключаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    curs_set(FALSE);    //Отключаем курсор
    mvprintw(0, 0,"Use arrows or WSAD for control. Eat %d '$' for grow up. Press 'F10' for EXIT");
    //timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    //initFood(food, MAX_FOOD_SIZE);
    //putFood(food, SEED_NUMBER);// КЛАДЕМ ЗЕРНА
    int key_pressed=0;
    int player=1;
    while( key_pressed != STOP_GAME )
    {
        key_pressed = getch(); // Считываем клавишу
        go(snake);
        goTail(snake);
        haveEat(snake, food);
        CheckCollisionWithTail(snake);
        timeout(100); // Задержка при отрисовке
        refreshFood(food, SEED_NUMBER);// ОБНОВЛЯЕМ ЕДУ
        changeDirection(snake, key_pressed, player);
    }
    free(snake->tail);//освобождаем память под хвост
    free(snake);//освобождаем память под змейку
    endwin(); // Завершаем режим curses mod
    return 0;*/
}
