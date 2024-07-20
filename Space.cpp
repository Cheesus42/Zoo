#include "Space.h"
#include <iostream>

void Exhibit::addAnimal(Animal* animal){
    this->animals.push_back(animal);
    if(animal->posX <= sizeX && animal->posY <= sizeY && animal->posX > 0, animal->posY > 0){
        field[animal->posX][animal->posY] = animal;
    }
}

void Exhibit::displayExhibit(){
    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            if(field[i][j] == nullptr){
                std::cout<< "#";
            }else{
                std::cout<<field[i][j]->asciiModel();
            }
        }
        std::cout<< std::endl;
    }
    
}