//��mԪǮ��n����Ʒ��ÿ����Ʒ��j�����ܼ�ֵfԪ��  ������0��f������۸�����Ӧ������Ʒ
//Ҫ�������mԪǮ������򵽶��ٰ�����Ʒ
//̰���㷨
#include<stdio.h>
#include<algorithm>
using namespace std;

struct goods
{//��ʾ������Ʒ�Ľṹ��
    double j;//����Ʒ����
    double f;//����Ʒ�ܼ�ֵ
    double s;//����Ʒ�Լ۱�
    bool operator < (const goods &A)
    {//�Ƚ���Ʒʱʹ���Լ۱����Ƚ�
        return s > A.s;//��������
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
            scanf("%lf%lf",&buf[i].j,&buf[i].f);//��Ʒ�����ܼ�ֵ
            buf[i].s = buf[i].j / buf[i].f;//�����Լ۱�
        }
        sort(buf,buf+n);//�Լ۱Ƚ�������
        int idx = 0;//��ǰ�����±�
        double ans = 0;//��ǰ���ܵõ���������
        while(m > 0 && idx < n)
        {
            if(m > buf[idx].f)//ȫ������
            {//����
                ans += buf[idx].j;
                m -= buf[idx].f;
            }
            else//��������
            {//����
                ans += buf[idx].j * m / buf[idx].f;
                m = 0;
            }
            idx ++;
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
