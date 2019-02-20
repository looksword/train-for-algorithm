//排版
//考察输出格式的细节把握
//输入：
//一个高度h
//输出：
//一个高为h，上底为h的梯形
#include <stdio.h>
int main()
{
    int h;
    while(scanf("%d",&h) != EOF)
    {
        int maxLine = h + (h - 1) * 2;//下底行星数
        for(int i = 1;i <= h;i++)
        {
            for(int j = 1;j <= maxLine;j++)
            {
                if(j < maxLine - h - (i - 1)*2 + 1)
                    printf(" ");
                else
                    printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
