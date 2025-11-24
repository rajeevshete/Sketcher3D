#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include "Export.h"
#include "Shape.h"
#include "Point.h"

class GEOMETRY3D_API Cuboid : public Shape
{
private:
    Point origin_;
    double length_;
    double breadth_;
    double height_;

public:
    // Cuboid constructor
    Cuboid(const std::string& name, const Point& origin, const double& length, const double& breadth, const double& height);

    // Cube constructor
    Cuboid(const std::string& name,
        const Point& origin,
        const double& side);  

    std::vector<Point> getCoordinates() const override;
    void write(std::ostream& os) const override;
    void writeForGnu(std::ostream& os) const override;

private:
    void printEdge(std::ostream& os,
        const std::vector<Point>& p,
        int a,
        int b) const;
};
