//堆栈应用
//括号匹配问题
//字符串包括左右括号和大小写字母，每个左括号从内到外与在它右边且距离最近的右括号匹配
//不能匹配的左括号用"$"标记，不能匹配的右括号用"?"标记，其余为空格
//输入
//多组数据，每组数据一行，包含一个字符串，只包括左右括号和大小写字母，长度不超过100
//输出
//对每组数据，输出两行，一行原字符串，一行处理过的字符串

#include <stdio.h>
#include <stack>
using namespace std;
stack<int> S;//定义一个堆栈
char str[100];//输入
char ans[100];//输出

int main()
{
    while(scanf("%s",str) != EOF)
    {//输入字符串
        int i;
        for(i = 0;str[i] != 0;i++)
        {//从左到右
            if(str[i] == '(')
            {//左括号
                S.push(i);//压入堆栈
                ans[i] = ' ';
            }
            else if(str[i] == ')')
            {//右括号
                if(S.empty() == false)
                {//堆栈非空
                    S.pop();
                    ans[i] = ' ';
                }
                else
                {//堆栈里无左括号
                    ans[i] = '?';
                }
            }
            else
            {//大小写字母
                ans[i] = ' ';
            }
        }
        while(S.empty() == false)
        {//还有多余的左括号未匹配
            ans[S.top()] = '$';
            S.pop();
        }
        ans[i] = 0;//形成字符串
        puts(str);//输出
        puts(ans);//输出
    }
    return 0;
}
