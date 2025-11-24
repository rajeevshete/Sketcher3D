#pragma once
#include <vector>
#include <memory>
#include <string>

#include "Shape.h"

class ShapeCreator {
private:

    std::vector<std::unique_ptr<Shape>> shapes_;

public:
    ShapeCreator() = default;

    void read();

    void write(size_t index) const;

    void listShapes() const;

    size_t getShapeCount() const { return shapes_.size(); }
};
