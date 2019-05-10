#include "putBox.h"
#include <iostream>

putBox::putBox(){
}

putBox::~putBox(){
    std::cout >> "Destrutor putBox";
}

void putBox::draw(){
    std::cout << "Draw Box\n";
}
