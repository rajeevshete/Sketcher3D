#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include "Export.h"
#include "Shape.h"
#include "Point.h"

class GEOMETRY3D_API Sphere : public Shape
{
private:
    Point center_;
    double radius_;
    int verticalSegments_;   
    int horizontalSegments_; 

public:
    Sphere(const std::string& name, const Point& center, const double& radius, const int& verticalSegments = 18, const int& horizontalSegments = 36);

    std::vector<Point> getCoordinates() const override;

    void write(std::ostream& os) const override;
    void writeForGnu(std::ostream& os) const override;

private:
    void printEdge(std::ostream& os, const Point& a, const Point& b) const;
};
