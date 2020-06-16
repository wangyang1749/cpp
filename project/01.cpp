
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
const int WORD_LENGTH = 256;   //使用const int 比用define要好
const int FREQUENCY_COUNT=6;	//用户指定统计词的频数
struct wordNode
{
    char word[WORD_LENGTH];                 //存放单词
    int iWordCount;                  //单词出现次数
	wordNode *pNext;             //结构体的指针
};
 
wordNode *pHeader = NULL;      //链表的头指针
 
//声明需要的函数
void CountWord(char *current);
wordNode * SearchWord(char *current);
void PrintResult();
void Release();
 
int main()
{
    char temp[WORD_LENGTH]; //临时存放单词的词组
    FILE *fp; //打开要读取的文件
    if((fp=fopen("123.txt", "r"))==NULL )   
    {
        printf("Open file failed!!\n");
        exit(1);
    }
        while( EOF != (fscanf(fp,"%s",temp)) )//循环读取文本中的内容
    {
        CountWord(temp);
    }
       fclose(fp); //关闭文件
       PrintResult(); //输出统计结果
   	   Release(); //释放内存，养成好习惯
}
 
void CountWord(char *current)//单词统计
{
    wordNode *pNode = NULL;
    pNode = SearchWord(current);
    if(NULL == pNode)
    {
        return;
    }
    else
    {
        pNode->iWordCount++;
    }
}
 
wordNode * SearchWord(char *current)//查找单词所在节点
{
    if( NULL == pHeader) //当链表为空的时候，也就统计第一个单词时
    {
        pHeader = new wordNode;
        strcpy(pHeader->word, current);
        pHeader->iWordCount = 0;
        pHeader->pNext = NULL;
        return pHeader;
    }
 
    //搜索现有的链表
    wordNode *pCurr = pHeader;
    wordNode *pPre = NULL;
    while( (NULL != pCurr) && (0 != strcmp(pCurr->word, current)) )
    {
        pPre = pCurr;
        pCurr = pCurr->pNext;
    }
 
    if(NULL == pCurr) //该单词不存在
    {
        pCurr = new wordNode;
        strcpy(pCurr->word, current);
        pCurr->iWordCount = 0;
        pCurr->pNext = NULL;
        pPre->pNext = pCurr;
    }
    return pCurr;
}
 
void PrintResult()//输出结果
{
	FILE* fp1=fopen("out_all_word_frequency.txt", "w");
	FILE* fp2=fopen("out_high_frequency.txt","w");
    if(NULL == pHeader)
    {
        printf("No Word!!\n");
    }
    else
    {
        wordNode *pCurr = pHeader;
 
        while(NULL != pCurr)
        {    
	    	fprintf(fp1,"%s\t%d\n", pCurr->word, pCurr->iWordCount);
		    printf("%-20s%-20d\n", pCurr->word, pCurr->iWordCount);
 
 
			if(pCurr->iWordCount >= FREQUENCY_COUNT)
				fprintf(fp2,"%s\t%d\n", pCurr->word, pCurr->iWordCount);
 
			pCurr = pCurr->pNext;
		}
		 fclose(fp1);
		 fclose(fp2);
    }
}
 
void Release()
{
    if(NULL == pHeader)
    {
        return;
    }
    wordNode *pCurr = pHeader;
    while(NULL != pCurr)
    {
        pHeader = pCurr->pNext;
        delete pCurr;
        pCurr = pHeader;
    }
}
