#include <stdio.h>

int main()
{
    FILE *fp = fopen("123.txt", "r");
    if (fp)
    {
        char ch;
        while ((ch = fgetc(fp)) != EOF)
        {
            // putchar(ch);
            printf("%c", ch);
        }
        // char num[256];
        // fscanf(fp, "%s", num);
        // printf("%s", num);
        fclose(fp);
    }
    else
    {
        printf("无法=打开文件！");
    }
    return 0;
}