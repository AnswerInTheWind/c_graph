#include <graphics.h>      // ������Ҫ�������ͼ�ο�
#include <conio.h>

void init_graph()
{
    initgraph(640, 480);   // ����� TC ��������
	rectangle(100,100,200,200);//���ƾ��Σ����Ͻ�����100,100, ���½�����200,200
    getch();               // �����������
    closegraph();          // �ر�ͼ�ν���
}