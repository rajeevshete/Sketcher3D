#include "Point.h"

Point::Point(const double& x, const double& y, const double& z)
    : x_(x), y_(y), z_(z)
{
}

void Point::write(std::ostream& os) const
{
    os << x_ << " " << y_ << " " << z_;
}
