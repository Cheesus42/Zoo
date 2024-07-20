#ifndef __SPACE__
#define __SPACE__

#include "Animal.h"
#include <vector>
#include <string>
class Animal;


class Exhibit {
public:
    int sizeX;
    int sizeY;
    std::string name;
    int size;
    std::vector<Animal*> animals;
    Animal*** field;
    Exhibit(std::string name, int sizeX, int sizeY){
        this->name = name;
        this->sizeX = sizeX;
        this->sizeY = sizeY;
        field = new Animal**[sizeX];
        for (int i = 0; i < sizeX; i++)
        {
            field[i] = new Animal*[sizeY];
            for (int j = 0; j < sizeY; j++)
            {
                field[i][j] = nullptr;
            }   
        }
    }
    ~Exhibit(){
        for (int i = 0; i < sizeX; ++i) {
            delete[] field[i];
        }
        delete[] field;
    }
    void addAnimal(Animal* animal);
    void displayExhibit();
};
#endif //__SPACE__