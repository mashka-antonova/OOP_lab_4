#pragma once

#include "SceneDrawerBase.h"
#include "Figure.h"
#include <QGraphicsScene>
#include <QPen>

class QtSceneDrawer : public SceneDrawerBase {
private:
    QGraphicsScene& graphicsScene;

    static constexpr float PEN_WIDTH = 1.2f;
    static constexpr int PEN_ALPHA = 220;
    static constexpr int NEON_R_HIGH = 0;
    static constexpr int NEON_R_LOW = 0;
    static constexpr int NEON_G_HIGH = 229;
    static constexpr int NEON_G_LOW = 80;
    static constexpr int NEON_B_HIGH = 255;
    static constexpr int NEON_B_LOW = 255;
    static constexpr float COS_30 = 0.866025f;
    static constexpr float SIN_30 = 0.5f;
    static constexpr float SCALE_FACTOR = 30.0f;
    static constexpr float HALF_FACTOR = 0.5f;

    QPen pen;

    void DrawFigure(Figure& figure);
    void DrawEdge(int beginIndex, int endIndex, const std::vector<Vertex>& vertices);
    void UpdateNeonPen(float heightFraction);

public:
    explicit QtSceneDrawer(QGraphicsScene& scene);
    void DrawScene(Scene& scene) override;
};
