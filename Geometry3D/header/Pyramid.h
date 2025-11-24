#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include "Export.h"
#include "Shape.h"
#include "Point.h"

class GEOMETRY3D_API Pyramid : public Shape
{
private:
    Point baseOrigin_;  // bottom-left corner of base
    double length_;
    double breadth_;
    double height_;

public:
    Pyramid(const std::string& name, const Point& baseOrigin, const double& length, const double& breadth, const double& height);

    std::vector<Point> getCoordinates() const override;

    void write(std::ostream& os) const override;
    void writeForGnu(std::ostream& os) const override;

private:
    void printEdge(std::ostream& os, const Point& a, const Point& b) const;
};
