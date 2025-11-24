#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include "Export.h"
#include "Shape.h"
#include "Point.h"

class GEOMETRY3D_API Cone : public Shape
{
private:
    Point baseCenter_;
    double radius_;
    double height_;
    int segments_; 

public:
    Cone(const std::string& name, const Point& baseCenter, const double& radius, const double& height, const int& segments = 36);

    std::vector<Point> getCoordinates() const override;

    void write(std::ostream& os) const override;
    void writeForGnu(std::ostream& os) const override;

private:
    void printEdge(std::ostream& os, const Point& a, const Point& b) const;
};
