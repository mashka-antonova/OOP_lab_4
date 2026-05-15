#pragma once

#include "Point3D.h"

class TransformMatrix {
private:
    static constexpr int MATRIX_SIZE = 4;
    static constexpr float EMPTY_VALUE = 0.0f;
    static constexpr float HOMOGENEOUS_COORD = 1.0f;
    float matr[MATRIX_SIZE][MATRIX_SIZE];

public:
    TransformMatrix();
    
    void SetValue(int row, int col, float value);
    float GetValue(int row, int col) const;

    TransformMatrix operator*(const TransformMatrix& other) const;
    Point3D operator*(const Point3D& point) const;
};
