#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void Judge_Num(int a[32][32], int b[32][32]) //지뢰 개수 판단 함수
{
    for (int i = 1; i < 31; i++)
    {
        for (int p = 1; p < 31; p++)
        {
            if (a[i][p] == 100)
            {
                int sum = 0;
                for (int j = -1; j < 2; j++)
                {
                    if (a[i + 1][p + j] == 1)
                    {
                        sum += 1;
                    }
                }
                if (a[i][p - 1] == 1)
                {
                    sum += 1;
                }
                if (a[i][p + 1] == 1)
                {
                    sum += 1;
                }
                for (int j = -1; j < 2; j++)
                {
                    if (a[i - 1][p + j] == 1)
                    {
                        sum += 1;
                    }
                }
                a[i][p] += sum;
                if (a[i][p] == 100)
                {
                   // b[i][p] = 1;
                }
            }
        }
    }
}

void User_Printing(int a[32][32], int b[32][32]) //프린트 메인 함수
{
    for (int i = 1; i < 31; i++)
    {
        for (int p = 1; p < 31; p++)
        {
            if (a[i][p] == 0)//unopened
                printf("■");
            else if (a[i][p] == 1)
            {

                int num = b[i][p] - 100;
                switch (num)
                {

                case 1:

                    printf("①");

                    break;

                case 2:

                    printf("②");

                    break;

                case 3:

                    printf("③");

                    break;

                case 4:

                    printf("④");

                    break;

                case 5:

                    printf("⑤");

                    break;

                case 6:

                    printf("⑥");

                    break;

                case 7:

                    printf("⑦");

                    break;

                case 8:

                    printf("⑧");

                    break;

                case 0:

                    printf("  ");

                    break;
                default:

                    printf("※");

                    break;
                }

            }
        }
        printf("\n");
    }
}

void ini_set(int map[32][32], int Printing[32][32], int checking[32][32])
{
    srand(time(NULL));
    int a, b, k;
    for (int i = 0; i < 32; i++)//배열 모든값 0으로 해줌
    {
        for (int j = 0; j < 32; j++)
        {
            if (i == 0 || i == 31 || j == 0 || j == 31)
            {
                map[i][j] = 0;
            }
            else
            {
                map[i][j] = 100;
            }
            Printing[i][j] = 0;
            checking[i][j] = 0;
        }
    }
    printf("input Number of Bombs \n");
    scanf_s("%d", &k);
    for (int i = 0; i < k; i++)//지뢰생성
    {

        while (1)
        {
            a = rand() % 30 + 1;
            b = rand() % 30 + 1;
            if (map[a][b] == 1)
                ;
            else
            {
                map[a][b] = 1;
                Printing[a][b] = 1;
                break;
            }
        }

        map[a][b] = 1;
        Printing[a][b] = 1;
    }

    Judge_Num(map,checking);

}

void Boom(int a[32][32], int b[32][32])
{
    for (int i = 1; i < 31; i++)
    {
        for (int p = 1; p < 31; p++)
        {
            b[i][p] = 1;
        }
    }
    User_Printing(b, a);
}

int main()
{
    int map[32][32];
    int Printing[32][32];
    int checking[32][32];
    int wd = 1;
    int c, d;
    ini_set(map, Printing, checking);

    while (wd == 1)
    {
        User_Printing(checking, map);
        printf("x location input: ");
        scanf_s("%d", &c);
        printf("y location input: ");
        scanf_s("%d", &d);

        if (c >= 31 || d >= 31 || c < 1 || d < 1)
        {
            printf("no range\n");
        }
        else if (map[c][d] == 1)
        {
            int any;
            checking[c][d] = 1;
            system("cls");
            printf("Boom!!\n");
            printf("Bomb location\n");
            Boom(map, checking);
            scanf_s("%d", &any);
            wd = 0;
        }
        else if (checking[c][d] == 1)
        {
            printf("already checked\n");
        }
        else if (map[c][d] >= 100)
        {
            printf("Safed location\n");
            checking[c][d] = 1;
        }

        //Sleep(1000);
        system("cls");
    }
    printf("Bomed location\n");

}