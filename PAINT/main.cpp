//�Ű�
//���������ʽ��ϸ�ڰ���
//���룺
//һ���߶�h
//�����
//һ����Ϊh���ϵ�Ϊh������
#include <stdio.h>
int main()
{
    int h;
    while(scanf("%d",&h) != EOF)
    {
        int maxLine = h + (h - 1) * 2;//�µ�������
        for(int i = 1;i <= h;i++)
        {
            for(int j = 1;j <= maxLine;j++)
            {
                if(j < maxLine - h - (i - 1)*2 + 1)
                    printf(" ");
                else
                    printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
