#include "Sphere.h"
#include <cmath>

const double PI = 3.1416;

Sphere::Sphere(const std::string& name, const Point& center, const double& radius, const int& verticalSegments, const int& horizontalSegments)
    : Shape(name), center_(center), radius_(radius), verticalSegments_(verticalSegments), horizontalSegments_(horizontalSegments) {}

std::vector<Point> Sphere::getCoordinates() const
{
    return {};
}

void Sphere::write(std::ostream& os) const
{
    os << "Sphere: radius=" << radius_ << "\n";
}

void Sphere::printEdge(std::ostream& os, const Point& a, const Point& b) const
{
    os << a.getX() << " " << a.getY() << " " << a.getZ() << "\n";
    os << b.getX() << " " << b.getY() << " " << b.getZ() << "\n";
    os << "\n";  // blank line for GNUplot
}

void Sphere::writeForGnu(std::ostream& os) const
{
    double cx = center_.getX();
    double cy = center_.getY();
    double cz = center_.getZ();

    // remaining
}
