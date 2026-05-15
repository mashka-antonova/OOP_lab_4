#include "Figure.h"

void Figure::ReserveVertices(size_t size) {
    vertices.reserve(size);
}

void Figure::AddVertex(const Vertex& vertex) {
    vertices.push_back(vertex);
}

void Figure::SetDimensions(int r, int c) {
    rows = r;
    cols = c;
}

std::vector<Vertex>& Figure::GetVertices() {
    return vertices;
}

int Figure::GetRows() const {
    return rows;
}

int Figure::GetCols() const {
    return cols;
}

void Figure::Transform(const TransformMatrix& matrix) {
    for (size_t i = 0; i < vertices.size(); ++i)
        vertices[i].Transform(matrix);
}
