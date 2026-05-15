#pragma once

#include "TransformMatrix.h"

class TransformMatrixBuilder {
public:
    static TransformMatrix CreateRotationMatrix(float x, float y, float z);
    static TransformMatrix CreateMoveMatrix(float x, float y, float z);
    static TransformMatrix CreateScaleMatrix(float x, float y, float z);
private:
    static constexpr float IDENTITY_DIAGONAL = 1.0f;

    static TransformMatrix CreateIdentityMatrix();
    static TransformMatrix CreateRotX(float angle);
    static TransformMatrix CreateRotY(float angle);
    static TransformMatrix CreateRotZ(float angle);
};
