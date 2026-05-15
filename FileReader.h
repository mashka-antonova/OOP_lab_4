#pragma once

#include "BaseFileReader.h"
#include <vector>

class FileReader : public BaseFileReader {
public:
    Scene ReadScene(const std::string& path, const NormalizationParameters& params) override;

private:
    static constexpr float EPSILON = 0.00001f;
    static constexpr float FLOAT_ZERO = 0.0f;

    float FindMin(const std::vector<std::vector<float>>& data) const;
    float FindMax(const std::vector<std::vector<float>>& data) const;
    float NormalizeValue(float value, float minVal, float maxVal, float outMin, float outMax) const;
    std::vector<float> ParseLine(std::string line) const;
    Figure BuildFigure(const std::vector<std::vector<float>>& data, const NormalizationParameters& params) const;
    void EqualizeRowLengths(std::vector<std::vector<float>>& data) const;
};
