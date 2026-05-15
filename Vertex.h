#pragma once

#include "SceneObject.h"
#include "Point3D.h"

class Vertex : public SceneObject {
private:
    Point3D position;

public:
    Vertex() = default;
    Vertex(const Point3D& point);
    Point3D GetPosition() const;
    void Transform(const TransformMatrix& matrix) override;
};
