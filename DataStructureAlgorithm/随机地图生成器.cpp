#include<iostream>
#include<cstdlib>
#include<malloc.h>
#include<ctime>
using namespace std;

#ifndef _COMMON_
#define _COMMON_
//定义常量
#define OK 1
#define ERROR 0
#define TRUE -1
#define FALSE 0
#endif

#ifndef _BINARY_TREE_
#define _BINARY_TREE_
//定义地牢房间
typedef struct TElemType
{
    int x;//x坐标
    int y;//y坐标
    int width;//宽度
    int height;//高度
    int splitPoint;//建造墙的位置
    int splitVert;//建造墙的方向
}TElemType;
//定义二叉树
typedef struct BiTreeNode
{
    TElemType data;//房间数据
    struct BiTreeNode*lchild;//左孩子结点
    struct BiTreeNode*rchild;//右孩子结点
}BiTreeNode,*BiTree;
#endif // _BINARY_TREE_

//创建二叉树
int CreateBiTree(BiTree &T)
{
    //分配内存
    T=(BiTree)malloc(sizeof(BiTreeNode));
    if(T==NULL)
    {
        cout<<"内存分配失败"<<endl;
        exit(-1);
    }
    T->lchild=NULL;
    T->rchild=NULL;
    return OK;
}
//销毁二叉树
int DestroyBiTree(BiTree &T)
{
    //后序遍历二叉树，回收结点内存
    if(T->lchild!=NULL)
        DestroyBiTree(T->lchild);
    if(T->rchild!=NULL)
        DestroyBiTree(T->rchild);
    //释放内存
    free(T);
    T=NULL;
    return OK;
}
//判断二叉树是否为空
int BiTreeEmpty(BiTree T)
{
    if(T->lchild==NULL&&T->rchild==NULL)
        return TRUE;
    else
        return FALSE;
}
//返回二叉树的高度
int BiTreeHeight(BiTree T)
{
    int h1,h2;
    if(T==NULL)
        return 0;
    h1=BiTreeHeight(T->lchild);
    h2=BiTreeHeight(T->rchild);
    if(h1>h2)
        return h1+1;
    else
        return h2+1;
}
//返回叶子结点数
int CountLeaf(BiTree T)
{
    if(T==NULL)
        //节点为空，返回0
        return 0;
    else if(BiTreeEmpty(T))
        //是叶子结点，返回1
        return 1;
    else
        //返回左、右子树叶子结点之和
        return CountLeaf(T->lchild)+CountLeaf(T->rchild);
    return 0;
}
//插入子结点
int InsertChild(BiTree T,int lr,TElemType e)
{
    BiTreeNode *pTmp;//临时结点指针
    //检查父结点是否为空
    if(T==NULL)
    {
        cout<<"父结点不能为空";
        return ERROR;
    }
    //为子结点分配内存
    pTmp=(BiTreeNode*)malloc(sizeof(BiTreeNode));
    if(pTmp==NULL)
    {
        cout<<"内存分配失败";
        exit(-1);
    }
    else
    {
        //初始化此结点
        pTmp->data=e;
        pTmp->lchild=NULL;
        pTmp->rchild=NULL;
    }
    //判断应为左孩子还是右孩子
    //若lr为0则插入左孩子，为1则插入右孩子
    if(lr==0)
    {
        //如原来左子树不为空，即销毁左子树
        if(T->lchild!=NULL)
            DestroyBiTree(T->lchild);
        T->lchild=pTmp;
    }
    else
    {
        //如原来右子树不为空，即销毁右子树
        if(T->rchild!=NULL)
            DestroyBiTree(T->rchild);
        T->rchild=pTmp;
    }
    return OK;
}
//获得所有叶子结点
int GetLeaves(BiTree T,BiTreeNode**&pLeaves)
{
    //定义叶子结点数组
    BiTreeNode**leaves;
    int count;//叶子结点总数
    int index=0;
    //定义两个栈，stack1保存结点，stack2保存结点的访问状态
    //栈的容量由树的高度决定
    //两个栈共用一个栈顶指针
    BiTreeNode**stack1;
    int *stack2;
    int height;//树的高度
    int top;//栈顶指针
    int tag;//访问状态标识
    //临时结点，用于记录当前结点的指针
    BiTreeNode*pCur;
    if(T==NULL)
    {
        cout<<"结点为空"<<endl;
        return 0;
    }
    //叶子结点数组，长度与叶子结点的数量一致
    count=CountLeaf(T);
    leaves=(BiTreeNode**)malloc(sizeof(BiTreeNode*)*count);
    //栈的最大深度，与树的深度一致
    height=BiTreeHeight(T);
    stack1=(BiTreeNode**)malloc(sizeof(BiTreeNode*)*(height+1));
    stack2=(int*)malloc(sizeof(int)*(height+1));
    //后序遍历二叉树
    pCur=T;//记录根结点
    index=0;//结点数组下标初始为0
    top=0;//栈顶指针初始为0
    tag=1;//循环标识，初始为1，遍历结束后为0
    do{
        while(pCur!=NULL)
        {
            stack1[++top]=pCur;//当前结点入栈
            stack2[top]=0;//状态设置为0，标识"左子树准备入栈"
            pCur=pCur->lchild;//移动到左子树，准备继续入栈
        }//左子树为NULL，停止入栈
        if(top==0)//若栈顶指针为0，说明已经访问到根结点
            tag=0;//停止遍历
        else if(stack2[top]==0)//若左子树已入栈
        {
            pCur=stack1[top]->rchild;//当前结点移动到右子树
            stack2[top]=1;//状态设置为1，标识"右子树准备入栈"
        }
        else//左右子树均已访问
        {
            pCur=stack1[top];//弹栈
            top--;
            if(BiTreeEmpty(pCur))//若是空树，就证明是叶子结点
                leaves[index++]=pCur;//将叶子结点保存到数组中
            pCur=NULL;//此结点已经访问，设为NULL,避免重复入栈
        }
    }while(tag!=0);
    //释放内存
    free(stack1);
    free(stack2);
    pLeaves=leaves;
    return count;
}
//打印二叉树
int PreOrderTraverse(BiTree&T,int depth)
{
    int i;
    if(T==NULL)
        return ERROR;
    //访问结点，打印当前房间的结构
    /*for(i=0;i<depth;i++)
        cout<<" ";*/
    cout<<"Room[x="<<T->data.x<<",y="<<T->data.y<<",width="<<T->data.width<<",height="<<T->data.height<<",splitVert="<<T->data.splitVert<<",splitPoint="<<T->data.splitPoint<<"]"<<endl;
    //继续访问子结点
    if(T->lchild!=NULL)
        PreOrderTraverse(T->lchild,depth+1);
    if(T->rchild!=NULL)
        PreOrderTraverse(T->rchild,depth+1);
    return OK;
}
//定义地图数据结构
#ifndef _DUNGEON_BUILDER_
#define _DUNGEON_BUILDER_
//定义地图常量
//地图的大小
#define COL 15
#define ROW 15
//地图的最大边长
#define MAX COL>ROW?COL:ROW
//最小房间的边长
#define MIN 5
//最小可分割房间的边长
#define LIMIT (2*MIN-1)
//地图元素
#define FLOOR 0//空地
#define WALL 1//墙
#define DOOR 2//门
#define UP_STAIRS 3//入口
#define DOWN_STAIRS 4//出口
//地图元素在控制台输出的符号
const char TILES[]=" #+IO";
//定义"点"结构体
typedef struct Point
{
    int x,y;
}Point;
#endif // _DUNGEON_BUILDER_
//地图数组
int gMap[ROW][COL];
//初始化地牢
void InitDungeon()
{
    int x,y;
    //初始化地牢数组
    for(y=0;y<ROW;y++)
        for(x=0;x<COL;x++)
        gMap[y][x]=FLOOR;
    //修建外墙，把地牢围起来
    for(x=0;x<COL;x++)
    {
        gMap[0][x]=WALL;
        gMap[ROW-1][x]=WALL;
    }
    for(y=0;y<ROW;y++)
    {
        gMap[y][0]=WALL;
        gMap[y][COL-1]=WALL;
    }
}
//显示地牢
void PrintDungeon()
{
    int x,y;
    for(y=0;y<ROW;y++)
    {
        for(x=0;x<COL;x++)
            cout<<TILES[gMap[y][x]];
        cout<<endl;
    }
}
//建造地下城

