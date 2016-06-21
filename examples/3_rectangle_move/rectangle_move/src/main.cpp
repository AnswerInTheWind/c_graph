#include <stdio.h>
#include <conio.h>
#include <graphics.h>      // ������Ҫ�������ͼ�ο�
#include <time.h>

#include "graph.h"

#define SQUARE_LEN 100

int main (void)
{
	time_t time_now = 0;
	time_t time_last = 0;

	uint8_t i = 0;

	init_graph();

	draw_square(0,0,SQUARE_LEN);
	
	time_now = time(NULL);//��λ:s
	time_last = time_now;
	while(1)
	{
		time_now = time(NULL);
		if(time_now - time_last >= 1)
		{
			time_last = time_now;
			i++;
			draw_square(i*50,i*50,SQUARE_LEN);
		}

	}

	getch();               // �����������
    closegraph();          // �ر�ͼ�ν���
	return 0;
}