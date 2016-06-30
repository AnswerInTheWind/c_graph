#include <graphics.h>      // ������Ҫ�������ͼ�ο�
#include <conio.h>

#include "component.h"
#include "graph.h"




COLORREF foreground_color = 0xFFFFFF;//ǰ��ɫ ��ɫ
COLORREF background_color = 0x000000;//����ɫ ��ɫ

void init_graph()
{

	initgraph(800, 640);   //����640*480
	setlinecolor(foreground_color);
}

void draw_square(uint16_t x,uint16_t y,uint8_t length)
{
	setlinecolor(foreground_color);;//������ɫ���óɻ�ͼǰ��ɫ
	rectangle(x,y,x+length-1,y+length-1);
}

void draw_line(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	line(x1,y1,x2,y2);
}

void clear_square(uint16_t x,uint16_t y,uint8_t length)
{
	setlinecolor(background_color);//������ɫ���óɻ�ͼǰ��ɫ
	
	rectangle(x,y,x+length-1,y+length-1);

}