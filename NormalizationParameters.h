#pragma once

class NormalizationParameters {
private:
  float min = 0.0f;
  float max = 0.0f;
  float dxStep = 0.0f;
  float dyStep = 0.0f;
public:
  NormalizationParameters() = default;
  NormalizationParameters(float min, float max, float dxStep, float dyStep) 
      : min(min), max(max), dxStep(dxStep), dyStep(dyStep) {}

  float GetMin() const { return min; }
  float GetMax() const { return max; }
  float GetDxStep() const { return dxStep; }
  float GetDyStep() const { return dyStep; }

  void SetMin(float value) { min = value; }
  void SetMax(float value) { max = value; }
  void SetDxStep(float value) { dxStep = value; }
  void SetDyStep(float value) { dyStep = value; }
};
