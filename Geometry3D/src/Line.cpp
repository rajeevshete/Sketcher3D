#include "Line.h"

Line::Line(const std::string& name, const Point& start, const Point& end)
    : Shape(name), start_(start), end_(end)
{
}

std::vector<Point> Line::getCoordinates() const
{
    return { start_, end_ };
}

void Line::write(std::ostream& os) const
{
    os << "Line: ";
    start_.write(os);
    os << "  ";
    end_.write(os);
    os << "\n";
}

void Line::printEdge(std::ostream& os,
    const std::vector<Point>& p,
    int a,
    int b) const
{
    os << p[a].getX() << " " << p[a].getY() << " " << p[a].getZ() << "\n";
    os << p[b].getX() << " " << p[b].getY() << " " << p[b].getZ() << "\n";
    os << "\n";  
}

void Line::writeForGnu(std::ostream& os) const
{
    auto pts = getCoordinates();
    printEdge(os, pts, 0, 1);
}
