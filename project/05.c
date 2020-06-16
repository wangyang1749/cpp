/**************************************************************
** 文 件 名：wuziqi.cpp
** 功    能：扫雷
** 作    者：褚禹江
** 创建日期：2018.05.20
** 修改日期：2018.06.22
** https://blog.csdn.net/weixin_41973135/article/details/81106486
**************************************************************/
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <string.h>

/**************************************************************/
void init_system();               //初始化系统
void close_system();               //关闭系统
void init_game();                  //初始化游戏界面

void m_white();                    //白棋
void m_black();                    //黑棋

void m_play();                     //下棋
int  m_win();                      //判断胜负

void m_replay();                   //重玩

void draw_bine();                  //覆盖棋  悔棋
/**************************************************************/
int m_bine[22][22] ;               //定义棋子数组
int m_w = 15,m_h = 15,m_wh = 25;   //定义行列数，每格像素数
int m_x0 = 25,m_y0 = 25;           //初始棋子位置
int m_x9 = 375,m_y9 = 375;         //最终棋子位置
int flag;

#define LIGHTBROWN RGB(255,211,155)//覆盖棋颜色

/**************************************************************/
/**************************************************************/
void main()
{
    init_system();

    m_play();

    close_system();
}

/*************************************************************/
void init_system()  //初始化系统
{
    init_game();
}

void init_game()    //初始化游戏界面
{
    IMAGE img;
    loadimage(&img, "test.jpg");//导入test图片用作棋盘
    int w, h;
    w = img.getwidth();
    h = img.getheight();
    initgraph(w+150,h);
    putimage( 0, 0, &img);

    setlinecolor(WHITE);
    setfillcolor(BLACK);
    fillrectangle(w, 0, w+130, 60);
    settextstyle(20,0,"楷体");
    outtextxy(w+10,5 ,"黑方:玩家一");
    outtextxy(w+10,30 ,"白方:玩家二");
}

void close_system()  //关闭系统
{
    closegraph();
}

/*********************************************/
void m_white()  //将画笔变为白色
{
    setlinecolor(WHITE);
    setfillcolor(WHITE);
}

void m_black()  //将画笔变为黑色
{
    setlinecolor(BLACK);
    setfillcolor(BLACK);
}

void draw_bine(int x,int y)//将背景覆盖实现悔棋
{
    setcolor(LIGHTBROWN);
    circle(x,y,11);
    setfillcolor(LIGHTBROWN);
    floodfill(x,y,LIGHTBROWN);
    setcolor(BLACK);
    line(x-11-1,y-1,x+11-1,y-1);
    line(x-1,y-11-1,x-1,y+11-1);   
}

/**********************************************/
void m_play()  //下棋
{
    MOUSEMSG m_mouse;
    int i,j;
    while(1)
    {
        flag = 0;
        m_mouse = GetMouseMsg();
        switch(m_mouse.uMsg)
        {
            int a,b;
            case WM_LBUTTONDOWN:  //左键下黑棋
               {
                    if(m_mouse.x > m_x0-m_wh/2 && m_mouse.x < m_x9+m_wh/2&&
                     m_mouse.y > m_y0-m_wh/2 && m_mouse.y < m_y9+m_wh/2)  //判断是否在棋盘内
                  {
                      for(i = 0 ; i <= 15 ; i++)
                      {
                          for(j = 0 ; j <= 15 ; j++)
                          {
                              if(m_mouse.x >= m_x0-m_wh/2   +i*m_wh &&
                                 m_mouse.x <= m_x0+m_wh/2   +i*m_wh &&
                                 m_mouse.y >= m_y0-m_wh/2   +j*m_wh &&
                                 m_mouse.y <= m_y0+m_wh/2   +j*m_wh)      //纠正棋子位置，使其落在两线交叉点
                              {
                                  a = i + 1;
                                  b = j + 1;
                                  m_mouse.x = a*m_wh;
                                  m_mouse.y = b*m_wh;
                                  break;
                              }
                          }
                      }                  
                      if(m_bine[a][b] != 0)  //如果此处有棋子则不能下棋
                        continue;
                      m_bine[a][b] = 1;
                      m_black();
                      fillcircle(m_mouse.x,m_mouse.y,10);
                  }
                  flag = m_win();
                  if(flag == 1)  //判断是否胜利
                  {
                      outtextxy(400,250 ,"按任意键");
                      outtextxy(400,270 ,"再来一盘");
                      getch();
                      m_replay();
                  }
                  else
                    m_win();
               }
              break;
            case WM_RBUTTONDOWN :   //右键下白棋
               {
                    if(m_mouse.x > m_x0-m_wh/2 && m_mouse.x < m_x9+m_wh/2&&
                     m_mouse.y > m_y0-m_wh/2 && m_mouse.y < m_y9+m_wh/2)  //判断是否在棋盘内
                  {
                      for(i = 0 ; i <= 15 ; i++)
                      {
                          for(j = 0 ; j <= 15 ; j++)
                          {
                              if(m_mouse.x >= m_x0-m_wh/2   +i*m_wh &&
                                 m_mouse.x <= m_x0+m_wh/2   +i*m_wh &&
                                 m_mouse.y >= m_y0-m_wh/2   +j*m_wh &&
                                 m_mouse.y <= m_y0+m_wh/2   +j*m_wh)      //纠正棋子位置，使其落在两线交叉点
                              {
                                  a = i + 1;
                                  b = j + 1;
                                  m_mouse.x = a*m_wh;
                                  m_mouse.y = b*m_wh;
                                  break;
                              }
                          }
                      }
                      if(m_bine[a][b] != 0)  //如果此处有棋子则不能下棋
                        continue;
                      m_bine[a][b] = 2;
                      m_white();
                      fillcircle(m_mouse.x,m_mouse.y,10);
                  }
                  flag = m_win();
                  if(m_win() == 1)  //判断是否胜利
                  {
                      outtextxy(400,250 ,"按任意键");
                      outtextxy(400,270 ,"再来一盘");
                      getch();
                      m_replay();
                  }
                  else
                    m_win();
               }
                break;
            case WM_MBUTTONDOWN:
                {
                    if(m_mouse.x > m_x0-m_wh/2 && m_mouse.x < m_x9+m_wh/2&&
                     m_mouse.y > m_y0-m_wh/2 && m_mouse.y < m_y9+m_wh/2)  //判断是否在棋盘内
                  {
                      for(i = 0 ; i <= 15 ; i++)
                      {
                          for(j = 0 ; j <= 15 ; j++)
                          {
                              if(m_mouse.x >= m_x0-m_wh/2   +i*m_wh &&
                                 m_mouse.x <= m_x0+m_wh/2   +i*m_wh &&
                                 m_mouse.y >= m_y0-m_wh/2   +j*m_wh &&
                                 m_mouse.y <= m_y0+m_wh/2   +j*m_wh)      //纠正棋子位置，使其落在两线交叉点
                              {
                                  a = i + 1;
                                  b = j + 1;
                                  m_mouse.x = a*m_wh;
                                  m_mouse.y = b*m_wh;
                                  break;
                              }
                          }
                      }
                      if(m_bine[a][b] == 0) 
                        continue;
                      m_bine[a][b] = 0;  //将本存在棋的数组赋0
                      draw_bine(m_mouse.x,m_mouse.y);
                  }
               }
              break;
        }
    }
}

