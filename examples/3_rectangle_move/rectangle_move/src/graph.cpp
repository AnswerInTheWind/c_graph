#include <graphics.h>      // 就是需要引用这个图形库
#include <conio.h>
#include "graph.h"


void init_graph()
{
    initgraph(640, 480);   //像素640*480
}

void draw_square(uint16_t x,uint16_t y,uint8_t length)
{
	rectangle(x,y,x+length,x+length);
}