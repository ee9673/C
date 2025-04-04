// ������С��Ϸ (δ�Ż�)
// ����1:�ؿ�̫��
// ����2:�󲿷��߼���������������ѭ����δ��װ
// ����3:��Ҳ���վ��Ŀ�ĵ���
// ֻ��ʹ��'w','s','a','d'�������ƶ�
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SPACE 0  // space : �յ�
#define WALL 1   // wall : ǽ
#define DESC 2   // destination : Ŀ�ĵ�
#define BOX 3    // box : ����
#define PLAYER 4 // player : ���

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


//��ͼ����ʵ��
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
                printf("����");
                break;
            }
            case DESC:
            {
                printf("�� ");
                break;
            }
            case BOX:
            {
                printf("��");
                break;
            }
            case PLAYER:
            {
                printf("�� ");
                break;
            }
            case BOX + DESC:
            {
                printf("�� ");
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
        // ��Ϸ����
        game_Pict();
        // ����
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
        // �����ƶ�
        case 'w':
        case 'W':
            // case 224:
            {
                // �ж��ƶ�����Ϊ�յ�
                if (map[x - 1][y] == SPACE)
                {
                    map[x - 1][y] += map[x][y];
                    map[x][y] -= map[x][y];

                } // �������ǰ��������,��������ǰ������ǽ
                else if ((map[x - 1][y] == BOX) && (map[x - 2][y] != WALL))
                {
                    map[x - 1][y] += map[x][y];
                    map[x - 2][y] += BOX;
                    map[x - 1][y] -= BOX;
                    map[x][y] -= map[x][y];
                }
                break;
            }
        // �����ƶ�
        case 's':
        case 'S':

        {
            if (map[x + 1][y] == SPACE)
            {
                map[x + 1][y] += map[x][y];
                map[x][y] -= map[x][y];

            } // �������ǰ��������,��������ǰ������ǽ
            else if ((map[x + 1][y] == BOX) && (map[x + 2][y] != WALL))
            {
                map[x + 1][y] += map[x][y];
                map[x + 2][y] += BOX;
                map[x + 1][y] -= BOX;
                map[x][y] -= map[x][y];
            }
            break;
        }
        // �����ƶ�
        case 'A':
        case 'a':
        {
            if (map[x][y - 1] == SPACE)
            {
                map[x][y - 1] += map[x][y];
                map[x][y] -= map[x][y];

            } // �������ǰ��������,��������ǰ������ǽ
            else if ((map[x][y - 1] == BOX) && (map[x][y - 2] != WALL))
            {
                map[x][y - 1] += map[x][y];
                map[x][y - 2] += BOX;
                map[x][y - 1] -= BOX;
                map[x][y] -= map[x][y];
            }
            break;
        }
        // �����ƶ�
        case 'D':
        case 'd':
        {
            if (map[x][y + 1] == SPACE)
            {
                map[x][y + 1] += map[x][y];
                map[x][y] -= map[x][y];

            } // �������ǰ��������,��������ǰ������ǽ
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
        // ˢ����Ļ
        system("cls");
        if (pass())
        {
            printf("you win");
            break;
        }
    }
}

// �ж�ʤ������
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

