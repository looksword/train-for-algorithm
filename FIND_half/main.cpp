//����n��ѧ������Ϣ��Ȼ����в�ѯ
//���룺
//��һ��ΪN,��ѧ���ĸ�����N<=1000��
//N�У�����N��ѧ������Ϣ
//ѧ�� ���� �Ա� ����
//����һ��M,��ʾ��M�У�M<=1000����ѯ
//ѧ��
//�����
//M�У�ÿ�а�����Ӧ�ڲ�ѯ��ѧ������Ϣ��û���������No Answer!��
#include <stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct Student
{
    char No[100];//ѧ��
    char Name[100];//����
    char Sex[5];//�Ա�
    int Age;//����
    bool operator < (const Student & A)const
    {
        return strcmp(No,A.No) < 0;
    }
}Buf[1000];
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0;i < n;i++)
        {
            scanf("%s%s%s%d",Buf[i].No,Buf[i].Name,Buf[i].Sex,&Buf[i].Age);//����
        }
        sort(Buf,Buf + n);
        int m;
        scanf("%d",&m);
        while(m-- != 0)
        {
            int ans = -1;
            char x[30];
            scanf("%s",x);
            int top = n - 1,base = 0;
            while(top >= base)
            {//���ֲ���
                int mid = (top + base) / 2;
                int tmp = strcmp(Buf[mid].No,x);
                if(tmp == 0)
                {
                    ans = mid;
                    break;
                }
                else if(tmp > 0)
                    top = mid - 1;
                else
                    base = mid + 1;
            }
            if(ans == -1)
                printf("No Answer!\n");
            else
                printf("%s %s %s %d\n",Buf[ans].No,Buf[ans].Name,Buf[ans].Sex,Buf[ans].Age);
        }
        return 0;
    }
    return 0;
}