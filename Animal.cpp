#include "Animal.h"
#include <iostream>
#include <random>
#include <cmath>
#include <iostream>
int randomNum(int x, int y);
void Elephant::move(int step, Exhibit* exib){
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

float Animal::distanceTo(Animal* animal){
    float distance;
    distance = std::sqrt(pow((this->posX - animal->posX), 2) + pow((this->posY - animal->posY), 2));
    return distance;
}

std::string Elephant::show(){
    return "Elephant \U0001F418";
}

std::string Elephant::confess(Animal* animal){
    if(typeid(*animal) == typeid(*this)){
        if(!(animal->gender == this->gender) || (animal->sex == BI || animal->sex == HOMO)){
            int rand = randomNum(1, 100);
            if(rand <= 60){
                return "Yay " + this->show() + " " + this->name + " confessed to " + animal->show() + " " + animal->name +" and it worked, they are now together as a pair.";
            }else if(rand >= 80){
                return "Oh No " + this->show() + " " + this->name + " confessed to " + animal->show() + " " + animal->name + ", but it didn't work out for them. " + this->name + " is now sad.";
            }else{
                std::cout<<"Oh No " << this->show() << " " << this->name << " confessed to " << animal->show() << " " << animal->name << ", but it didn't work out for them. " << this->name << " got depressed and killed itself";
                delete this;
                return "";
            }
        }else{
            return "Oh No " + this->show() + " " + this->name + " confessed to " + animal->show() + " " + animal->name + ", but " + animal->name + " isn't attracted to " + this->name + " because of their sexuality.";
        }
        if((animal->gender == this->gender) || (animal->sex == BI || animal->sex == HETERO)){
            int rand = randomNum(1, 10);
            if(rand <= 6){
                return "Yay " + this->show() + " " + this->name + " confessed to " + animal->show() + " " + animal->name +" and it worked, they are now together as a pair.";
            }else{
                return "Oh No " + this->show() + " " + this->name + " confessed to " + animal->show() + " " + animal->name + ", but it didn't work out for them. " + this->name + " is now sad.";
            }
        }
    }else{
        return "Sadly " + animal->name + " isn't an elephant but an " + animal->show() + " strange for " + this->name + " to ask.";
    }
}

std::string Elephant::asciiModel(){
    return "E";
}

std::string Elephant::waterFountain(Exhibit* ex, float radius){
    std::vector<Animal*> animals = ex->animals;
    for (int i = animals.size() - 1; i >= 0; i--)
    {
        if (this->distanceTo(animals[i]) <= radius){
            animals[i]->wet = true;
        }
    }
    return "";
}

int randomNum(int x, int y){
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(x, y);
    return distrib(gen);
}