//
// Created by Piece on 2022/7/16.
//

#include "Food.h"
#include <Windows.h>

void gotoxy2(HANDLE hOut2,int x,int y)
{
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(hOut2,pos);
}
HANDLE hOut2=GetStdHandle(STD_OUTPUT_HANDLE);

Food::Food(Wall &mp) : wall(mp)
{

}

void Food::setFood()
{
    //cout<<Foodx<<" "<<Foody<<endl;
    while(wall.getWall(Foodx,Foody)!=' ')
    {
        Foodx=rand()%(Wall::n-2)+1;
        Foody=rand()%(Wall::m-2)+1;
    }
    wall.setWall(Foodx,Foody,'*');
    gotoxy2(hOut2,Foody*2,Foodx);
    cout<<"*";
}
