//����һ��ֻ����+-*/�ķǸ�����������ʽ ����ñ��ʽ��ֵ
//����
//���������У�һ��һ����ÿ�в�����200���ַ��������������֮���ÿո����
//û�зǷ����ʽ����һ����ֻ��0ʱ�����������Ӧ�Ľ����Ҫ���
//���
//��ÿ�������������һ�У����ñ��ʽ��ֵ����ȷ��С�����2λ

#include <stdio.h>
#include<stack>
using namespace std;
//����������ջ��һ�����������������һ��������������
//�ڱ��ʽ��β��ӱ�����������������������ȼ����

char str[200];//������ʽ�ַ���
int mat[][5] = {//���ȼ�����mat[i][j] == 1 ��ʾi����������ȼ�����j�������
    //0�ű�������
    //1��+
    //2��-
    //3��*
    //4��/
    1,0,0,0,0,
    1,0,0,0,0,
    1,0,0,0,0,
    1,1,1,0,0,
    1,1,1,0,0,
};
stack<int> op;//�����ջ��������������
stack<double> in;//����ջ�����������ܴ��ڸ��������ʲ���double
void getOp(bool &reto,int &retn,int &i)
{//��ñ��ʽ����һ��Ԫ��
    //retoΪtrue��ʾ��Ԫ��Ϊ�����,false��ʾΪ����
    //Ԫ�ر�����retn��
    //i��ʾԪ�ص��ַ����±�
    if(i == 0 && op.empty() == true)
    {//��Ϊ��ӱ��Ϊ0�ı���ַ�
        reto = true;
        retn = 0;
        return;
    }
    if(str[i] == 0)
    {//�ѱ������ַ���,��Ϊ��ӱ��Ϊ0�ı���ַ�
        reto = true;
        retn = 0;
        return;
    }
    if(str[i] >= '0' && str[i] <= '9')
    {//����
        reto = false;
    }
    else
    {//�����
        reto = true;
        switch(str[i])
        {
            case '+':retn = 1;break;
            case '-':retn = 2;break;
            case '*':retn = 3;break;
            case '/':retn = 4;break;
        }
        i += 2;//�����ո�
        return;
    }
    retn = 0;//����������Ϊ0
    for(;str[i] != ' '&&str[i] != 0;i++)
    {//��������������
        retn *= 10;
        retn += str[i] - '0';
    }//��������ֵ�����ֵ
    if(str[i] == ' ')
        i++;
    return;
}

int main()
{
    while(gets(str))
    {//�����ַ���������λ���ļ�βʱ��gets����0
        if(str[0] == '0' && str[1] == 0)
            break;
        bool retop;
        int retnum;
        int idx = 0;
        //���ջ
        while(op.empty() == false)
            op.pop();
        while(in.empty() == false)
            in.pop();
        while(true)
        {//ѭ�������ַ���
            getOp(retop,retnum,idx);//��ȡ���ʽ����һԪ��
            if(retop == false)
            {//��Ԫ��Ϊ����
                in.push((double)retnum);//ѹ������ջ
            }
            else
            {
                double tmp;
                if(op.empty() == true || mat[retnum][op.top()] == 1)
                {//�����ջΪ�ջ�ǰ��������ȼ�����ջ�������
                    op.push(retnum);//ѹ�������ջ
                }
                else
                {
                    while(mat[retnum][op.top()] == 0)
                    {//��ǰ��������ȼ�С��ջ�������
                        int ret = op.top();//ջ�������
                        op.pop();//�������ջ
                        double b = in.top();//ջ������
                        in.pop();//��ֵ��ջ
                        double a = in.top();//ջ������
                        in.pop();//��ֵ��ջ
                        //��ret��������a��b
                        switch(ret)
                        {
                            case 1:tmp = a + b;break;
                            case 2:tmp = a - b;break;
                            case 3:tmp = a * b;break;
                            case 4:tmp = a / b;break;
                        }
                        in.push(tmp);//������ѹ������ջ
                    }
                    op.push(retnum);//�����ѹ�������ջ
                }
            }
            if(op.size() == 2 && op.top() == 0)
            {//�����ջ��ֻʣ����Ԫ�أ��Ҿ�����Ϊ�趨�ı�������
                break;
            }
        }
        printf("%.2f\n",in.top());
    }
    return 0;
}
