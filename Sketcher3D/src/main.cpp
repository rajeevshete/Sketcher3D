#include "ShapeCreator.h"

#include <iostream>

int main() {
    ShapeCreator creator;


    creator.read();

    if (creator.getShapeCount() > 0) {
        creator.write(0); 
        std::cout << "Shape written to 'Data.dat'.\n";
    }
    else {
        std::cout << "No shape was created.\n";
    }

    return 0;
}