void m_replay()//重新游戏
{
    memset(m_bine,0,sizeof(m_bine));//初始化数组
    init_game();
}

int m_win()  //判断是否胜利
{
    int i,j;
    for(i = 1 ; i <= 15 ; i++)
    {
        for(j = 1 ; j <= 15 ; j++)
            {
                if(m_bine[i][j] == 1 && m_bine[i+1][j] == 1 && m_bine[i+2][j] == 1 &&
                   m_bine[i+3][j] == 1 && m_bine[i+4][j] == 1)
                {
                    settextcolor(WHITE);
                    outtextxy(400,200 ,"the black win");
                    return 1;
                }
                else if(m_bine[i][j] == 1 && m_bine[i+1][j+1] == 1 && m_bine[i+2][j+2] == 1 &&
                        m_bine[i+3][j+3] == 1 && m_bine[i+4][j+4] == 1)
                {
                    settextcolor(WHITE);
                    outtextxy(400 ,200 ,"the black win");
                    return 1;
                }
                else if(m_bine[i][j+1] == 1 && m_bine[i][j+2] == 1 && m_bine[i][j+3] == 1 &&
                        m_bine[i][j] == 1 && m_bine[i][j+4] == 1)
                {
                    settextcolor(WHITE);
                    outtextxy(400 ,200,"the black win");
                    return 1;
                }        
                else if(i >= 3 && m_bine[i][j] == 1 && m_bine[i+1][j-1] == 1 && m_bine[i+2][j-2] == 1 &&
                        m_bine[i+3][j-3] == 1 && m_bine[i+4][j-4] == 1)
                {
                    settextcolor(WHITE);
                    outtextxy(400 ,200 ,"the black win");
                    return 1;
                }
                else if(j >= 3 && m_bine[i][j] == 1 && m_bine[i+1][j-1] == 1 && m_bine[i+2][j-2] == 1 &&
                        m_bine[i+3][j-3] == 1 && m_bine[i+4][j-4] == 1)
                {
                    settextcolor(WHITE);
                    outtextxy(400 ,200 ,"the black win");
                    return 1;
                }
                else if(m_bine[i][j] == 2 && m_bine[i+1][j] == 2 && m_bine[i+2][j] == 2 &&
                        m_bine[i+3][j] == 2 && m_bine[i+4][j] == 2)
                {
                    settextcolor(WHITE);
                    outtextxy(400,200 ,"the  white win");
                    return 1;
                }
                else if(m_bine[i][j] == 2 && m_bine[i+1][j+1] == 2 && m_bine[i+2][j+2] == 2 && 
                        m_bine[i+3][j+3] == 2 && m_bine[i+4][j+4] == 2)
                {
                    settextcolor(WHITE);
                    outtextxy(400 ,200 ,"the white win");
                    return 1;
                }
                else if(m_bine[i][j+1] == 2 && m_bine[i][j+2] == 2 && m_bine[i][j+3] == 2 && 
                        m_bine[i][j] == 2 && m_bine[i][j+4] == 2)
                {
                    settextcolor(WHITE);
                    outtextxy(400 ,200,"the white win");
                    return 1;
                }    
                else if(i >= 3 && j > 3 && m_bine[i][j] == 2 && m_bine[i+1][j-1] == 2 && m_bine[i+2][j-2] == 2 && 
                        m_bine[i+3][j-3] == 2 && m_bine[i+4][j-4] == 2)
                {
                    settextcolor(WHITE);
                    outtextxy(400 ,200 ,"the white win");
                    return 1;
                }
                else if(j >= 3 && m_bine[i][j] == 2 && m_bine[i+1][j-1] == 2 && m_bine[i+2][j-2] == 2 && 
                        m_bine[i+3][j-3] == 2 && m_bine[i+4][j-4] == 2)
                {
                    settextcolor(WHITE);
                    outtextxy(400 ,200 ,"the white win");
                    return 1;
                }
            }
    }
    return 0;
}  