//实现房间分割
void SplitRoom(BiTree root)
{
    int nSplitVert;
    int nSplitPoint;
    TElemType sLeft;
    TElemType sRight;
    //判断房间是否还可以继续分割
    if(root->data.width>=LIMIT||root->data.height>=LIMIT)
    {
       //决定房间分割方向
       if(root->data.width<LIMIT)
       {
           //当房间的宽度不够时，修建一堵横着的墙，把房间分割成上下两半
           nSplitVert=0;
       }
       else if(root->data.height<LIMIT)
       {
           //当房间的高度不够时，修建一堵竖着的墙，把房间分割成左右两半
           nSplitVert=1;
       }
       else
       {
           //房间足够大，随机决定墙壁的方向
           nSplitVert=rand()%2;
       }
       //随机选择一个位置，建造一堵墙
       if(nSplitVert)//分成左右两半
       {
           //在data.x和data.width之间随机选择一个位置来建墙
           if(root->data.width==LIMIT)
           {
               //最小可分割房间，只能在固定位置建造墙壁
               nSplitPoint=(root->data.x+MIN-1);
           }
           else
           {
               nSplitPoint=(root->data.x+MIN-1)+rand()%(root->data.width-LIMIT);
           }
           //左边的房间
           sLeft.x=root->data.x;
           sLeft.y=root->data.y;
           sLeft.width=nSplitPoint-root->data.x+1;
           sLeft.height=root->data.height;
           sLeft.splitVert=-1;
           sLeft.splitPoint=-1;
           //右边的房间
           sRight.x=nSplitPoint;
           sRight.y=root->data.y;
           sRight.width=root->data.width-sLeft.width+1;
           sRight.height=root->data.height;
           sRight.splitVert=-1;
           sRight.splitPoint=-1;
       }
       else//分成上下两半
       {
           //在data.y和data.height之间随机选择一个位置来建墙
           if(root->data.height==LIMIT)
           {
               //最小可分割房间，只能在固定位置建造墙壁
               nSplitPoint=(root->data.y+MIN-1);
           }
           else
           {
               nSplitPoint=(root->data.y+MIN-1)+rand()%(root->data.height-LIMIT);
           }
           //上面的房间
           sLeft.x=root->data.x;
           sLeft.y=root->data.y;
           sLeft.width=root->data.width;
           sLeft.height=nSplitPoint-root->data.y+1;
           sLeft.splitVert=-1;
           sLeft.splitPoint=-1;
           //下面的房间
           sRight.x=root->data.x;
           sRight.y=nSplitPoint;
           sRight.width=root->data.width;
           sRight.height=root->data.height-sLeft.height+1;
           sRight.splitVert=-1;
           sRight.splitPoint=-1;
       }
       //记录此房间的分割方式
       root->data.splitVert=nSplitVert;
       root->data.splitPoint=nSplitPoint;
       //插入左右孩子结点
       InsertChild(root,0,sLeft);
       InsertChild(root,1,sRight);
       //继续分割房间
       SplitRoom(root->lchild);
       SplitRoom(root->rchild);
    }
}

