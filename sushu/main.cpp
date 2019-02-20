//题目描述
//令Pi表示第i个素数。现任给两个正整数M <= N <= 10000，请输出PM到PN的所有素数。
//输入描述:
//输入在一行中给出M和N，其间以空格分隔。
//输出描述:
//输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int num=0,flag=0;;
    for(int i=2;num<m;i++)
    {
        if(flag==1)
        {
            flag=0;
        }
        for(int j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            num++;
            if(num>=n&&num<=m)
            {
                cout<<i;
                if((num-n+1)%10==0)
                {
                    cout<<endl;
                }
                else if(num<m)
                {
                    cout<<" ";
                }
            }
        }
    }
    return 0;
}
