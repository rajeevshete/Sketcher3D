#pragma once
#include "pch.h"
#include <string>
#include <vector>
#include "Export.h"
#include "Point.h"

class GEOMETRY3D_API Shape
{
private:
    std::string mName;

public:
    Shape(const std::string& name);
    virtual ~Shape() = default;

    const std::string getName() const;

    virtual const std::vector<Point> getCoordinates() const = 0;

    virtual void save(std::ostream& os) const = 0;

    virtual void saveForGnu(std::ostream& os) const = 0;
};
