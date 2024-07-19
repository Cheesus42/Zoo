#include "Animal.h"
#include <iostream>
#include <random>

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
            std::uniform_int_distribution<> distrib(1, 10);
            int rand = distrib(gen);
            if(rand <= 6){
                return "Yay " + this->show() + " " + this->name + " confessed to " + animal->show() + " " + animal->name +" and it worked, they are now together as a pair.";
            }else{
                return "Oh No " + this->show() + " " + this->name + " confessed to " + animal->show() + " " + animal->name + ", but it didn't work out for them. " + this->name + " is now sad.";
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

std::string Elephant::walk(){
    return "Elephant " + this->name + " is walking";
}
