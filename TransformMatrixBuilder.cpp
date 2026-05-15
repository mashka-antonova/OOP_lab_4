#include "TransformMatrixBuilder.h"
#include <cmath>


TransformMatrix TransformMatrixBuilder::CreateIdentityMatrix() {
    TransformMatrix m;
    m.SetValue(0, 0, IDENTITY_DIAGONAL);
    m.SetValue(1, 1, IDENTITY_DIAGONAL);
    m.SetValue(2, 2, IDENTITY_DIAGONAL);
    m.SetValue(3, 3, IDENTITY_DIAGONAL);
    return m;
}

TransformMatrix TransformMatrixBuilder::CreateRotX(float angle) {
    TransformMatrix m = CreateIdentityMatrix();
    float c = std::cos(angle);
    float s = std::sin(angle);
    m.SetValue(1, 1, c);
    m.SetValue(1, 2, -s);
    m.SetValue(2, 1, s);
    m.SetValue(2, 2, c);
    return m;
}

TransformMatrix TransformMatrixBuilder::CreateRotY(float angle) {
    TransformMatrix m = CreateIdentityMatrix();
    float c = std::cos(angle);
    float s = std::sin(angle);
    m.SetValue(0, 0, c);
    m.SetValue(0, 2, s);
    m.SetValue(2, 0, -s);
    m.SetValue(2, 2, c);
    return m;
}

TransformMatrix TransformMatrixBuilder::CreateRotZ(float angle) {
    TransformMatrix m = CreateIdentityMatrix();
    float c = std::cos(angle);
    float s = std::sin(angle);
    m.SetValue(0, 0, c);
    m.SetValue(0, 1, -s);
    m.SetValue(1, 0, s);
    m.SetValue(1, 1, c);
    return m;
}

TransformMatrix TransformMatrixBuilder::CreateRotationMatrix(float x, float y, float z) {
    TransformMatrix mx = CreateRotX(x);
    TransformMatrix my = CreateRotY(y);
    TransformMatrix mz = CreateRotZ(z);
    return mx * my * mz;
}

TransformMatrix TransformMatrixBuilder::CreateMoveMatrix(float x, float y, float z) {
    TransformMatrix m = CreateIdentityMatrix();
    m.SetValue(0, 3, x);
    m.SetValue(1, 3, y);
    m.SetValue(2, 3, z);
    return m;
}

TransformMatrix TransformMatrixBuilder::CreateScaleMatrix(float x, float y, float z) {
    TransformMatrix m = CreateIdentityMatrix();
    m.SetValue(0, 0, x);
    m.SetValue(1, 1, y);
    m.SetValue(2, 2, z);
    return m;
}
