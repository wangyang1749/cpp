#include<iostream>
#include<cstdlib>
#include<malloc.h>
#include<ctime>
using namespace std;

#ifndef _COMMON_
#define _COMMON_
//���峣��
#define OK 1
#define ERROR 0
#define TRUE -1
#define FALSE 0
#endif

#ifndef _BINARY_TREE_
#define _BINARY_TREE_
//������η���
typedef struct TElemType
{
    int x;//x����
    int y;//y����
    int width;//���
    int height;//�߶�
    int splitPoint;//����ǽ��λ��
    int splitVert;//����ǽ�ķ���
}TElemType;
//���������
typedef struct BiTreeNode
{
    TElemType data;//��������
    struct BiTreeNode*lchild;//���ӽ��
    struct BiTreeNode*rchild;//�Һ��ӽ��
}BiTreeNode,*BiTree;
#endif // _BINARY_TREE_

//����������
int CreateBiTree(BiTree &T)
{
    //�����ڴ�
    T=(BiTree)malloc(sizeof(BiTreeNode));
    if(T==NULL)
    {
        cout<<"�ڴ����ʧ��"<<endl;
        exit(-1);
    }
    T->lchild=NULL;
    T->rchild=NULL;
    return OK;
}
//���ٶ�����
int DestroyBiTree(BiTree &T)
{
    //������������������ս���ڴ�
    if(T->lchild!=NULL)
        DestroyBiTree(T->lchild);
    if(T->rchild!=NULL)
        DestroyBiTree(T->rchild);
    //�ͷ��ڴ�
    free(T);
    T=NULL;
    return OK;
}
//�ж϶������Ƿ�Ϊ��
int BiTreeEmpty(BiTree T)
{
    if(T->lchild==NULL&&T->rchild==NULL)
        return TRUE;
    else
        return FALSE;
}
//���ض������ĸ߶�
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
//����Ҷ�ӽ����
int CountLeaf(BiTree T)
{
    if(T==NULL)
        //�ڵ�Ϊ�գ�����0
        return 0;
    else if(BiTreeEmpty(T))
        //��Ҷ�ӽ�㣬����1
        return 1;
    else
        //������������Ҷ�ӽ��֮��
        return CountLeaf(T->lchild)+CountLeaf(T->rchild);
    return 0;
}
//�����ӽ��
int InsertChild(BiTree T,int lr,TElemType e)
{
    BiTreeNode *pTmp;//��ʱ���ָ��
    //��鸸����Ƿ�Ϊ��
    if(T==NULL)
    {
        cout<<"����㲻��Ϊ��";
        return ERROR;
    }
    //Ϊ�ӽ������ڴ�
    pTmp=(BiTreeNode*)malloc(sizeof(BiTreeNode));
    if(pTmp==NULL)
    {
        cout<<"�ڴ����ʧ��";
        exit(-1);
    }
    else
    {
        //��ʼ���˽��
        pTmp->data=e;
        pTmp->lchild=NULL;
        pTmp->rchild=NULL;
    }
    //�ж�ӦΪ���ӻ����Һ���
    //��lrΪ0��������ӣ�Ϊ1������Һ���
    if(lr==0)
    {
        //��ԭ����������Ϊ�գ�������������
        if(T->lchild!=NULL)
            DestroyBiTree(T->lchild);
        T->lchild=pTmp;
    }
    else
    {
        //��ԭ����������Ϊ�գ�������������
        if(T->rchild!=NULL)
            DestroyBiTree(T->rchild);
        T->rchild=pTmp;
    }
    return OK;
}
//�������Ҷ�ӽ��
int GetLeaves(BiTree T,BiTreeNode**&pLeaves)
{
    //����Ҷ�ӽ������
    BiTreeNode**leaves;
    int count;//Ҷ�ӽ������
    int index=0;
    //��������ջ��stack1�����㣬stack2������ķ���״̬
    //ջ�����������ĸ߶Ⱦ���
    //����ջ����һ��ջ��ָ��
    BiTreeNode**stack1;
    int *stack2;
    int height;//���ĸ߶�
    int top;//ջ��ָ��
    int tag;//����״̬��ʶ
    //��ʱ��㣬���ڼ�¼��ǰ����ָ��
    BiTreeNode*pCur;
    if(T==NULL)
    {
        cout<<"���Ϊ��"<<endl;
        return 0;
    }
    //Ҷ�ӽ�����飬������Ҷ�ӽ�������һ��
    count=CountLeaf(T);
    leaves=(BiTreeNode**)malloc(sizeof(BiTreeNode*)*count);
    //ջ�������ȣ����������һ��
    height=BiTreeHeight(T);
    stack1=(BiTreeNode**)malloc(sizeof(BiTreeNode*)*(height+1));
    stack2=(int*)malloc(sizeof(int)*(height+1));
    //�������������
    pCur=T;//��¼�����
    index=0;//��������±��ʼΪ0
    top=0;//ջ��ָ���ʼΪ0
    tag=1;//ѭ����ʶ����ʼΪ1������������Ϊ0
    do{
        while(pCur!=NULL)
        {
            stack1[++top]=pCur;//��ǰ�����ջ
            stack2[top]=0;//״̬����Ϊ0����ʶ"������׼����ջ"
            pCur=pCur->lchild;//�ƶ�����������׼��������ջ
        }//������ΪNULL��ֹͣ��ջ
        if(top==0)//��ջ��ָ��Ϊ0��˵���Ѿ����ʵ������
            tag=0;//ֹͣ����
        else if(stack2[top]==0)//������������ջ
        {
            pCur=stack1[top]->rchild;//��ǰ����ƶ���������
            stack2[top]=1;//״̬����Ϊ1����ʶ"������׼����ջ"
        }
        else//�����������ѷ���
        {
            pCur=stack1[top];//��ջ
            top--;
            if(BiTreeEmpty(pCur))//���ǿ�������֤����Ҷ�ӽ��
                leaves[index++]=pCur;//��Ҷ�ӽ�㱣�浽������
            pCur=NULL;//�˽���Ѿ����ʣ���ΪNULL,�����ظ���ջ
        }
    }while(tag!=0);
    //�ͷ��ڴ�
    free(stack1);
    free(stack2);
    pLeaves=leaves;
    return count;
}
//��ӡ������
int PreOrderTraverse(BiTree&T,int depth)
{
    int i;
    if(T==NULL)
        return ERROR;
    //���ʽ�㣬��ӡ��ǰ����Ľṹ
    /*for(i=0;i<depth;i++)
        cout<<" ";*/
    cout<<"Room[x="<<T->data.x<<",y="<<T->data.y<<",width="<<T->data.width<<",height="<<T->data.height<<",splitVert="<<T->data.splitVert<<",splitPoint="<<T->data.splitPoint<<"]"<<endl;
    //���������ӽ��
    if(T->lchild!=NULL)
        PreOrderTraverse(T->lchild,depth+1);
    if(T->rchild!=NULL)
        PreOrderTraverse(T->rchild,depth+1);
    return OK;
}
//�����ͼ���ݽṹ
#ifndef _DUNGEON_BUILDER_
#define _DUNGEON_BUILDER_
//�����ͼ����
//��ͼ�Ĵ�С
#define COL 15
#define ROW 15
//��ͼ�����߳�
#define MAX COL>ROW?COL:ROW
//��С����ı߳�
#define MIN 5
//��С�ɷָ��ı߳�
#define LIMIT (2*MIN-1)
//��ͼԪ��
#define FLOOR 0//�յ�
#define WALL 1//ǽ
#define DOOR 2//��
#define UP_STAIRS 3//���
#define DOWN_STAIRS 4//����
//��ͼԪ���ڿ���̨����ķ���
const char TILES[]=" #+IO";
//����"��"�ṹ��
typedef struct Point
{
    int x,y;
}Point;
#endif // _DUNGEON_BUILDER_
//��ͼ����
int gMap[ROW][COL];
//��ʼ������
void InitDungeon()
{
    int x,y;
    //��ʼ����������
    for(y=0;y<ROW;y++)
        for(x=0;x<COL;x++)
        gMap[y][x]=FLOOR;
    //�޽���ǽ���ѵ���Χ����
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
//��ʾ����
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
//������³�

//ʵ�ַ���ָ�
void SplitRoom(BiTree root)
{
    int nSplitVert;
    int nSplitPoint;
    TElemType sLeft;
    TElemType sRight;
    //�жϷ����Ƿ񻹿��Լ����ָ�
    if(root->data.width>=LIMIT||root->data.height>=LIMIT)
    {
       //��������ָ��
       if(root->data.width<LIMIT)
       {
           //������Ŀ�Ȳ���ʱ���޽�һ�º��ŵ�ǽ���ѷ���ָ����������
           nSplitVert=0;
       }
       else if(root->data.height<LIMIT)
       {
           //������ĸ߶Ȳ���ʱ���޽�һ�����ŵ�ǽ���ѷ���ָ����������
           nSplitVert=1;
       }
       else
       {
           //�����㹻���������ǽ�ڵķ���
           nSplitVert=rand()%2;
       }
       //���ѡ��һ��λ�ã�����һ��ǽ
       if(nSplitVert)//�ֳ���������
       {
           //��data.x��data.width֮�����ѡ��һ��λ������ǽ
           if(root->data.width==LIMIT)
           {
               //��С�ɷָ�䣬ֻ���ڹ̶�λ�ý���ǽ��
               nSplitPoint=(root->data.x+MIN-1);
           }
           else
           {
               nSplitPoint=(root->data.x+MIN-1)+rand()%(root->data.width-LIMIT);
           }
           //��ߵķ���
           sLeft.x=root->data.x;
           sLeft.y=root->data.y;
           sLeft.width=nSplitPoint-root->data.x+1;
           sLeft.height=root->data.height;
           sLeft.splitVert=-1;
           sLeft.splitPoint=-1;
           //�ұߵķ���
           sRight.x=nSplitPoint;
           sRight.y=root->data.y;
           sRight.width=root->data.width-sLeft.width+1;
           sRight.height=root->data.height;
           sRight.splitVert=-1;
           sRight.splitPoint=-1;
       }
       else//�ֳ���������
       {
           //��data.y��data.height֮�����ѡ��һ��λ������ǽ
           if(root->data.height==LIMIT)
           {
               //��С�ɷָ�䣬ֻ���ڹ̶�λ�ý���ǽ��
               nSplitPoint=(root->data.y+MIN-1);
           }
           else
           {
               nSplitPoint=(root->data.y+MIN-1)+rand()%(root->data.height-LIMIT);
           }
           //����ķ���
           sLeft.x=root->data.x;
           sLeft.y=root->data.y;
           sLeft.width=root->data.width;
           sLeft.height=nSplitPoint-root->data.y+1;
           sLeft.splitVert=-1;
           sLeft.splitPoint=-1;
           //����ķ���
           sRight.x=root->data.x;
           sRight.y=nSplitPoint;
           sRight.width=root->data.width;
           sRight.height=root->data.height-sLeft.height+1;
           sRight.splitVert=-1;
           sRight.splitPoint=-1;
       }
       //��¼�˷���ķָʽ
       root->data.splitVert=nSplitVert;
       root->data.splitPoint=nSplitPoint;
       //�������Һ��ӽ��
       InsertChild(root,0,sLeft);
       InsertChild(root,1,sRight);
       //�����ָ��
       SplitRoom(root->lchild);
       SplitRoom(root->rchild);
    }
}

void BuildWalls(BiTree root)
{
    int x,y;
    //����˽�㲻Ϊ�գ���˵����Ҫ��һ��ǽ�ѿռ�ָ
    if(!BiTreeEmpty(root))
    {
        //�ж�Ӧ�ý��������ǽ���Ǻ����ǽ
        if(root->data.splitVert)
        {
            x=root->data.splitPoint;//��ǽ��λ��
            for(y=root->data.y;y<root->data.y+root->data.height;y++)
                gMap[y][x]=WALL;
        }
        else
        {
            y=root->data.splitPoint;//��ǽ��λ��
            for(x=root->data.x;x<root->data.x+root->data.width;x++)
                gMap[y][x]=WALL;
        }
        BuildWalls(root->lchild);
        BuildWalls(root->rchild);
    }

}

//��ǽ���Ͽ���
void BuildDoors(BiTree root)
{
    int x,y;
    Point points[MAX];//��¼���Կ��ŵ�����
    int pointCount=0;
    int selection;
    //����˽�㲻Ϊ�գ���˵����Ҫ���Ű����ң����£�����������
    if(!BiTreeEmpty(root))
    {
        //����ǽ�ķ��򣬾�����������Щ���ÿ���
        if(root->data.splitVert)
        {
            x=root->data.splitPoint;
            for(y=root->data.y;y<root->data.y+root->data.height;y++)
            {
                if(gMap[y][x+1]==FLOOR&&gMap[y][x-1]==FLOOR&&y!=0&&y!=ROW-1)
                {
                    //��¼����
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
                    //��¼����
                    points[pointCount].x=x;
                    points[pointCount].y=y;
                    pointCount++;
                }
            }
        }
        //���ѡ��һ��λ�ã���ͨǽ�ڣ�������
        selection=rand()%pointCount;
        gMap[points[selection].y][points[selection].x]=DOOR;
        //�����ݹ���������
        BuildDoors(root->lchild);
        BuildDoors(root->rchild);
    }
}
//����̨��
void PutStairs(BiTree root,int stairs)
{
    int x,y;
    BiTreeNode**pLeaves;//Ҷ�ӽ������
    int count;//Ҷ�ӽ������
    int index;//��ѡ�еĽ��
    TElemType room;//��ѡ�еķ���
    //��ѯ��������Ҷ�ӽ�㣨�����䣩
    count=GetLeaves(root->lchild,pLeaves);
    //���ѡ��һ������
    index=rand()%count;
    room=pLeaves[index]->data;
    //�ڷ��������ѡ��һ��λ��
    x=room.x+1+rand()%(room.width-2);
    y=room.y+1+rand()%(room.height-2);
    gMap[y][x]=stairs;
    //�ͷ�ָ������
    free(pLeaves);
}
//�������
void BuildDungeon()
{
    BiTree root;//�����������
    /*���ɶ�����*/
    //������һ������
    CreateBiTree(root);
    //��ʼ����������
    root->data.x=0;
    root->data.y=0;
    root->data.width=COL;
    root->data.height=ROW;
    root->data.splitPoint=-1;
    root->data.splitVert=-1;
    //�ݹ��ַ��䣬���ɶ�����
    /*���ݶ�������������*/
    //��ʼ������
    SplitRoom(root);
    PreOrderTraverse(root,0);
    InitDungeon();
    //�޽�ǽ�ڣ����ϴ󷿼�ָ��С����
    //��ǽ�Ͽ��ţ�ʹ�����ҡ����·�����ͨ
    //���õ��ε���ںͳ���
    /*����������ϣ����ٶ�����*/
    //�޽�ǽ�ڣ����ϴ󷿼�ָ��С����
    BuildWalls(root);
    //��ǽ�Ͽ��ţ�ʹ�����ҡ����·��������ͨ
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
    //���ٶ�����
    DestroyBiTree(root);
}
int main()
{
    char c;
    //������������������ڷ���������޽�ǽ�ں���
    //���ݵ�ǰϵͳʱ���ʼ�����������
    srand((unsigned)time(NULL));
    do{
        cout<<"===��ͼ������==="<<endl;
        //�������
        BuildDungeon();
        //��ʾ����
        PrintDungeon();
        cout<<"����q��������:";
        cin>>c;
        cout<<endl;
    }while(c!='q');
    return 0;
}
