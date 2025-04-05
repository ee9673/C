// 冒泡排序 (优化版)
// 冒泡排序核心特点:每一轮排序会将当前未排序部分的最大值“冒泡”到末尾,
// 因此下一轮无需再比较已经排好的部分。
// 即:每次比较次数可以比前次要减少一次
#include <stdio.h>
int main()
{
    int arr[5] = {4, 5, 7, 3, 2};   // 正确答案 : 2,3,4,5,7
    int size = sizeof(arr) / sizeof(arr[0]);
    int counts = 0;         //counts:存儲循环运行次数,从0开始计数
    while (1)
    {
        
        int i = 1;
        // 每一次可以比上一次少进行一次比较,即减少counts次
        for ( i = 1 ; i < size - counts; i++)
        {
           
            if (arr[i - 1] > arr[i])
            {
                //将元素与上一个元素比较,若小于上一个元素,则交换数据
                int z = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = z;         
            } 
        }
        //当i=2跳出循环时,证明arr[0]和arr[1]的判断交换已经结束,
        // 且后面的顺序也为正确,可直接跳出循环
        if (i==2)  break;

        counts++;

    }

    for (int i = 0; i < size; i++)
    {
        printf("%d",arr[i]);    //輸出: 23457
    }
    
}




// // 冒泡排序优化前
// // 部分比较操作多余,最后一次比较还多走一次循环
// #include <stdio.h>
// int main()
// {
//     int arr[5] = {4, 5, 7, 3, 2};   // 正确答案 : 2,3,4,5,7
//     int size = sizeof(arr) / sizeof(arr[0]);
//     while (1)
//     {
//         int counts = 0;         //counts:存儲本次循环交换元素的次数
//         for (int i = 1; i < size-1; i++)
//         {

//             if (arr[i - 1] > arr[i])
//             {
//                 //将元素与上一个元素比较,若小于上一个元素,则交换数据
//                 int z = arr[i - 1];
//                 arr[i - 1] = arr[i];
//                 arr[i] = z;
//                 counts++;           //每当交换一次元素时,counts加1.
//             }
//         }
//         if (counts == 0)        //当某一次交换的次数为0时,代表所有数字已经排序完毕,可结束排序.
//         {
//             break;
//         }
//     }
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d",arr[i]);    //輸出: 23457
//     }
    
// }
