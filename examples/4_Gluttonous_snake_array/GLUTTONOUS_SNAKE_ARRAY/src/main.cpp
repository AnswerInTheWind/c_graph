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

typedef struct point
{
    uint8_t x;//x 0-(GAME_WIDTH-1)
	uint8_t y;//y 0-(GAME_HEIGHT-1)
}Point;

typedef struct snake
{
	Point snake_header;
	Point snake_position[GAME_WIDTH*GAME_HEIGHT];//蛇的最大长度，也是游戏范围
	uint8_t snake_length;
}Snake;

uint8_t key_value[VALID_KEYS_NUMBER] = {'w','a','s','d','W','A','S','D'};
uint8_t move_dir = DIR_UP;

uint8_t top_lift_x = 5;
uint8_t top_lift_y = 4;
const uint8_t SNAKE_BODY_MAX_NUM = GAME_WIDTH*GAME_HEIGHT;

Snake snake;
Point food;
uint8_t map[GAME_WIDTH][GAME_HEIGHT];

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
uint8_t get_dir()
{
	uint8_t key_value;
	key_value = get_input();
	switch (key_value)
	{
		case 'w':
		case 'W':
			if(move_dir == DIR_DOWN)
				return 0;
			move_dir = DIR_UP;
			return 1;
		case 'a':
		case 'A':
			if(move_dir == DIR_RIGHT)
				return 0;
			move_dir = DIR_LEFT;
			return 1;
		case 's':
		case 'S':
			if(move_dir == DIR_UP)
				return 0;
			move_dir = DIR_DOWN;
			return 1;
			break;
		case 'd':
		case 'D':
			if(move_dir == DIR_LEFT)
				return 0;
			move_dir = DIR_RIGHT;
			return 1;
			break;
		default:
			return 0;
	}
}

//初始化蛇头的位置
void init_snake()
{
	uint8_t i = 0;

	snake.snake_header.x = 5;
	snake.snake_header.y = 4;

	snake.snake_position[0].x = 5;
	snake.snake_position[0].y = 4;

	snake.snake_position[1].x = 6;
	snake.snake_position[1].y = 4;
	
	snake.snake_position[2].x = 7;
	snake.snake_position[2].y = 4;
	
	for(i = 3;i<SNAKE_BODY_MAX_NUM;i++)
	{
		snake.snake_position[i].x = 0;
		snake.snake_position[i].y = 0;
	}

	snake.snake_length = 3;

	for(i= 0;i<snake.snake_length;i++)
		draw_square(snake.snake_position[i].x*SQUARE_LEN,snake.snake_position[i].y*SQUARE_LEN,SQUARE_LEN);//画新方块
}

void init_map()
{
	uint8_t i= 0;
	uint8_t j = 0;

	for(i = 0;i<GAME_WIDTH;i++)
	{
		for(j = 0;j<GAME_HEIGHT;j++)
		{
			map[i][j] = 0;
		}
	}
}

void snake_mapping()
{
	uint8_t i = 0;
	for(i = 0;i<snake.snake_length;i++)
		map[snake.snake_position[i].x][snake.snake_position[i].y] = 1;
}

void snake_add_mapping(uint8_t x,uint8_t y)
{
	map[x][y] = 1;
}

void snake_delete_mapping(uint8_t x,uint8_t y)
{
	map[x][y] = 0;
} 

//在非蛇身的位置产生食物
//1.循环，直到食物落在非蛇身位置 此处使用的是这个方法
//2.将没有蛇身的的点生成数组，在数组中随机
void generate_food()
{
	do 
	{
		food.x=rand()%GAME_WIDTH;
		food.y=rand()%GAME_HEIGHT;
	} while (map[food.x][food.y]==1);		//随机产生食物在非蛇的位置,map[food.x][food.y] == 0;表示此位置没有蛇身
	draw_square(food.x*SQUARE_LEN,food.y*SQUARE_LEN,SQUARE_LEN);//画新方块
}

void init_game()
{
	init_graph();

	rand_init();
	
	init_snake();

	init_map();

	snake_mapping();

	generate_food();

}

uint8_t change_snake_header_point()
{
	switch (move_dir)
	{
		case DIR_UP:
			if(snake.snake_header.y == 0)
				return 0;
			snake.snake_header.y--;
			break;
		case DIR_LEFT:
			if(snake.snake_header.x == 0)
				return 0;
			snake.snake_header.x--;
			break;
		case DIR_DOWN:
			if(snake.snake_header.y == (GAME_HEIGHT-1))
				return 0;
			snake.snake_header.y++;
			break;
		case DIR_RIGHT:
			if(snake.snake_header.x == (GAME_WIDTH-1))
				return 0 ;
			snake.snake_header.x++;
			break;
	}
	return 1;
}

void game_over()
{
	while(1);
}



void move_snake_body()
{
	uint8_t i = 0;
//	snake_delete_mapping(snake.snake_position[snake.snake_length-1].x,snake.snake_position[snake.snake_length-1].y);
//	clear_square(snake.snake_position[snake.snake_length-1].x*SQUARE_LEN,snake.snake_position[snake.snake_length-1].y*SQUARE_LEN,SQUARE_LEN);
	for(i = 0;i<snake.snake_length-1;i++)
	{
		snake.snake_position[snake.snake_length-1-i].x = snake.snake_position[snake.snake_length-2-i].x;
		snake.snake_position[snake.snake_length-1-i].y = snake.snake_position[snake.snake_length-2-i].y;
	}
	snake.snake_position[0].x = snake.snake_header.x;
	snake.snake_position[0].y = snake.snake_header.y;
	snake_add_mapping(snake.snake_position[0].x,snake.snake_position[0].y);
	draw_square(snake.snake_position[0].x*SQUARE_LEN,snake.snake_position[0].y*SQUARE_LEN,SQUARE_LEN);//画新方块

}

void move_snake()
{
	if(!change_snake_header_point())
		game_over();

}

void get_command()
{
	uint8_t i = 0;
	for(i = 0;i<5;i++)
	{
		delay(100);//延时200ms
		if(get_dir())
			break;
	}
}

void snake_process()
{
	get_command();
	move_snake();
}

void food_process()
{
	if((snake.snake_position[0].x == food.x) && (snake.snake_position[0].y == food.y))
	{
		generate_food();
		snake.snake_length++;
		snake.snake_position[snake.snake_length-1].x = snake.snake_position[snake.snake_length-2].x;
		snake.snake_position[snake.snake_length-1].y = snake.snake_position[snake.snake_length-2].y;	
	}
	else
	{
		snake_delete_mapping(snake.snake_position[snake.snake_length-1].x,snake.snake_position[snake.snake_length-1].y);
		clear_square(snake.snake_position[snake.snake_length-1].x*SQUARE_LEN,snake.snake_position[snake.snake_length-1].y*SQUARE_LEN,SQUARE_LEN);
	}
	
}

void process()
{
	while(1)
	{
		snake_process();
		food_process();
		move_snake_body();

		
	}
}

int main (void)
{
	uint32_t time_now = 0;
	uint32_t time_last = 0;

	init_game();
	
	process();//贪吃蛇进程

    closegraph();          // 关闭图形界面
	return 0;
}
