#include "Animal.h"
#include <iostream>
#include <cmath>
#include <random>
#include <iostream>

void Animal::move(int step, Exhibit* exib){
    exib->removeAnimal(this);
    for (int i = 0; i < step; ++i)
    {
        int direction = randomNum(1, 8);
        switch(direction){
        case 1:
            posY += 1;
            break;
        case 2:
            posY += 1;
            posX += 1;
            break;
        case 3:
            posX += 1;
            break;
        case 4:
            posY -= 1;
            posX += 1;
            break;
        case 5:
            posY -= 1;
            break;
        case 6:
            posY -= 1;
            posX -= 1;
            break;
        case 7:
            posX -= 1;
            break;
        case 8:
            posY += 1;
            posX -= 1;
            break;
        default:
            break;
        }   
        posX < 1 ? posX = 1: posX;
        posX > exib->sizeX ? posX = exib->sizeX: posX;
        posY < 1 ? posY = 1: posY;
        posY > exib->sizeY ? posY = exib->sizeY: posY; 
    } 
    exib->addAnimal(this);
}

int Animal::randomNum(int x, int y){
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(x, y);
    return distrib(gen);
}