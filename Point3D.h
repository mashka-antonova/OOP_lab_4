#pragma once

class Point3D {
private:
  float x = 0.0f;
  float y = 0.0f;
  float z = 0.0f;
public:
  Point3D() = default;
  Point3D(float x, float y, float z) : x(x), y(y), z(z) {}
  
  float GetX() const { return x; }
  float GetY() const { return y; }
  float GetZ() const { return z; }
  
  void SetX(float value) { x = value; }
  void SetY(float value) { y = value; }
  void SetZ(float value) { z = value; }
};
