#include "Animal.h"
#include <iostream>

int main(){
    Elephant* ele1 = new Elephant("gandalf", MALE, BI);
    Elephant* ele2 = new Elephant("saruman", MALE, BI);

    std::cout<< ele1->eat() << "\n";
    std::cout<< ele1->confess(ele2);

    delete[] ele1, ele2;
}

