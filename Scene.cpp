#include "Scene.h"

void Scene::AddFigure(const Figure& figure) {
    figures.push_back(figure);
}

std::vector<Figure>& Scene::GetFigures() {
    return figures;
}

void Scene::TransformFigures(const TransformMatrix& matrix) {
    for (size_t i = 0; i < figures.size(); ++i)
        figures[i].Transform(matrix);
}
