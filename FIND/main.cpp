//����һ������һ�������е�λ�ã���0��ʼ�������ڷ���-1��
//���룺
//����n(1<n<200),��������n����,Ȼ������x
//�����
//�±��-1
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
        int x,ans = -1;//�𰸳�ʼ��Ϊ-1
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
