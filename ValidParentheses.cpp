// ����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
// ��Ч�ַ��������㣺
// �����ű�������ͬ���͵������űպϡ�
// �����ű�������ȷ��˳��պϡ�
// ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�

// �ⷨ:�ȳ��ֵ����ź�ƥ����һ��,���÷���ջ������������
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
    // �ж��ַ��������Ƿ�Ϊż��,������Ϊ��Ч�ַ���
    int n = strlen(s);
    printf("%d %d",sizeof(s),strlen(s));
    if ((n % 2)!=0) return false;
    // ����һ��ջ��һ������ָ��
    char stk[n];
    int top = 0;
    for(int i=0;i<n;i++)
    {
        char ch = pairs(s[i]);
        // ��������ת���������Ŵ���ջ��,��֮���������ƥ��
        if (ch)
        {   
            
            stk[top] = ch;
            top++;
            
       }else
       {
        // ���ջ�������Ų������������ƥ��,����ջΪ��
        if (top==0 || stk[top-1] != s[i])
        {
            return false;
        }
        // ƥ��ɹ������������
        top--;
       }
        
    }
    return true;
}


// ����������
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