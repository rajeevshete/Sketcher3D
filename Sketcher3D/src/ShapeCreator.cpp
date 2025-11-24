#include "ShapeCreator.h"

#include "Line.h"
#include "Cuboid.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Pyramid.h"

#include <iostream>
#include <fstream>

void ShapeCreator::read() {
    int choice;
    std::cout << "Select shape:\n"
        << "1. Line\n"
        << "2. Cuboid\n"
        << "3. Cube\n"
        << "4. Sphere\n"
        << "5. Cylinder\n"
        << "6. Cone\n"
        << "7. Pyramid (rectangular base)\n";
    std::cin >> choice;

    switch (choice) {
    case 1: {
        double x1, y1, z1, x2, y2, z2;
        std::cout << "Enter first point x y z: ";
        std::cin >> x1 >> y1 >> z1;
        std::cout << "Enter second point x y z: ";
        std::cin >> x2 >> y2 >> z2;
        shapes_.push_back(std::make_unique<Line>("Line", Point(x1, y1, z1), Point(x2, y2, z2)));
        break;
    }

    case 2: {
        double x, y, z, l, b, h;
        std::cout << "Enter origin x y z: "; std::cin >> x >> y >> z;
        std::cout << "Enter Length Breadth Height: "; std::cin >> l >> b >> h;
        shapes_.push_back(std::make_unique<Cuboid>("Cuboid", Point(x, y, z), l, b, h));
        break;
    }

    case 3: {
        double x, y, z, s;
        std::cout << "Enter origin x y z: "; std::cin >> x >> y >> z;
        std::cout << "Enter side length: "; std::cin >> s;
        shapes_.push_back(std::make_unique<Cuboid>("Cube", Point(x, y, z), s)); // cube via cuboid constructor
        break;
    }

    case 4: {
        double x, y, z, r;
        int vSeg = 18, hSeg = 36;
        std::cout << "Enter center x y z: "; std::cin >> x >> y >> z;
        std::cout << "Enter radius: "; std::cin >> r;
        shapes_.push_back(std::make_unique<Sphere>("Sphere", Point(x, y, z), r, vSeg, hSeg));
        break;
    }

    case 5: {
        double x, y, z, r, h;
        int seg = 36;
        std::cout << "Enter base center x y z: "; std::cin >> x >> y >> z;
        std::cout << "Enter radius and height: "; std::cin >> r >> h;
        shapes_.push_back(std::make_unique<Cylinder>("Cylinder", Point(x, y, z), r, h, seg));
        break;
    }

    case 6: {
        double x, y, z, r, h;
        int seg = 36;
        std::cout << "Enter base center x y z: "; std::cin >> x >> y >> z;
        std::cout << "Enter radius and height: "; std::cin >> r >> h;
        shapes_.push_back(std::make_unique<Cone>("Cone", Point(x, y, z), r, h, seg));
        break;
    }

    case 7: {
        double x, y, z, l, b, h;
        std::cout << "Enter base origin x y z: "; std::cin >> x >> y >> z;
        std::cout << "Enter Length Breadth Height: "; std::cin >> l >> b >> h;
        shapes_.push_back(std::make_unique<Pyramid>("Pyramid", Point(x, y, z), l, b, h));
        break;
    }

    default:
        std::cout << "Invalid choice.\n";
        break;
    }
}

void ShapeCreator::write(size_t index) const {
    if (index >= shapes_.size()) return;

    std::ofstream out("data.dat");
    if (!out) {
        std::cout << "Error opening file for writing.\n";
        return;
    }

    shapes_[index]->writeForGnu(out);
}

void ShapeCreator::listShapes() const {
    for (size_t i = 0; i < shapes_.size(); ++i) {
        std::cout << i << ": " << shapes_[i]->getName() << "\n";
    }
}
