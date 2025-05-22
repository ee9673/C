// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 每个右括号都有一个对应的相同类型的左括号。

// 解法:先出现的括号后匹配另一半,正好符合栈的先入后出性质
#include <stdio.h>
#include <string.h>
char pairs(char a)
{
    if (a=='{') return '}';
    if (a=='[') return ']';
    if (a=='(') return ')';
    return 0;
}

bool isVali(char* s)
{
    // 判断字符串长度是否为偶数,不是则为无效字符串
    int n = strlen(s);
    printf("%d %d",sizeof(s),strlen(s));
    if ((n % 2)!=0) return false;
    // 创建一个栈和一个顶部指针
    char stk[n];
    int top = 0;
    for(int i=0;i<n;i++)
    {
        char ch = pairs(s[i]);
        // 将左括号转换成右括号存入栈内,与之后的右括号匹配
        if (ch)
        {   
            
            stk[top] = ch;
            top++;
            
       }else
       {
        // 如果栈顶右括号并不与该右括号匹配,或是栈为空
        if (top==0 || stk[top-1] != s[i])
        {
            return false;
        }
        // 匹配成功弹出最顶部括号
        top--;
       }
        
    }
    return true;
}


// 测试主函数
int main()
{
    char s[] = "()[]{}";       
    // char s[] = "([)]"; 
    // char s[] = "(]";
    bool res = isVali(s);
    if (res)
    {
        printf("true");
    }else
    {
        printf("false");

    }
    
}