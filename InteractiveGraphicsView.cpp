#include "InteractiveGraphicsView.h"


InteractiveGraphicsView::InteractiveGraphicsView(QWidget* parent)
    : QGraphicsView(parent) {
    setMouseTracking(false);
}

void InteractiveGraphicsView::mousePressEvent(QMouseEvent* event) {
    lastMousePos = event->pos();
    if (event->button() == Qt::LeftButton)
        isDragging = true;
    else if (event->button() == Qt::RightButton)
        isRotating = true;
    QGraphicsView::mousePressEvent(event);
}

void InteractiveGraphicsView::mouseMoveEvent(QMouseEvent* event) {
    if (isDragging) {
        int deltaX = event->pos().x() - lastMousePos.x();
        int deltaY = event->pos().y() - lastMousePos.y();
        lastMousePos = event->pos();
        emit mouseMoveRequested(deltaX * MOVE_SENSITIVITY,
                                deltaY * MOVE_SENSITIVITY);
        return;
    }
    if (isRotating) {
        int deltaX = event->pos().x() - lastMousePos.x();
        int deltaY = event->pos().y() - lastMousePos.y();
        lastMousePos = event->pos();
        emit mouseRotateRequested(deltaY * ROTATE_SENSITIVITY,
                                  deltaX * ROTATE_SENSITIVITY);
        return;
    }
    QGraphicsView::mouseMoveEvent(event);
}

void InteractiveGraphicsView::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton)
        isDragging = false;
    else if (event->button() == Qt::RightButton)
        isRotating = false;
    QGraphicsView::mouseReleaseEvent(event);
}

void InteractiveGraphicsView::wheelEvent(QWheelEvent* event) {
    int steps = event->angleDelta().y() / WHEEL_ANGLE_DIVISOR;
    float factor = SCALE_BASE + steps * SCALE_STEP;
    emit mouseScaleRequested(factor);
}
