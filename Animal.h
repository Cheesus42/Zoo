#ifndef __ANIMAL__
#define __ANIMAL__

#include <string>
#include <iostream>
#include "Space.h"

class Exhibit;

enum Gender{
    MALE, FEMALE, ZWITTER
};
enum Sexuality{
    HETERO, HOMO, BI, ASEX
};
class Animal{
public:
    std::string name;
    Gender gender;
    Sexuality sex;
    float posX;
    float posY;
    bool wet = false;

    virtual std::string show() = 0;
    virtual std::string eat() = 0;
    virtual std::string fight(Animal* animal) = 0;
    virtual std::string confess(Animal* animal) = 0;
    float distanceTo(Animal* animal);

    virtual ~Animal(){
        std::cout<< "Unknown Animal " << this->name << " has been killed :(";
    }
};

class Elephant : public Animal{
public:
    Elephant(std::string name, Gender gender, Sexuality sex, float posX=1.0, float posY=1.0){
        this->name = name;
        this->gender = gender;
        this->sex = sex;
        this->posX = posX;
        this->posY = posY;
    }
    ~Elephant(){
        std::cout<< this->show() << this->name << " has been killed :(";
    }
    std::string show() override;
    std::string eat() override;
    std::string fight(Animal* animal) override;
    std::string confess(Animal* animal) override;

    std::string waterFountain(Exhibit* ex, float radius);

};
#endif // __ANIMAL__