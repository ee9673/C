// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
#include <stdio.h>
int MaxProfit(int* prices,int size)
{
    // 每次都假设今天购买,计算之后的最大利润,若比之前最大利润更大就替换
    int maxP = 0;
    int min = __INT_MAX__;
    for (int i = 0; i < size;i++)
    {
        // 如果当前最低价低于该天价格,则替换最低价
        if(min < prices[i])
        {
            min = prices[i];
        }else{
            // 如果当前最大利润低于今天价格减去最低价,则替换当前最大利润
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