#include "TransformMatrix.h"


TransformMatrix::TransformMatrix() {
  for (int i = 0; i < MATRIX_SIZE; ++i)
    for (int j = 0; j < MATRIX_SIZE; ++j)
      matr[i][j] = EMPTY_VALUE;
}

void TransformMatrix::SetValue(int row, int col, float value) {
  matr[row][col] = value;
}

float TransformMatrix::GetValue(int row, int col) const {
  return matr[row][col];
}

TransformMatrix TransformMatrix::operator*(const TransformMatrix &other) const {
  TransformMatrix result;
  for (int i = 0; i < MATRIX_SIZE; ++i) {
    for (int j = 0; j < MATRIX_SIZE; ++j) {
      float sum = EMPTY_VALUE;
      for (int k = 0; k < MATRIX_SIZE; ++k)
        sum += matr[i][k] * other.GetValue(k, j);
      result.SetValue(i, j, sum);
    }
  }
  return result;
}

Point3D TransformMatrix::operator*(const Point3D &point) const {
  return Point3D(
      matr[0][0] * point.GetX() + matr[0][1] * point.GetY() + matr[0][2] * point.GetZ() + matr[0][3] * HOMOGENEOUS_COORD,
      matr[1][0] * point.GetX() + matr[1][1] * point.GetY() + matr[1][2] * point.GetZ() + matr[1][3] * HOMOGENEOUS_COORD,
      matr[2][0] * point.GetX() + matr[2][1] * point.GetY() + matr[2][2] * point.GetZ() + matr[2][3] * HOMOGENEOUS_COORD);
}

