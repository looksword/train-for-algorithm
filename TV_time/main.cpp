//尽可能多的看电视节目
//输入：
//第一行只有一个整数n（n <= 100），表示你喜欢看的节目数
//接下来是n行数据 表示节目开始时间和结束时间
//n = 0 表示输入结束 不做处理
//输出能完整看完节目的个数
#include <stdio.h>
#include<algorithm>
using namespace std;

struct TV_time
{
    int starttime;
    int endtime;
    bool operator < (const TV_time &A)
    {
        return endtime < A.endtime;//升序排序
    }
}buf[100];

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
        {
            break;
        }
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d",&buf[i].starttime,&buf[i].endtime);
        }
        sort(buf,buf + n);
        int currenttime = 0;//当前时间
        int ans = 0;//收看节目数
        for(int i = 0;i < n;i++)
        {
            if(currenttime <= buf[i].starttime)
            {
                currenttime = buf[i].endtime;
                ans ++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
