#pragma once

#include "Figure.h"
#include <vector>

class Scene {
private:
    std::vector<Figure> figures;

public:
    void AddFigure(const Figure& figure);
    std::vector<Figure>& GetFigures();
    void TransformFigures(const TransformMatrix& matrix);
};
