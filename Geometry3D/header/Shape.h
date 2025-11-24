#pragma once
#include "pch.h"
#include <string>
#include <vector>
#include "Export.h"
#include "Point.h"

class GEOMETRY3D_API Shape
{
protected:
    std::string name_;

public:
    Shape(const std::string& name);
    virtual ~Shape() = default;

    std::string getName() const { return name_; }

    virtual std::vector<Point> getCoordinates() const = 0;

    virtual void write(std::ostream& os) const = 0;

    virtual void writeForGnu(std::ostream& os) const = 0;
};
