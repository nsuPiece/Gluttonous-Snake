//
// Created by Piece on 2022/7/16.
//

#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H
#include <bits/stdc++.h>
#include "Wall.h"
using namespace std;

class Food
{
public:

    Food(Wall & mp);
    int Foodx=5;
    int Foody=7;

    void setFood();

    Wall & wall;

};

#endif //SNAKE_FOOD_H
