//哈夫曼树 第一行输入一个数n 表示叶节点的个数
//需要用这些叶节点生成哈夫曼树 根据哈夫曼树的概念 这些节点有权值 即weight
//题目需要输出所有节点的值和权值的乘积之和
//输入：
//多组数据
//每组第一行输入一个数n 接着输入n个叶节点（叶节点权值不超过100，2<=n<=100）
//输出：
//输出权值
#include <queue>
#include<stdio.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > Q;//建立一个小顶堆
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        while(Q.empty() == false) Q.pop();//清空堆内元素
        for(int i = 1;i <= n;i++)
        {//输入n个叶子节点权值
            int x;
            scanf("%d",&x);
            Q.push(x);//将权值放入堆中
        }
        int ans = 0;//保存答案
        while(Q.size() > 1)
        {//当堆中元素大于1
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();
            //取出堆中两个最小的元素 他们为同一个节点的左右儿子 且该双亲节点的权值为他们的和
            ans += a + b;//该父亲节点必不为叶子节点 累加其权值
            Q.push(a + b);//将该双亲节点的权值放回堆中
        }
        printf("%d",ans);//输出
    }
    return 0;
}
