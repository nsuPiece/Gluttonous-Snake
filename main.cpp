#include <bits/stdc++.h>
#include "Wall.h"
#include "Snake.h"
#include "Food.h"
#include <unistd.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

void gotoxy(HANDLE hOut,int x,int y)
{
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(hOut,pos);
}
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);


void solve()
{

    Wall wall;
    wall.initWall();
    wall.printWall();

    Food food(wall);
    food.setFood();

    Snake snake(wall, food);
    snake.initSnake();


    bool isDead= false;
    char pre='!';
    while (!isDead)
    {
        char key=tolower(getch());
        if(pre=='!'&&key=='a') continue;
        do {
            if(key!='w'&&key!='s'&&key!='a'&&key!='d') key=pre;
            if((pre=='a'&&key=='d')||(pre=='d'&&key=='a')||(pre=='w'&&key=='s')||(pre=='s'&&key=='w')) key=pre;
            if(snake.move(key))
            {
                pre=key;
                //system("cls");
                //wall.printWall();
                usleep(snake.getSleepTime());
            }else
            {
                isDead= true;
                break;
            }
            if(snake.getsize()==(wall.n-2)*(wall.m-2))
            {
                //system("cls");
                //wall.printWall();
                gotoxy(hOut,wall.m/2,wall.n/2);
                cout<<"YOU WIN!";
                gotoxy(hOut,wall.m/2,wall.n/2+1);
                cout<<"投B继续";
                gotoxy(hOut,wall.m/2,wall.n/2+2);
                cout<<"按Q退出";
                return ;
            }

        }while(!kbhit());

    }
    gotoxy(hOut,wall.m/2,wall.n/2+1);
    cout<<"投B继续";
    gotoxy(hOut,wall.m/2,wall.n/2+2);
    cout<<"按Q退出";
}


int main()
{
    srand(time(nullptr));
    char flag='b';
    while(flag=='b')
    {
        system("cls");
        solve();
        flag=tolower(getch());
        while(flag!='b'&&flag!='q') flag=tolower(getch());
    }
    return 0;
}
