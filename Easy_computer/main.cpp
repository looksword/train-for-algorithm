//读入一个只包含+-*/的非负整数计算表达式 计算该表达式的值
//输入
//数据若干行，一行一例，每行不超过200个字符，整数和运算符之间用空格隔开
//没有非法表达式，当一行中只有0时输入结束，相应的结果不要输出
//输出
//对每个测试样例输出一行，即该表达式的值，精确到小数点后2位

#include <stdio.h>
#include<stack>
using namespace std;
//设立两个堆栈，一个用来保存运算符，一个用来保存数字
//在表达式首尾添加标记运算符，该运算符运算优先级最低

char str[200];//保存表达式字符串
int mat[][5] = {//优先级矩阵，mat[i][j] == 1 表示i号运算符优先级大于j好运算符
    //0号标记运算符
    //1号+
    //2号-
    //3号*
    //4号/
    1,0,0,0,0,
    1,0,0,0,0,
    1,0,0,0,0,
    1,1,1,0,0,
    1,1,1,0,0,
};
stack<int> op;//运算符栈，保存运算符编号
stack<double> in;//数字栈，运算结果可能存在浮点数，故采用double
void getOp(bool &reto,int &retn,int &i)
{//获得表达式中下一个元素
    //reto为true表示该元素为运算符,false表示为数字
    //元素保存在retn中
    //i表示元素的字符串下标
    if(i == 0 && op.empty() == true)
    {//人为添加编号为0的标记字符
        reto = true;
        retn = 0;
        return;
    }
    if(str[i] == 0)
    {//已遍历完字符串,人为添加编号为0的标记字符
        reto = true;
        retn = 0;
        return;
    }
    if(str[i] >= '0' && str[i] <= '9')
    {//数字
        reto = false;
    }
    else
    {//运算符
        reto = true;
        switch(str[i])
        {
            case '+':retn = 1;break;
            case '-':retn = 2;break;
            case '*':retn = 3;break;
            case '/':retn = 4;break;
        }
        i += 2;//跳过空格
        return;
    }
    retn = 0;//返回数字置为0
    for(;str[i] != ' '&&str[i] != 0;i++)
    {//遍历连续的数字
        retn *= 10;
        retn += str[i] - '0';
    }//计算该数字的数字值
    if(str[i] == ' ')
        i++;
    return;
}

int main()
{
    while(gets(str))
    {//输入字符串，当其位于文件尾时，gets返回0
        if(str[0] == '0' && str[1] == 0)
            break;
        bool retop;
        int retnum;
        int idx = 0;
        //清空栈
        while(op.empty() == false)
            op.pop();
        while(in.empty() == false)
            in.pop();
        while(true)
        {//循环遍历字符串
            getOp(retop,retnum,idx);//获取表达式中下一元素
            if(retop == false)
            {//该元素为数字
                in.push((double)retnum);//压入数字栈
            }
            else
            {
                double tmp;
                if(op.empty() == true || mat[retnum][op.top()] == 1)
                {//运算符栈为空或当前运算符优先级大于栈顶运算符
                    op.push(retnum);//压入运算符栈
                }
                else
                {
                    while(mat[retnum][op.top()] == 0)
                    {//当前运算符优先级小于栈顶运算符
                        int ret = op.top();//栈顶运算符
                        op.pop();//运算符出栈
                        double b = in.top();//栈顶数字
                        in.pop();//数值出栈
                        double a = in.top();//栈顶数字
                        in.pop();//数值出栈
                        //用ret运算数字a和b
                        switch(ret)
                        {
                            case 1:tmp = a + b;break;
                            case 2:tmp = a - b;break;
                            case 3:tmp = a * b;break;
                            case 4:tmp = a / b;break;
                        }
                        in.push(tmp);//运算结果压入数字栈
                    }
                    op.push(retnum);//运算符压入运算符栈
                }
            }
            if(op.size() == 2 && op.top() == 0)
            {//运算符栈中只剩两个元素，且均是人为设定的标记运算符
                break;
            }
        }
        printf("%.2f\n",in.top());
    }
    return 0;
}
