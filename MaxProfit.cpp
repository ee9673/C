// ����һ������ prices �����ĵ� i ��Ԫ�� prices[i] ��ʾһ֧������Ʊ�� i ��ļ۸�
// ��ֻ��ѡ�� ĳһ�� ������ֻ��Ʊ����ѡ���� δ����ĳһ����ͬ������ �����ù�Ʊ�����һ���㷨�����������ܻ�ȡ���������
// ��������Դ���ʽ����л�ȡ�������������㲻�ܻ�ȡ�κ����󣬷��� 0 ��
#include <stdio.h>
int MaxProfit(int* prices,int size)
{
    // ÿ�ζ�������칺��,����֮����������,����֮ǰ������������滻
    int maxP = 0;
    int min = __INT_MAX__;
    for (int i = 0; i < size;i++)
    {
        // �����ǰ��ͼ۵��ڸ���۸�,���滻��ͼ�
        if(min < prices[i])
        {
            min = prices[i];
        }else{
            // �����ǰ���������ڽ���۸��ȥ��ͼ�,���滻��ǰ�������
            if(maxP< (prices[i]-min))
            {
                maxP = prices[i]-min;
            }
        }
    }
    return maxP;
}

int main()
{
    int prices[6] = {7,1,5,3,6,4};
    int size = sizeof(prices) / sizeof(int);
    int res = MaxProfit(prices,size);
    printf("%d",res);
}