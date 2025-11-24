#include "Cylinder.h"
#include <cmath>

Cylinder::Cylinder(const std::string& name, const Point& center, const double& radius, const double& height, const int& segments)
    : Shape(name), center_(center), radius_(radius), height_(height), segments_(segments) {}

std::vector<Point> Cylinder::getCoordinates() const
{
    return {};
}

void Cylinder::write(std::ostream& os) const
{
    os << "Cylinder: radius = " << radius_ << ", height = " << height_ << "\n";
}

void Cylinder::printEdge(std::ostream& os,
    const Point& a,
    const Point& b) const
{
    os << a.getX() << " " << a.getY() << " " << a.getZ() << "\n";
    os << b.getX() << " " << b.getY() << " " << b.getZ() << "\n\n\n\n\n";
    os << "\n"; 
}

void Cylinder::writeForGnu(std::ostream& os) const
{
    double cx = center_.getX();
    double cy = center_.getY();
    double cz = center_.getZ();
    double topZ = cz + height_;

    double step = 2 * 3.1416 / segments_;

    for (int i = 0; i < segments_; ++i)
    {
        double angle1 = i * step;
        double angle2 = ((i + 1) % segments_) * step;

        Point b1(cx + radius_ * cos(angle1), cy + radius_ * sin(angle1), cz); // bottom circle points
        Point b2(cx + radius_ * cos(angle2), cy + radius_ * sin(angle2), cz);

        Point t1(cx + radius_ * cos(angle1), cy + radius_ * sin(angle1), topZ); // top circle points
        Point t2(cx + radius_ * cos(angle2), cy + radius_ * sin(angle2), topZ);

        printEdge(os, b1, b2);         // base circle

        printEdge(os, t1, t2);        // top circle

        printEdge(os, b1, t1);        // vertical edges
    }
}
