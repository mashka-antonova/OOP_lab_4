#pragma once

#include "FacadeOperationResult.h"
#include "BaseFileReader.h"
#include "SceneDrawerBase.h"
#include "Scene.h"
#include "NormalizationParameters.h"
#include <string>
#include <memory>

class Facade {
private:
    std::shared_ptr<BaseFileReader> fileReader;
    std::shared_ptr<SceneDrawerBase> sceneDrawer;
    Scene scene;

public:
    Facade(std::shared_ptr<BaseFileReader> reader, std::shared_ptr<SceneDrawerBase> drawer);
    
    FacadeOperationResult DrawScene();
    FacadeOperationResult LoadScene(const std::string& path, const NormalizationParameters& params);
    FacadeOperationResult MoveScene(float x, float y, float z);
    FacadeOperationResult RotateScene(float x, float y, float z);
    FacadeOperationResult ScaleScene(float x, float y, float z);
};
