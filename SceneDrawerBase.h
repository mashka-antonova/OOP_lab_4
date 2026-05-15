#pragma once

#include "Scene.h"

class SceneDrawerBase {
public:
    virtual ~SceneDrawerBase() = default;
    virtual void DrawScene(Scene& scene) = 0;
};
