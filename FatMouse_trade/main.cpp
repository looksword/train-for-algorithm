//有m元钱，n种物品；每种物品有j磅，总价值f元，  可以用0到f的任意价格购买相应磅的物品
//要求输出用m元钱最多能买到多少磅的物品
//贪心算法
#include<stdio.h>
#include<algorithm>
using namespace std;

struct goods
{//表示可买物品的结构体
    double j;//该物品总重
    double f;//该物品总价值
    double s;//该物品性价比
    bool operator < (const goods &A)
    {//比较物品时使用性价比来比较
        return s > A.s;//降序排序
    }
}buf[1000];

int main()
{
    double m;
    int n;
    while(scanf("%lf%d",&m,&n) != EOF)
    {
        if(m == -1 && n == -1)
        {
            break;
        }
        for(int i = 0;i < n;i++)
        {
            scanf("%lf%lf",&buf[i].j,&buf[i].f);//物品总重总价值
            buf[i].s = buf[i].j / buf[i].f;//计算性价比
        }
        sort(buf,buf+n);//性价比降序排序
        int idx = 0;//当前货物下标
        double ans = 0;//当前所能得到的总重量
        while(m > 0 && idx < n)
        {
            if(m > buf[idx].f)//全部买下
            {//买下
                ans += buf[idx].j;
                m -= buf[idx].f;
            }
            else//部分买下
            {//买下
                ans += buf[idx].j * m / buf[idx].f;
                m = 0;
            }
            idx ++;
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
