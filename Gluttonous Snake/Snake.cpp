//
// Created by Piece on 2022/7/16.
//

#include "Snake.h"
#include <Windows.h>

void gotoxy1(HANDLE hOut1,int x,int y)
{
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(hOut1,pos);
}
HANDLE hOut1=GetStdHandle(STD_OUTPUT_HANDLE);

Snake::Snake(Wall &mp,Food &food) : wall(mp) ,food(food)
{

}

void Snake::initSnake()
{
    destroyPoint();
    addPoint(5,4);
    addPoint(5,5);
    addPoint(5,6);
}

void Snake::destroyPoint()
{
    while(!q.empty())
    {
        wall.setWall(q.front().first,q.front().second,' ');
        gotoxy1(hOut1,q.front().second*2,q.front().first);
        cout<<" ";
        q.pop_front();
    }
}

void Snake::addPoint(int x,int y)
{
    if(q.empty())
    {
        q.push_front(make_pair(x, y));
        wall.setWall(x, y, '@');
        gotoxy1(hOut1,y*2,x);
        cout<<"@";
    }
    else
    {
        wall.setWall(q.front().first,q.front().second,'+');
        gotoxy1(hOut1,q.front().second*2,q.front().first);
        cout<<"+";

        q.push_front(make_pair(x,y));

        wall.setWall(x,y,'@');
        gotoxy1(hOut1,y*2,x);
        cout<<"@";
    }
}

void Snake::deletPoint()
{
    if(q.size()<=3) return;

    wall.setWall(q.back().first,q.back().second,' ');
    gotoxy1(hOut1,q.back().second*2,q.back().first);
    cout<<" ";

    q.pop_back();
}

bool Snake::move(char key)
{
    int x=q.front().first;
    int y=q.front().second;
    if(tolower(key)=='w') x--;
    else if(tolower(key)=='s') x++;
    else if(tolower(key)=='a') y--;
    else if(tolower(key)=='d') y++;

    if(wall.getWall(x,y)=='+')
    {
        if(make_pair(x,y)==q.back())
        {
            deletPoint();
            addPoint(x,y);
        }else
        {
            addPoint(x,y);
            //system("cls");
            //wall.printWall();
            gotoxy1(hOut1,wall.m/2,wall.n/2);
            cout<<"GAMAE OVER\n";
            return false;
        }
    }
    if(wall.getWall(x,y)=='#')
    {
        addPoint(x,y);
        deletPoint();
        //system("cls");
        //wall.printWall();
        gotoxy1(hOut1,wall.m/2,wall.n/2);
        cout<<"GAMAE OVER\n";
        return false;
    }
    if(wall.getWall(x,y)=='*')
    {
        addPoint(x,y);
        if(getsize()<(wall.n-2)*(wall.m-2)) food.setFood();
    }
    if(wall.getWall(x,y)==' ')
    {
        addPoint(x,y);
        deletPoint();
    }
    return true;
}

int Snake::getsize()
{
    wall.score=int(q.size())-3;
    gotoxy1(hOut1,35,7);
    cout<<wall.score;
    return int(q.size());
}

int Snake::getSleepTime()
{
    int time=0;
    getsize();
    if(wall.score<10) time=300000,wall.difficulty=1;
    else if(wall.score<50) time=250000,wall.difficulty=2;
    else time=200000,wall.difficulty=3;
    gotoxy1(hOut1,35,8);
    cout<<wall.difficulty;
    return time;
}

