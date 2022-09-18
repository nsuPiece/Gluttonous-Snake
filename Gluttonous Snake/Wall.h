//
// Created by Piece on 2022/7/16.
//

#ifndef SNAKE_WALL_H
#define SNAKE_WALL_H
#include <bits/stdc++.h>
using namespace std;
class Wall
{
public:
    int score=0;
    int difficulty=1;
    enum {n=10,m=10};
    void initWall();
    void printWall();
    void setWall(int x,int y,char c);
    char getWall(int x,int y);

private:
    char mp[n][m]{};

};
#endif //SNAKE_WALL_H
