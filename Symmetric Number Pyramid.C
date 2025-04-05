// 输出数字金字塔
//  输入层数
#include <stdio.h>
int main()
{
    int level = 0;
    // 输入想输出的层数
    scanf("%d", &level);
    // 输出部分
    for (int le = 1; le <= level; le++)
    {
        // 控制空格数量
        for (int i = level - le; i >= 1; i--)
        {
            printf(" ");
        }
        // 升序数字输出
        for (int j = 1; j <= le; j++)
        {
            printf("%d", j);
        }
        // 降序数字输出
        for (int k = le - 1; k > 0; k--)
        {
            printf("%d", k);
        }
        printf("\n");
    }
}
