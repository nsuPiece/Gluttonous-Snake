//
// Created by Piece on 2022/7/16.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include <bits/stdc++.h>
#include "Wall.h"
#include "Food.h"
using namespace std;

class Snake
{
    deque<pair<int,int>>q;
    void destroyPoint();
    Wall &wall;
    Food &food;
public:
    Snake(Wall & mp,Food &food);

    int getsize();
    int getSleepTime();
    void initSnake();
    void deletPoint();
    bool move(char key);
    void addPoint(int x,int y);

};


#endif //SNAKE_SNAKE_H
