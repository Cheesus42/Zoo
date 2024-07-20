#include "Space.h"
#include <iostream>
#include <algorithm>

void Exhibit::addAnimal(Animal* animal){
    this->animals.push_back(animal);
        animal->posX < 1 ? animal->posX = 1: animal->posX;
        animal->posX >= sizeX ? animal->posX = (sizeX-1): animal->posX;
        animal->posY < 1 ? animal->posY = 1: animal->posY;
        animal->posY >= sizeY ? animal->posY = (sizeY-1): animal->posY;
        field[animal->posY][animal->posX] = animal;
    
}

void Exhibit::removeAnimal(Animal* animal){
    this->animals.erase(std::remove(this->animals.begin(), this->animals.end(), animal), this->animals.end());
    field[animal->posY][animal->posX] = nullptr;
}

void Exhibit::displayExhibit(){
    for (int i = 0; i < sizeY; ++i) {
        for (int j = 0; j < sizeX; ++j) {
            if(field[i][j] == nullptr){
                std::cout<< ".";
            }else{
                std::cout<<field[i][j]->asciiModel();
            }
        }
        std::cout<< std::endl;
    }
}