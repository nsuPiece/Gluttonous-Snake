//
// Created by Piece on 2022/7/16.
//

#include "Wall.h"
void Wall::initWall()
{

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <m ; ++j)
        {
            if(i==0 || i==n-1 || j==0 || j==m-1 )
            {
                mp[i][j]='#';
            }else
            {
                mp[i][j]=' ';
            }

        }
    }
}

void Wall::printWall()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <m ; ++j)
        {
            cout<<mp[i][j]<<" ";
        }
        if(i==1) cout<<"     W:¡ü";
        if(i==2) cout<<"     S:¡ý";
        if(i==3) cout<<"     A:¡û";
        if(i==4) cout<<"     D:¡ú";
        if(i==6) cout<<"create by Piece";
        if(i==7) cout<<"   score   :   "<<score;
        if(i==8) cout<<" difficulty:   "<<difficulty;
        cout<<"\n";
    }
}

void Wall::setWall(int x,int y,char c)
{
    mp[x][y]=c;
}

char Wall::getWall(int x,int y)
{
    return mp[x][y];
}


