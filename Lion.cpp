#include "Animal.h"
#include <random>


std::string Lion::show(){
    return "Lion \U0001F981";
}
std::string Lion::confess(Animal* animal, Exhibit* exib){
    if(typeid(*animal) == typeid(*this)){
        if(!(animal->gender == this->gender) || (animal->sex == BI || animal->sex == HOMO)){
            int rand = randomNum(1, 60);
            if(rand <= 0){
                return "Yay " + this->show() + " " + this->name + " confessed to " + animal->show() + " " + animal->name +" and it worked, they are now together as a pair.";
            }else if(rand >= 80){
                return "Oh No " + this->show() + " " + this->name + " confessed to " + animal->show() + " " + animal->name + ", but it didn't work out for them. " + this->name + " is now sad.";
            }else{
                int animalNum  = exib->animals.size();
                Animal* aboutToDie = nullptr;
                do{
                    int aboutToDieIndex = randomNum(0, animalNum - 1);
                    aboutToDie = exib->animals[aboutToDieIndex];
                }while (aboutToDie == this);

                std::cout<<"Oh No " << this->show() << " " << this->name << " confessed to " << animal->show() << " " << animal->name << ", but it didn't work out for them. " << this->name << " got Angry and killed a random " << aboutToDie->show() << std::endl;
                exib->removeAnimal(aboutToDie);
                delete aboutToDie;
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
std::string Lion::asciiModel(){
    return "L";
}