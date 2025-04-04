// 一个管理数组小程序     (未优化)
//  问题1.数据存入数量超过最大可存储数(还包括数据已满时再插入,插入到无效位置)
//  问题2.删除无效数据时(还包括删除超出范围位置,无数据可删除时)
//  问题3.修改无效数据时(还包括修改超出范围位置,无数据可修改时)
#include <stdio.h>
int main()
{
    char ope = 0;
    int arr[10] = {0};                      // 数组
    int len = sizeof(arr) / sizeof(arr[0]); // 最大元素个数
    int items = 0;                          // 当前有效元素个数(追加下标)
// printf("%d",len);
act:
    // 打印出数组有效数据
    printf("最大可存储数据数量:%d\n", len);
    printf("当前数组存储:");
    for (int i = 0; i < items; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n请输入你需要执行的操作:(输入大写字母)\n");
    printf("A:插入\tB:删除\tC:修改\t\n");
    // scanf("%c",&ope);
    ope = getchar();
    switch (ope)
    {
    case 'A':
    {
        int num, loc = 0; // 创建数据,位置变量
        printf("请输入要插入的数据:");
        scanf("%d", &num);
        printf("请输入要插入的位置:(若插入位置前无有效数据则默认追加)");
        scanf("%d", &loc);
        if (loc - 2 >= items)
        { // 插入位置-2 = 前一个位置的下标 , 若这个数大于应追加到的下标 ,
            arr[items] = num;
            items += 1; // 则说明前面有位置无有效数据,应将数据追加到结尾
        }
        else
        {
            for (int i = items - 1; i >= loc - 1; i--)
            { // 真正的插入操作
                arr[i + 1] = arr[i];
                if (i == loc - 1)
                { // 该for循环将插入位置开始之后的所有元素向后移动一个
                    arr[i] = num;// 且当找到插入位置移动数据后,修改该位置值,完成插入
                    items += 1;
                }
            }
        }
        break;
    }
    case 'B':
    {
        int del = 0;
        printf("请输入要删除的位置数据");
        scanf("%d", &del);
        for (int i = del - 1; i < items; i++)
        {
            arr[i] = arr[i + 1]; // 从删除的那个数据开始,后面每个有效数据都往前移动一格
        }
        items -= 1;
        break;
    }

    case 'C':
    {
        int change = 0;
        int loc = 0;
        printf("请输入要修改的位置:");
        scanf("%d", &loc);
        printf("\n请输入新的数据:");
        scanf("%d", &change);
        arr[loc - 1] = change;
        break;
    }

    default:
        printf("输入选项无效,请重新输入.\n");
    }
    getchar(); // 处理缓冲区读取到的多余\n , 解决每次跳转开头都会执行一次default分支bug
    goto act;
    return 0;
}
