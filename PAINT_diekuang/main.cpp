//把一个个大小差一圈的筐叠上去，使得从上往下看时，边筐花色交错
//输入：
//三元组：外筐尺寸n（0<n<80，奇整数），中心花色字符,外筐花色字符（均为ASCII可见字符）
//输出：
//叠在一起的筐图案，中心花色与外筐花色字符从内层起交错相叠
//多筐相叠时，最外筐的角总是被打磨掉，叠筐与叠筐之间应有一行间隔
#include <stdio.h>
int main()
{
    int outPutBuf[82][82];//预排版的输出缓存
    char a,b;//输入的字符
    int n;//叠筐大小
    bool firstCase = true;//是否为第一个叠筐 方便控制一行间隔
    while(scanf("%d %c %c",&n,&a,&b) == 3)
    {
        if(firstCase == true)
            firstCase = false;
        else
            printf("\n");
        for(int i = 1,j = 1;i <= n;i += 2,j++)//外筐总比内筐边长增加2
        {//从里往外赋值输出缓存
            int x = n / 2 + 1,y = x;//每个筐左上角坐标
            x -= j - 1;
            y -= j - 1;
            char c = j % 2 == 1 ? a : b;//当前筐的字符
            for(int k = 1;k <= i;k++)
            {//对当前筐赋值
                outPutBuf[x + k - 1][y] = c;//左边赋值
                outPutBuf[x][y + k - 1] = c;//上边赋值
                outPutBuf[x + i - 1][y + k - 1] = c;//右边赋值
                outPutBuf[x + k - 1][y + i - 1] = c;//下边赋值
            }
        }
        if(n != 1)//打磨掉最外筐的角
        {
            outPutBuf[1][1] = ' ';
            outPutBuf[1][n] = ' ';
            outPutBuf[n][1] = ' ';
            outPutBuf[n][n] = ' ';
        }
        for(int i = 1;i <= n;i++)
        {//输出筐
            for(int j = 1;j <= n;j++)
            {
                printf("%c",outPutBuf[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
