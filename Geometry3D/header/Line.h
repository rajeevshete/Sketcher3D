#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include "Export.h"
#include "Shape.h"
#include "Point.h"

class GEOMETRY3D_API Line : public Shape
{
private:
    Point start_;
    Point end_;

public:
    Line(const std::string& name, const Point& start, const Point& end);

    std::vector<Point> getCoordinates() const override;

    void write(std::ostream& os) const override;

    void writeForGnu(std::ostream& os) const override;

private:
    void printEdge(std::ostream& os, const std::vector<Point>& p, int a, int b) const;
};
