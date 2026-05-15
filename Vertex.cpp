#include "Vertex.h"
#include "TransformMatrix.h"

Vertex::Vertex(const Point3D& point) {
  position = point;
}

Point3D Vertex::GetPosition() const {
    return position;
}

void Vertex::Transform(const TransformMatrix &matrix) {
  position = matrix * position;
}
