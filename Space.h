#ifndef __SPACE__
#define __SPACE__

#include "Animal.h"
#include <vector>
#include <string>
class Animal;


class Space{
public:
    float sizeX;
    float sizeY;
};

class Exhibit : public Space{
public:
    std::string name;
    int size;
    std::vector<Animal*> animals;
    Exhibit(std::string name, float sizeX, float sizeY){
        this->sizeX = sizeX;
        this->sizeY = sizeY;
        this->name = name;
    }

    void addAnimal(Animal* animal);
};
#endif //__SPACE__