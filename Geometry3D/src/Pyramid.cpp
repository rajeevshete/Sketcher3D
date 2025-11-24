#include "Pyramid.h"

Pyramid::Pyramid(const std::string& name, const Point& baseOrigin, const double& length, const double& breadth, const double& height)
    : Shape(name), baseOrigin_(baseOrigin), length_(length), breadth_(breadth), height_(height)
{
}

std::vector<Point> Pyramid::getCoordinates() const
{
    double x = baseOrigin_.getX();
    double y = baseOrigin_.getY();
    double z = baseOrigin_.getZ();

    // Base rectangle points
    Point p0(x, y, z);
    Point p1(x + length_, y, z);
    Point p2(x + length_, y + breadth_, z);
    Point p3(x, y + breadth_, z);

    // Apex point
    Point apex(x + length_ / 2.0, y + breadth_ / 2.0, z + height_);

    return { p0, p1, p2, p3, apex };
}

void Pyramid::write(std::ostream& os) const
{
    os << "Pyramid dimensions: length = " << length_ << ", breadth = " << breadth_ << ", height = " << height_ << "\n";
}

void Pyramid::printEdge(std::ostream& os, const Point& a, const Point& b) const
{
    os << a.getX() << " " << a.getY() << " " << a.getZ() << "\n";
    os << b.getX() << " " << b.getY() << " " << b.getZ() << "\n";
    os << "\n"; 
}

void Pyramid::writeForGnu(std::ostream& os) const
{
    auto p = getCoordinates();

    // Base edges
    printEdge(os, p[0], p[1]);
    printEdge(os, p[1], p[2]);
    printEdge(os, p[2], p[3]);
    printEdge(os, p[3], p[0]);

    // Side edges (to apex)
    printEdge(os, p[0], p[4]);
    printEdge(os, p[1], p[4]);
    printEdge(os, p[2], p[4]);
    printEdge(os, p[3], p[4]);
}
