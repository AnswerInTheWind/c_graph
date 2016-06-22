#include <stdio.h>
#include <conio.h>
#include <graphics.h>      // 就是需要引用这个图形库
#include <time.h>

#include "component.h"
#include "graph.h"


#define SQUARE_LEN 80
#define VALID_KEYS_NUMBER 8

#define GAME_WIDTH	10
#define GAME_HEIGHT	8

#define DIR_UP		0
#define DIR_LEFT	1
#define DIR_DOWN	2
#define DIR_RIGHT	3

uint8_t key_value[VALID_KEYS_NUMBER] = {'w','a','s','d','W','A','S','D'};
uint8_t move_dir = DIR_UP;

uint8_t top_lift_x = 5;
uint8_t top_lift_y = 4;

typedef struct snake
{
    uint8_t x;//x 0-(GAME_WIDTH-1)
	uint8_t y;//y 0-(GAME_HEIGHT-1)
}Snake;

//获取按键,读取到键值返回键值，没有返回0
uint8_t get_input()
{
	uint8_t i = 0;
	for(i = 0;i<VALID_KEYS_NUMBER;i++)
	{
		if(GetAsyncKeyState(key_value[i]))//判断在上一次调用这个函数到这一次调用期间，是否有键被按下
		{
			printf("%d",key_value[i]);
			return key_value[i];
		}
	}
	return 0;
}

//获取蛇移动的方向
void get_dir()
{
	uint8_t key_value;
	key_value = get_input();
	switch (key_value)
	{
		case 'w':
		case 'W':
			move_dir = DIR_UP;
			break;
		case 'a':
		case 'A':
			move_dir = DIR_LEFT;
			break;
		case 's':
		case 'S':
			move_dir = DIR_DOWN;
			break;
		case 'd':
		case 'D':
			move_dir = DIR_RIGHT;
			break;
		default:
			break;
	}
}

//初始化蛇头的位置
void init_snake()
{
	
}

void init_game()
{
	init_graph();
	rand_init();
}

void get_snake_header()
{
	switch (move_dir)
	{
		case DIR_UP:
			if(top_lift_y == 0)
				return;
			top_lift_y--;
			break;
		case DIR_LEFT:
			if(top_lift_x == 0)
				return;
			top_lift_x--;
			break;
		case DIR_DOWN:
			if(top_lift_y == (GAME_HEIGHT-1))
				return;
			top_lift_y++;
			break;
		case DIR_RIGHT:
			if(top_lift_x == (GAME_WIDTH-1))
				return;
			top_lift_x++;
			break;
	}
}

int main (void)
{
	time_t time_now = 0;
	time_t time_last = 0;



	init_game();

	draw_square(top_lift_x*SQUARE_LEN,top_lift_y*SQUARE_LEN,SQUARE_LEN);
	
	time_now = time(NULL);//单位:s
	time_last = time_now;
	while(1)
	{	
		get_dir();
		
		time_now = time(NULL);
		if(time_now - time_last >= 1)
		{
			clear_square(top_lift_x*SQUARE_LEN,top_lift_y*SQUARE_LEN,SQUARE_LEN);//擦除之前的方块
			get_snake_header();
		//	top_lift_x = rand() % 10;
		//	top_lift_y = rand() % 10;
			
			time_last = time_now;
		//	i++;

			draw_square(top_lift_x*SQUARE_LEN,top_lift_y*SQUARE_LEN,SQUARE_LEN);//画新方块
		}
		

	}

	getch();               // 按任意键继续
    closegraph();          // 关闭图形界面
	return 0;
}
