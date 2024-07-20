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
    int posX;
    int posY;
    bool wet = false;

    virtual void move(int step, Exhibit* exib) = 0;
    virtual std::string show() = 0;
    virtual std::string confess(Animal* animal) = 0;
    virtual std::string asciiModel() = 0;
    float distanceTo(Animal* animal);

    virtual ~Animal(){
    };
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
    ~Elephant() override {
        std::cout<< this->show() << " " << this->name << " has been killed :(" << std::endl;
    }

    void move(int step, Exhibit* exib) override;
    std::string show() override;
    std::string confess(Animal* animal) override;
    std::string asciiModel() override;

    std::string waterFountain(Exhibit* ex, float radius);

};
#endif // __ANIMAL__