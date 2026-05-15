#pragma once

#include <QGraphicsView>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPoint>

class InteractiveGraphicsView : public QGraphicsView {
    Q_OBJECT

private:
    static constexpr float MOVE_SENSITIVITY = 0.05f;
    static constexpr float ROTATE_SENSITIVITY = 0.005f;
    static constexpr float SCALE_STEP = 0.05f;
    static constexpr float SCALE_BASE = 1.0f;
    static constexpr int WHEEL_ANGLE_DIVISOR = 120;

    QPoint lastMousePos;
    bool isDragging = false;
    bool isRotating = false;

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;

signals:
    void mouseMoveRequested(float dx, float dy);
    void mouseRotateRequested(float rx, float ry);
    void mouseScaleRequested(float factor);

public:
    explicit InteractiveGraphicsView(QWidget* parent = nullptr);
};
