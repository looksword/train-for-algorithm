//�����ܶ�Ŀ����ӽ�Ŀ
//���룺
//��һ��ֻ��һ������n��n <= 100������ʾ��ϲ�����Ľ�Ŀ��
//��������n������ ��ʾ��Ŀ��ʼʱ��ͽ���ʱ��
//n = 0 ��ʾ������� ��������
//��������������Ŀ�ĸ���
#include <stdio.h>
#include<algorithm>
using namespace std;

struct TV_time
{
    int starttime;
    int endtime;
    bool operator < (const TV_time &A)
    {
        return endtime < A.endtime;//��������
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
        int currenttime = 0;//��ǰʱ��
        int ans = 0;//�տ���Ŀ��
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
