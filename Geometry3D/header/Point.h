#pragma once
#include "pch.h"
#include <iostream>
#include "Export.h"

class GEOMETRY3D_API Point
{
private:
    double x_, y_, z_;

public:

    Point(const double& x, const double& y, const double& z);

    double getX() const { return x_; }
    double getY() const { return y_; }
    double getZ() const { return z_; }

    void write(std::ostream& os) const;
};
