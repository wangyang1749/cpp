#include "stdafx.h"
#include<graphics.h>
#include<conio.h>
int main()
{
	//绘制窗口
	initgraph(560,560);  
	
	//绘制格子
	for(int i=0;i<=560;i+=70){
		line(i,0,i,560);
		line(0,i,560,i);
	}
	
	//绘制选色区
	setfillcolor(RED);
	fillrectangle(0,490,70,560);
	setfillcolor(GREEN);
	fillrectangle(70,490,140,560);
	setfillcolor(BLUE);
	fillrectangle(140,490,210,560);
	setfillcolor(YELLOW);
	fillrectangle(210,490,280,560);
	setfillcolor(LIGHTBLUE);
	fillrectangle(280,490,350,560);
	setfillcolor(WHITE);
	fillrectangle(350,490,420,560);
	setfillcolor(MAGENTA);
	fillrectangle(420,490,490,560);
	setfillcolor(CYAN);
	fillrectangle(490,490,560,560);
 
 	MOUSEMSG m;         //定义鼠标信息
	COLORREF c;         //颜色值	
	while(1){
	m=GetMouseMsg();    //获得一条鼠标信息
	switch(m.uMsg){
	case WM_LBUTTONDOWN: {          //单击选色区
		if(m.x>=0&&m.x<=70&&m.y>=490&&m.y<=560)         
			c=getpixel(m.x,m.y);    //取当前鼠标所在点的颜色
		if(m.x>70&&m.x<=140&&m.y>=490&&m.y<=560)
			c=getpixel(m.x,m.y);
		if(m.x>140&&m.x<=210&&m.y>=490&&m.y<=560)
			c=getpixel(m.x,m.y);
		if(m.x>210&&m.x<=280&&m.y>=490&&m.y<=560)
			c=getpixel(m.x,m.y);			
		if(m.x>280&&m.x<=350&&m.y>=490&&m.y<=560)
			c=getpixel(m.x,m.y);
		if(m.x>350&&m.x<=420&&m.y>=490&&m.y<=560)
			c=getpixel(m.x,m.y);
		if(m.x>420&&m.x<=490&&m.y>=490&&m.y<=560)
			c=getpixel(m.x,m.y);
		if(m.x>490&&m.x<=560&&m.y>=490&&m.y<=560)
			c=getpixel(m.x,m.y);
						}break;
	case WM_LBUTTONDBLCLK:        //双击涂色区
		if(m.x>=0&&m.x<=560&&m.y>=0&&m.y<=560){
         setfillcolor(c);         //填充颜色为c
		 for(int i=0;i<8;i++)     //寻找当前鼠标所在的i,j
			 for(int j=0;j<8;j++){
           if(m.x>=(70*i)&&m.x<=(70*i+70)&&m.y>=(70*j)&&m.y<=(70*j+70))
           fillrectangle(70*i,70*j,70*i+70,70*j+70);
			 }
		}break;
		case WM_RBUTTONUP:return 0;
	
	}
	}
	getch();       //等待按键结束
	closegraph();//关闭窗口
	return 0;
}
