#pragma once

#include <string>
#include "NormalizationParameters.h"
#include "Scene.h"

class BaseFileReader {
public:
    virtual ~BaseFileReader() = default;
    virtual Scene ReadScene(const std::string& path, const NormalizationParameters& params) = 0;
};
