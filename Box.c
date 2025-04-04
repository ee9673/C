// 推箱子小游戏 (未优化)
// 问题1:关卡太少
// 问题2:大部分逻辑都在主函数大型循环里未封装
// 问题3:玩家不能站在目的地上
// 只可使用'w','s','a','d'键控制移动
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SPACE 0  // space : 空地
#define WALL 1   // wall : 墙
#define DESC 2   // destination : 目的地
#define BOX 3    // box : 箱子
#define PLAYER 4 // player : 玩家

int ope = 0;
int map[10][10] =
{0,0,0,0,0,0,0,0,0,0,
 0,0,1,1,1,1,0,0,0,0,
 0,0,1,0,2,1,0,0,0,0,
 0,0,1,0,3,1,0,0,0,0,
 1,1,1,0,0,1,1,1,1,1,
 1,2,0,3,0,0,0,0,0,1,
 1,0,0,0,4,3,0,0,2,1,
 1,0,3,0,1,1,1,1,1,1,
 1,0,2,0,1,0,0,0,0,0,
 1,1,1,1,1,0,0,0,0,0};
//  char ope = 0;
int pass();


//地图画面实现
int game_Pict(){ 
    for (int i = 0; i < 10; i++)
    {
        for (int k = 0; k < 10; k++)
        {
            switch (map[i][k])
            {
            case SPACE:
            {
                printf("  ");
                break;
            }
            case WALL:
            {
                printf("▓▓");
                break;
            }
            case DESC:
            {
                printf("☆ ");
                break;
            }
            case BOX:
            {
                printf("口");
                break;
            }
            case PLAYER:
            {
                printf("♀ ");
                break;
            }
            case BOX + DESC:
            {
                printf("★ ");
                break;
            }

            default:
            {
                printf(" ");
                break;
            }
            }
            if (k == 9)
            {
                printf(" \n");
            }
        }
    }
}

int main()
{
    

    
    while (true)
    {
        // 游戏界面
        game_Pict();
        // 操作
        // ope = _getch()
        // 119 w
        // 115 s
        // 97 a
        // 100 d

        int x, y = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (map[i][k] == PLAYER)
                {
                    x = i;
                    y = k;
                    break;
                }
            }
        }
        ope = _getch();
        switch (ope)
        {
        // 向上移动
        case 'w':
        case 'W':
            // case 224:
            {
                // 判定移动方向为空地
                if (map[x - 1][y] == SPACE)
                {
                    map[x - 1][y] += map[x][y];
                    map[x][y] -= map[x][y];

                } // 否则如果前方有箱子,并且箱子前方不是墙
                else if ((map[x - 1][y] == BOX) && (map[x - 2][y] != WALL))
                {
                    map[x - 1][y] += map[x][y];
                    map[x - 2][y] += BOX;
                    map[x - 1][y] -= BOX;
                    map[x][y] -= map[x][y];
                }
                break;
            }
        // 向下移动
        case 's':
        case 'S':

        {
            if (map[x + 1][y] == SPACE)
            {
                map[x + 1][y] += map[x][y];
                map[x][y] -= map[x][y];

            } // 否则如果前方有箱子,并且箱子前方不是墙
            else if ((map[x + 1][y] == BOX) && (map[x + 2][y] != WALL))
            {
                map[x + 1][y] += map[x][y];
                map[x + 2][y] += BOX;
                map[x + 1][y] -= BOX;
                map[x][y] -= map[x][y];
            }
            break;
        }
        // 向左移动
        case 'A':
        case 'a':
        {
            if (map[x][y - 1] == SPACE)
            {
                map[x][y - 1] += map[x][y];
                map[x][y] -= map[x][y];

            } // 否则如果前方有箱子,并且箱子前方不是墙
            else if ((map[x][y - 1] == BOX) && (map[x][y - 2] != WALL))
            {
                map[x][y - 1] += map[x][y];
                map[x][y - 2] += BOX;
                map[x][y - 1] -= BOX;
                map[x][y] -= map[x][y];
            }
            break;
        }
        // 向右移动
        case 'D':
        case 'd':
        {
            if (map[x][y + 1] == SPACE)
            {
                map[x][y + 1] += map[x][y];
                map[x][y] -= map[x][y];

            } // 否则如果前方有箱子,并且箱子前方不是墙
            else if ((map[x][y + 1] == BOX) && (map[x][y + 2] != WALL))
            {
                map[x][y + 1] += map[x][y];
                map[x][y + 2] += BOX;
                map[x][y + 1] -= BOX;
                map[x][y] -= map[x][y];
            }
            break;
        }

        default:
            printf("%d", ope);
            getchar();
            break;
        }
        // 刷新屏幕
        system("cls");
        if (pass())
        {
            printf("you win");
            break;
        }
    }
}

// 判定胜利条件
int pass()
{
    for (int a = 0; a < 10; a++)
    {
        for (int b = 0; b < 10; b++)
        {
            if (map[a][b] == BOX)
            {
                return 0;
            }
        }
    }
    return 1;
}

