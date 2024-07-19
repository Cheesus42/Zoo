#include "Animal.h"
#include <iostream>
#include <string>

int main(){
    Elephant* ele1 = new Elephant("gandalf", MALE, BI);
    Elephant* ele2 = new Elephant("saruman", MALE, BI);

    int i = 5;
    std::string strings = "Hallo " + std::to_string(i);
    std::cout<< strings;
    std::cout<< ele1->eat() << "\n";
    std::cout<< ele1->confess(ele2);

    delete[] ele1, ele2;
}

