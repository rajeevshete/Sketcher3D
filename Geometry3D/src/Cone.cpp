#include "Cone.h"
#include <cmath>

const double PI = 3.1416;

Cone::Cone(const std::string& name, const Point& baseCenter, const double& radius, const double& height, const int& segments)
    : Shape(name), baseCenter_(baseCenter), radius_(radius), height_(height), segments_(segments) {}

std::vector<Point> Cone::getCoordinates() const
{
    return {};
}

void Cone::write(std::ostream& os) const
{
    os << "Cone: radius = " << radius_ << ", height = " << height_ << "\n";
}

void Cone::printEdge(std::ostream& os, const Point& a, const Point& b) const
{
    os << a.getX() << " " << a.getY() << " " << a.getZ() << "\n";
    os << b.getX() << " " << b.getY() << " " << b.getZ() << "\n";
    os << "\n"; 
}

void Cone::writeForGnu(std::ostream& os) const
{
    double cx = baseCenter_.getX();
    double cy = baseCenter_.getY();
    double cz = baseCenter_.getZ();
    double apexZ = cz + height_;

    Point apex(cx, cy, apexZ);

    double step = 2 * PI / segments_;

    for (int i = 0; i < segments_; ++i)
    {
        double angle1 = i * step;
        double angle2 = ((i + 1) % segments_) * step;

        // Points on the base circle
        Point p1(cx + radius_ * cos(angle1), cy + radius_ * sin(angle1), cz);
        Point p2(cx + radius_ * cos(angle2), cy + radius_ * sin(angle2), cz);

        // Base edge
        printEdge(os, p1, p2);

        // Side edge (from base point to apex)
        printEdge(os, p1, apex);
    }
}
