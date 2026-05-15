#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <memory>
#include "Facade.h"
#include "QtSceneDrawer.h"
#include "FileReader.h"
#include "InteractiveGraphicsView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    std::unique_ptr<Ui::MainWindow> ui;

    static constexpr int SCENE_WIDTH = 900;
    static constexpr int SCENE_HEIGHT = 700;
    static constexpr int BG_COLOR_R = 5;
    static constexpr int BG_COLOR_G = 7;
    static constexpr int BG_COLOR_B = 15;
    static constexpr float PI = 3.14159f;
    static constexpr float HALF_CIRCLE_DEG = 180.0f;
    static constexpr float DEG_TO_RAD = PI / HALF_CIRCLE_DEG;

    std::shared_ptr<FileReader> fileReader;
    QGraphicsScene scene;
    std::shared_ptr<QtSceneDrawer> drawer;
    std::unique_ptr<Facade> facade;

    void SetupScene();
    void SetupFacade();
    void SetupConnections();
    void HandleFacadeResult(const FacadeOperationResult& result);
    NormalizationParameters ReadNormalizationParams() const;

    void OnBrowseClicked();
    void OnLoadClicked();
    void OnMoveClicked();
    void OnRotateClicked();
    void OnScaleClicked();

    void OnMouseMove(float dx, float dy);
    void OnMouseRotate(float rx, float ry);
    void OnMouseScale(float factor);

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
};
