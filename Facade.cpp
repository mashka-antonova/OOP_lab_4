#include "Facade.h"
#include "TransformMatrixBuilder.h"
#include <exception>

Facade::Facade(std::shared_ptr<BaseFileReader> reader, std::shared_ptr<SceneDrawerBase> drawer)
    : fileReader(reader), sceneDrawer(drawer) {}

FacadeOperationResult Facade::DrawScene() {
    FacadeOperationResult result(true, "");
    if (!sceneDrawer)
        result = FacadeOperationResult(false, "Scene drawer is not set");
    else
        sceneDrawer->DrawScene(scene);
    return result;
}

FacadeOperationResult Facade::LoadScene(const std::string& path, const NormalizationParameters& params) {
    FacadeOperationResult result(true, "");
    if (!fileReader)
        result = FacadeOperationResult(false, "File reader is not set");
    else {
        try {
            scene = fileReader->ReadScene(path, params);
        } catch (const std::exception& e) {
            result = FacadeOperationResult(false, e.what());
        }
    }
    return result;
}

FacadeOperationResult Facade::MoveScene(float x, float y, float z) {
    TransformMatrix m = TransformMatrixBuilder::CreateMoveMatrix(x, y, z);
    scene.TransformFigures(m);
    return FacadeOperationResult(true, "");
}

FacadeOperationResult Facade::RotateScene(float x, float y, float z) {
    TransformMatrix m = TransformMatrixBuilder::CreateRotationMatrix(x, y, z);
    scene.TransformFigures(m);
    return FacadeOperationResult(true, "");
}

FacadeOperationResult Facade::ScaleScene(float x, float y, float z) {
    TransformMatrix m = TransformMatrixBuilder::CreateScaleMatrix(x, y, z);
    scene.TransformFigures(m);
    return FacadeOperationResult(true, "");
}
