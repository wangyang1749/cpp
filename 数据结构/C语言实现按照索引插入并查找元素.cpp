
#include<stdio.h>
 
#define LEN 30
 
typedef struct
{
	int index;  //索引值；
	int start;  //开始位置；
	int length; //子表长度；
}Index_Table;
 
//定义主表数据；
int Master[LEN]=
{
	101,102,103,104,105,106,107,108, 0, 0,
	111,112,113,114,115,116,117, 0, 0, 0,
	211,212,213,214,215,216, 0, 0, 0, 0
};
 
//定义索引表；
Index_Table Table[3]=
{
	{10, 0, 8},
	{11,10, 7},
	{21,20, 6}
};
 
//按索引查找；
int IndexSearch(int key)
{
	int start=0,length=0,i=0;
	for(i=0;i<3;i++)  //在索引表中查找索引值；
 
	{
		if(Table[i].index==key/10)  //找到索引值并计算索引值；；
		{
			start=Table[i].start;   //获取数组开始序号；
			length=Table[i].length;  //获取元素的长度；
			break;  //跳出循环；
		}
	}
	if(i>=3)
		return -1;  //索引表中查找失败；

	for(i=start;i<start+length;i++)
		if(Master[i]==key)  //找到关键字；
			return i;   //返回序号；
}
 
//插入一个新的关键字；
int InsertNode(int key)
{
	int start,length,i;
	for(i=0;i<3;i++)  //在索引表中查找索引值；
	{
		if(Table[i].index==key/10)  //计算索引值；
		{
			start=Table[i].start;  //获取数组开始的序号；
			length=Table[i].length;  //获取元素长度；
			break;
		}
	}
	if(i>=3)
		return -1;   //索引表中查找失败；
	Master[start+length]=key;   //保存关键字到主表；
	Table[i].length++;   //修改索引表的子表长度；
	return 0;
}
 
int main(void)
{
	long key;
	int i,pos;
	printf("原数据:");
	for(i=0;i<LEN;i++)
	{
		if(!(i%10))
			printf("\n");
		printf("%d ",Master[i]);
	}
	printf("\n\n");
	printf("输入要查找的关键字:");
	scanf("%d",&key);
	pos=IndexSearch(key);
	if(pos>-1)
		printf("查找成功,该关键字的索引位置(即下标)为:  %d",pos);
	else
		printf("查找失败!!!");
	printf("\n\n");
 
	printf("输入要插入的关键字: ");
	scanf("%d",&key);
	printf("\n");
	if(InsertNode(key)==-1)
		printf("插入失败!!!");
	else
	{
		printf("插入关键字后的数据为:");
		for(i=0;i<LEN;i++)
		{
			if(!(i%10))
				printf("\n");
			printf("%d ",Master[i]);
		}
		printf("\n");
	}
 
	printf("\n");
	return 0;
}
