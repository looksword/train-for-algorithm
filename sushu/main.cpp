//��Ŀ����
//��Pi��ʾ��i�����������θ�����������M <= N <= 10000�������PM��PN������������
//��������:
//������һ���и���M��N������Կո�ָ���
//�������:
//�����PM��PN������������ÿ10������ռ1�У�����Կո�ָ�������ĩ�����ж���ո�
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
