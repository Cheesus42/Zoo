#include "Animal.h"
#include <iostream>
#include <random>
#include <cmath>
#include <iostream>

float Animal::distanceTo(Animal* animal){
    float distance;
    distance = std::sqrt(pow((this->posX - animal->posX), 2) + pow((this->posY - animal->posY), 2));
    return distance;
}

std::string Elephant::show(){
    return "Elephant \U0001F418";
}
std::string Elephant::eat(){
    return this->show() + " Elephant is eating";
}

std::string Elephant::fight(Animal* animal){
    return "Elephant " + this->name + " is fighting " + animal->name;
}

std::string Elephant::confess(Animal* animal){
    if(typeid(*animal) == typeid(*this)){
        if(!(animal->gender == this->gender) || (animal->sex == BI || animal->sex == HOMO)){
            std::random_device rd;  // a seed source for the random number engine
            std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
            std::uniform_int_distribution<> distrib(1, 100);
            int rand = distrib(gen);
            if(rand <= 60){
                return "Yay " + this->show() + " " + this->name + " confessed to " + animal->show() + " " + animal->name +" and it worked, they are now together as a pair.";
            }else if(rand >= 80){
                return "Oh No " + this->show() + " " + this->name + " confessed to " + animal->show() + " " + animal->name + ", but it didn't work out for them. " + this->name + " is now sad.";
            }else{
                std::cout<<"Oh No " << this->show() << " " << this->name << " confessed to " << animal->show() << " " << animal->name << ", but it didn't work out for them. " << this->name << " got depressed and killed itself";
                delete[] this;
                return "";
            }
        }else{
            return "Oh No " + this->show() + " " + this->name + " confessed to " + animal->show() + " " + animal->name + ", but " + animal->name + " isn't attracted to " + this->name + " because of their sexuality.";
        }
        if((animal->gender == this->gender) || (animal->sex == BI || animal->sex == HETERO)){
            std::random_device rd;  // a seed source for the random number engine
            std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
            std::uniform_int_distribution<> distrib(1, 10);
            int rand = distrib(gen);
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
