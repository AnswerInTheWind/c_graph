#include <graphics.h>      // 就是需要引用这个图形库
#include <conio.h>

void init_graph()
{
    initgraph(640, 480);   // 这里和 TC 略有区别
	rectangle(100,100,200,200);//绘制矩形，左上角坐标100,100, 右下角坐标200,200
    getch();               // 按任意键继续
    closegraph();          // 关闭图形界面
}