//��һ������С��һȦ�Ŀ����ȥ��ʹ�ô������¿�ʱ���߿�ɫ����
//���룺
//��Ԫ�飺���ߴ�n��0<n<80���������������Ļ�ɫ�ַ�,���ɫ�ַ�����ΪASCII�ɼ��ַ���
//�����
//����һ��Ŀ�ͼ�������Ļ�ɫ�����ɫ�ַ����ڲ��𽻴����
//������ʱ�������Ľ����Ǳ���ĥ�������������֮��Ӧ��һ�м��
#include <stdio.h>
int main()
{
    int outPutBuf[82][82];//Ԥ�Ű���������
    char a,b;//������ַ�
    int n;//�����С
    bool firstCase = true;//�Ƿ�Ϊ��һ������ �������һ�м��
    while(scanf("%d %c %c",&n,&a,&b) == 3)
    {
        if(firstCase == true)
            firstCase = false;
        else
            printf("\n");
        for(int i = 1,j = 1;i <= n;i += 2,j++)//����ܱ��ڿ�߳�����2
        {//�������⸳ֵ�������
            int x = n / 2 + 1,y = x;//ÿ�������Ͻ�����
            x -= j - 1;
            y -= j - 1;
            char c = j % 2 == 1 ? a : b;//��ǰ����ַ�
            for(int k = 1;k <= i;k++)
            {//�Ե�ǰ��ֵ
                outPutBuf[x + k - 1][y] = c;//��߸�ֵ
                outPutBuf[x][y + k - 1] = c;//�ϱ߸�ֵ
                outPutBuf[x + i - 1][y + k - 1] = c;//�ұ߸�ֵ
                outPutBuf[x + k - 1][y + i - 1] = c;//�±߸�ֵ
            }
        }
        if(n != 1)//��ĥ�������Ľ�
        {
            outPutBuf[1][1] = ' ';
            outPutBuf[1][n] = ' ';
            outPutBuf[n][1] = ' ';
            outPutBuf[n][n] = ' ';
        }
        for(int i = 1;i <= n;i++)
        {//�����
            for(int j = 1;j <= n;j++)
            {
                printf("%c",outPutBuf[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
