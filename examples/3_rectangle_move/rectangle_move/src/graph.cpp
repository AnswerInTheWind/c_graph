#include <graphics.h>      // ������Ҫ�������ͼ�ο�
#include <conio.h>
#include "graph.h"


void init_graph()
{
    initgraph(640, 480);   //����640*480
}

void draw_square(uint16_t x,uint16_t y,uint8_t length)
{
	rectangle(x,y,x+length,x+length);
}