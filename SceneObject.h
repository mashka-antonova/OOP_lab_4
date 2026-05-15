#pragma once

class TransformMatrix;

class SceneObject {
public:
    virtual ~SceneObject() = default;
    virtual void Transform(const TransformMatrix& matrix) = 0;
};
