//�������� ��һ������һ����n ��ʾҶ�ڵ�ĸ���
//��Ҫ����ЩҶ�ڵ����ɹ������� ���ݹ��������ĸ��� ��Щ�ڵ���Ȩֵ ��weight
//��Ŀ��Ҫ������нڵ��ֵ��Ȩֵ�ĳ˻�֮��
//���룺
//��������
//ÿ���һ������һ����n ��������n��Ҷ�ڵ㣨Ҷ�ڵ�Ȩֵ������100��2<=n<=100��
//�����
//���Ȩֵ
#include <queue>
#include<stdio.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > Q;//����һ��С����
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        while(Q.empty() == false) Q.pop();//��ն���Ԫ��
        for(int i = 1;i <= n;i++)
        {//����n��Ҷ�ӽڵ�Ȩֵ
            int x;
            scanf("%d",&x);
            Q.push(x);//��Ȩֵ�������
        }
        int ans = 0;//�����
        while(Q.size() > 1)
        {//������Ԫ�ش���1
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();
            //ȡ������������С��Ԫ�� ����Ϊͬһ���ڵ�����Ҷ��� �Ҹ�˫�׽ڵ��ȨֵΪ���ǵĺ�
            ans += a + b;//�ø��׽ڵ�ز�ΪҶ�ӽڵ� �ۼ���Ȩֵ
            Q.push(a + b);//����˫�׽ڵ��Ȩֵ�Żض���
        }
        printf("%d",ans);//���
    }
    return 0;
}
