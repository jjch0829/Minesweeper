#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

/*#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW 224

void GotoXY(int x, int y) {
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void CursorView(char show)
{
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}
int Move_Cursor() {

    int x = 30;
    int y = 7;
    CursorView(0);
    GotoXY(x, y);
    printf("★");
    while (1) {
        if (_kbhit()) {
            int nkey = _getch();
            if (nkey == ARROW) {
                nkey = _getch();
                switch (nkey) {
                case UP:
                    system("cls");
                    GotoXY(x, --y);
                    printf("★");
                    break;
                case LEFT:
                    system("cls");
                    GotoXY(x = x - 2, y);
                    printf("★");
                    break;
                case RIGHT:
                    system("cls");
                    GotoXY(x = x + 2, y);
                    printf("★");
                    break;
                case DOWN:
                    system("cls");
                    GotoXY(x, ++y);
                    printf("★");
                    break;

                }
            }
        }
    }

    return 0;
}
*/
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

void Boom(int a[32][32], int b[32][32]) //지뢰가 터졌을시 사용함수
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
/*
int key_Board(int map[32][32], int checking[32][32], int Printing[32][32])
{
    int c, d;
    for (;;)
    {
        if (_kbhit())
        {        //키보드 입력 확인 (true / false)
            c = _getch();      // 방향키 입력시 224 00이 들어오게 되기에 앞에 있는 값 224를 없앰
            if (c == -32)
            {    // -32로 입력되면
                c = _getch();  // 새로 입력값을 판별하여 상하좌우 출력
                switch (c)
                {
                case LEFT:
                    //printf("왼쪽으로 이동\n");
                    c--;
                    break;
                case RIGHT:
                    //printf("오른쪽으로 이동\n");
                    c++;
                    break;
                case UP:
                    //printf("위로 이동\n");
                    d++;
                    break;
                case DOWN:
                    //printf("아래로 이동\n");
                    c--;
                    break;
                }
            }
        }
    }
    if (c >= 31 || d >= 31 || c < 1 || d < 1)
    {
        printf("no range\n");
        Sleep(1000);
    }
    else if (map[c][d] == 1)
    {
        checking[c][d] = 1;
        system("cls");
        printf("Boom!!\n");
        printf("Bomb location\n");
        Boom(map, checking);
        return 0;
    }
    else if (checking[c][d] == 1)
    {
        printf("already checked\n");
        return 1;
    }
    else if (map[c][d] >= 100)
    {
        printf("Safed location\n");
        checking[c][d] = 1;
        return 1;
    }

    //Sleep(1000);
    system("cls");
    return 1;
}
*/
int User_Input(int map[32][32], int checking[32][32], int Printing[32][32]) //입력 메인함수
{
    int c, d;
    printf("x location input: ");
    scanf_s("%d", &c);
    printf("y location input: ");
    scanf_s("%d", &d);

    if (c >= 31 || d >= 31 || c < 1 || d < 1)
    {
        printf("no range\n");
        Sleep(1000);
    }
    else if (map[c][d] == 1)
    {
        checking[c][d] = 1;
        system("cls");
        printf("Boom!!\n");
        printf("Bomb location\n");
        Boom(map, checking);
        return 0;
    }
    else if (checking[c][d] == 1)
    {
        printf("already checked\n");
        return 1;
    }
    else if (map[c][d] >= 100)
    {
        printf("Safed location\n");
        checking[c][d] = 1;
        return 1;
    }

    //Sleep(1000);
    system("cls");
    return 1;
}

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
                    b[i][p] = 1;
                }
            }
        }
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

    Judge_Num(map, checking);

}

int main()
{
    int map[32][32];
    int Printing[32][32];
    int checking[32][32];
    int wd = 1, game = 1; //초기 변수 선언

    while (wd == 1) // 프로그램 종료 여부
    {
        ini_set(map, Printing, checking);
        while (game == 1) //게임 승리 여부 
        {
            system("cls");
            User_Printing(checking, map);
            game = User_Input(map, checking, Printing);
            wd = game;
            Sleep(1000);
        }
        /*int ans;
        Sleep(10000);
        printf("Do You Wanna Play Game More? \n");
        printf("If You Want Input 'Y' : \n");
        scanf("%d", &ans);
        if (ans == 1)
        {
            wd = 0;
            printf("Thanks For Playing Game");
        }*/
    }
}


