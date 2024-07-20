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
        field = new Animal**[sizeY];
        for (int i = 0; i < sizeY; i++)
        {
            field[i] = new Animal*[sizeX];
            for (int j = 0; j < sizeX; j++)
            {
                field[i][j] = nullptr;
            }   
        }
    }
    ~Exhibit(){
        for (int i = 0; i < sizeY; ++i) {
            delete[] field[i];
        }
        delete[] field;
    }
    void addAnimal(Animal* animal);
    void removeAnimal(Animal* animal);
    void displayExhibit();
};
#endif //__SPACE__