//查找一个数在一个数组中的位置（从0开始，若不在返回-1）
//输入：
//输入n(1<n<200),接着输入n个数,然后输入x
//输出：
//下标或-1
#include <stdio.h>
int main()
{
    int buf[200];
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&buf[i]);
        }
        int x,ans = -1;//答案初始化为-1
        scanf("%d",&x);
        for(int i = 0;i < n;i++)
        {
            if(x == buf[i])
            {
                ans = i;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