void BuildWalls(BiTree root)
{
    int x,y;
    //如果此结点不为空，就说明需要建一堵墙把空间分割开
    if(!BiTreeEmpty(root))
    {
        //判断应该建立纵向的墙还是横向的墙
        if(root->data.splitVert)
        {
            x=root->data.splitPoint;//建墙的位置
            for(y=root->data.y;y<root->data.y+root->data.height;y++)
                gMap[y][x]=WALL;
        }
        else
        {
            y=root->data.splitPoint;//建墙的位置
            for(x=root->data.x;x<root->data.x+root->data.width;x++)
                gMap[y][x]=WALL;
        }
        BuildWalls(root->lchild);
        BuildWalls(root->rchild);
    }

}

//在墙壁上开门
void BuildDoors(BiTree root)
{
    int x,y;
    Point points[MAX];//记录可以开门的坐标
    int pointCount=0;
    int selection;
    //如果此结点不为空，就说明需要开门把左右（上下）房间连起来
    if(!BiTreeEmpty(root))
    {
        //根据墙的方向，决定可以在哪些外置开门
        if(root->data.splitVert)
        {
            x=root->data.splitPoint;
            for(y=root->data.y;y<root->data.y+root->data.height;y++)
            {
                if(gMap[y][x+1]==FLOOR&&gMap[y][x-1]==FLOOR&&y!=0&&y!=ROW-1)
                {
                    //记录坐标
                    points[pointCount].x=x;
                    points[pointCount].y=y;
                    pointCount++;
                }
            }
        }
        else
        {
            y=root->data.splitPoint;
            for(x=root->data.x;x<root->data.x+root->data.width;x++)
            {
                if(gMap[y+1][x]==FLOOR&&gMap[y+1][x]==FLOOR&&x!=0&&x!=COL-1)
                {
                    //记录坐标
                    points[pointCount].x=x;
                    points[pointCount].y=y;
                    pointCount++;
                }
            }
        }
        //随机选择一个位置，打通墙壁，安上门
        selection=rand()%pointCount;
        gMap[points[selection].y][points[selection].x]=DOOR;
        //继续递归左右子树
        BuildDoors(root->lchild);
        BuildDoors(root->rchild);
    }
}
//放置台阶
void PutStairs(BiTree root,int stairs)
{
    int x,y;
    BiTreeNode**pLeaves;//叶子结点数组
    int count;//叶子结点总数
    int index;//被选中的结点
    TElemType room;//被选中的房间
    //查询二叉树的叶子结点（即房间）
    count=GetLeaves(root->lchild,pLeaves);
    //随机选择一个房间
    index=rand()%count;
    room=pLeaves[index]->data;
    //在房间内随机选择一个位置
    x=room.x+1+rand()%(room.width-2);
    y=room.y+1+rand()%(room.height-2);
    gMap[y][x]=stairs;
    //释放指针数组
    free(pLeaves);
}
//建造地牢
void BuildDungeon()
{
    BiTree root;//二叉树根结点
    /*生成二叉树*/
    //创建第一个房间
    CreateBiTree(root);
    //初始化房间数据
    root->data.x=0;
    root->data.y=0;
    root->data.width=COL;
    root->data.height=ROW;
    root->data.splitPoint=-1;
    root->data.splitVert=-1;
    //递归拆分房间，生成二叉树
    /*根据二叉树建立地牢*/
    //初始化地牢
    SplitRoom(root);
    PreOrderTraverse(root,0);
    InitDungeon();
    //修建墙壁，将较大房间分割成小房间
    //在墙上开门，使得左右、上下房间连通
    //放置地牢的入口和出口
    /*地牢生成完毕，销毁二叉树*/
    //修建墙壁，将较大房间分割成小房间
    BuildWalls(root);
    //在墙上开门，使得左右、上下房间可以连通
    BuildDoors(root);
    if(rand()%2)
    {
        PutStairs(root->lchild,UP_STAIRS);
        PutStairs(root->rchild,DOWN_STAIRS);
    }
    else
    {
        PutStairs(root->lchild,DOWN_STAIRS);
        PutStairs(root->rchild,UP_STAIRS);
    }
    //销毁二叉树
    DestroyBiTree(root);
}
int main()
{
    char c;
    //随机数发生器，用于在房间中随机修建墙壁和门
    //根据当前系统时间初始化随机数种子
    srand((unsigned)time(NULL));
    do{
        cout<<"===地图生成器==="<<endl;
        //建造地牢
        BuildDungeon();
        //显示地牢
        PrintDungeon();
        cout<<"输入q结束程序:";
        cin>>c;
        cout<<endl;
    }while(c!='q');
    return 0;
}
