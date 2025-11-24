#include "Shape.h"

Shape::Shape(const std::string& name)
    : mName(name)
{
}

const std::string Shape::getName() const
{
    return mName;
}
