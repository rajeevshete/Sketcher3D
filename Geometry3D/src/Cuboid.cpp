#include "Cuboid.h"

// Cuboid constructor
Cuboid::Cuboid(const std::string& name,
    const Point& origin,
    const double& length,
    const double& breadth,
    const double& height)
    : Shape(name), origin_(origin), length_(length), breadth_(breadth), height_(height)
{
}

// Cube constructor
Cuboid::Cuboid(const std::string& name,
    const Point& origin,
    const double& side)
    : Shape(name), origin_(origin), length_(side), breadth_(side), height_(side)
{
}

std::vector<Point> Cuboid::getCoordinates() const
{
    double x = origin_.getX();
    double y = origin_.getY();
    double z = origin_.getZ();

    // 8 vertices of the cuboid
    return {
        // bottom rectangle
        Point(x, y, z),                  // 0
        Point(x + length_, y, z),        // 1
        Point(x + length_, y + breadth_, z), // 2
        Point(x, y + breadth_, z),       // 3

        // top rectangle
        Point(x, y, z + height_),        // 4
        Point(x + length_, y, z + height_), // 5
        Point(x + length_, y + breadth_, z + height_), // 6
        Point(x, y + breadth_, z + height_)  // 7
    };
}

void Cuboid::write(std::ostream& os) const
{
    os << "Cuboid dimensions: ";
    os << "length=" << length_ << " ";
    os << "breadth=" << breadth_ << " ";
    os << "height=" << height_ << "\n";
}

void Cuboid::printEdge(std::ostream& os,
    const std::vector<Point>& p,
    int a,
    int b) const
{
    os << p[a].getX() << " " << p[a].getY() << " " << p[a].getZ() << "\n";
    os << p[b].getX() << " " << p[b].getY() << " " << p[b].getZ() << "\n";
    os << "\n\n";  
}

void Cuboid::writeForGnu(std::ostream& os) const
{
    auto p = getCoordinates();

    // bottom rectangle
    printEdge(os, p, 0, 1);
    printEdge(os, p, 1, 2);
    printEdge(os, p, 2, 3);
    printEdge(os, p, 3, 0);

    // vertical edges
    printEdge(os, p, 0, 4);
    printEdge(os, p, 1, 5);
    printEdge(os, p, 2, 6);
    printEdge(os, p, 3, 7);

    // top rectangle
    printEdge(os, p, 4, 5);
    printEdge(os, p, 5, 6);
    printEdge(os, p, 6, 7);
    printEdge(os, p, 7, 4);
}
