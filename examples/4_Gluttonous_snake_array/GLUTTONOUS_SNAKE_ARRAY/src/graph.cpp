#include <graphics.h>      // 就是需要引用这个图形库
#include <conio.h>

#include "component.h"
#include "graph.h"




COLORREF foreground_color = 0xFFFFFF;//前景色 白色
COLORREF background_color = 0x000000;//背景色 黑色

void init_graph()
{

	initgraph(800, 640);   //像素640*480
	setlinecolor(foreground_color);
}

void draw_square(uint16_t x,uint16_t y,uint8_t length)
{
	setlinecolor(foreground_color);;//将背景色设置成绘图前景色
	rectangle(x,y,x+length-1,y+length-1);
}

void draw_line(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	line(x1,y1,x2,y2);
}

void clear_square(uint16_t x,uint16_t y,uint8_t length)
{
	setlinecolor(background_color);//将背景色设置成绘图前景色
	
	rectangle(x,y,x+length-1,y+length-1);

}