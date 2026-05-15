#pragma once

#include "SceneObject.h"
#include "Vertex.h"
#include <vector>

class Figure : public SceneObject {
private:
    std::vector<Vertex> vertices;
    int rows = 0;
    int cols = 0;

public:
    Figure() = default;
    Figure(const Figure& other) = default;
    Figure& operator=(const Figure& other) = default;
    Figure(Figure&& other) noexcept = default;
    Figure& operator=(Figure&& other) noexcept = default;

    void ReserveVertices(size_t size);
    void AddVertex(const Vertex& vertex);
    void SetDimensions(int r, int c);
    
    std::vector<Vertex>& GetVertices();
    int GetRows() const;
    int GetCols() const;

    void Transform(const TransformMatrix& matrix) override;
};
