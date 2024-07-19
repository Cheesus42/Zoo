#ifndef __ANIMAL__
#define __ANIMAL__

#include <string>

enum Gender{
    MALE, FEMALE, ZWITTER
};
enum Sexuality{
    HETERO, HOMO, BI
};
class Animal{
public:
    std::string name;
    Gender gender;
    Sexuality sex;

    virtual std::string show() = 0;
    virtual std::string eat() = 0;
    virtual std::string fight(Animal* animal) = 0;
    virtual std::string confess(Animal* animal) = 0;

    virtual ~Animal(){}
};

class Elephant : public Animal{
public:
    Elephant(std::string name, Gender gender, Sexuality sex){
        this->name = name;
        this->gender = gender;
        this->sex = sex;
    }
    std::string show() override;
    std::string eat() override;
    std::string fight(Animal* animal) override;
    std::string confess(Animal* animal) override;

    std::string walk();

};
#endif // __ANIMAL__