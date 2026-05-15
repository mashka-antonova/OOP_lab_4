#include "QtSceneDrawer.h"
#include <QPen>


QtSceneDrawer::QtSceneDrawer(QGraphicsScene &scene) : graphicsScene(scene) {
  pen.setWidthF(PEN_WIDTH);
}

void QtSceneDrawer::DrawScene(Scene &scene) {
  graphicsScene.clear();
  std::vector<Figure> &figures = scene.GetFigures();
  for (size_t i = 0; i < figures.size(); ++i)
    DrawFigure(figures[i]);
  graphicsScene.update();
}

void QtSceneDrawer::DrawFigure(Figure &figure) {
  const std::vector<Vertex> &vertices = figure.GetVertices();
  int rows = figure.GetRows();
  int cols = figure.GetCols();

  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols - 1; ++j)
      DrawEdge(i * cols + j, i * cols + j + 1, vertices);

  for (int i = 0; i < rows - 1; ++i)
    for (int j = 0; j < cols; ++j)
      DrawEdge(i * cols + j, (i + 1) * cols + j, vertices);
}

void QtSceneDrawer::UpdateNeonPen(float heightFraction) {
  int r = static_cast<int>(heightFraction * NEON_R_HIGH + (1.0f - heightFraction) * NEON_R_LOW);
  int g = static_cast<int>(heightFraction * NEON_G_HIGH + (1.0f - heightFraction) * NEON_G_LOW);
  int b = static_cast<int>(heightFraction * NEON_B_HIGH + (1.0f - heightFraction) * NEON_B_LOW);

  pen.setColor(QColor(r, g, b, PEN_ALPHA));
}

void QtSceneDrawer::DrawEdge(int beginIndex, int endIndex, const std::vector<Vertex> &vertices) {
  Point3D p1 = vertices[beginIndex].GetPosition();
  Point3D p2 = vertices[endIndex].GetPosition();

  float x1 = (p1.GetX() - p1.GetY()) * COS_30;
  float y1 = -p1.GetZ() + (p1.GetX() + p1.GetY()) * SIN_30;
  float x2 = (p2.GetX() - p2.GetY()) * COS_30;
  float y2 = -p2.GetZ() + (p2.GetX() + p2.GetY()) * SIN_30;

  float offsetX = graphicsScene.width() * HALF_FACTOR;
  float offsetY = graphicsScene.height() * HALF_FACTOR;

  float avgZ = (p1.GetZ() + p2.GetZ()) * HALF_FACTOR;
  float heightFraction = avgZ;
  if (heightFraction < 0.0f)
    heightFraction = 0.0f;
  if (heightFraction > 1.0f)
    heightFraction = 1.0f;

  UpdateNeonPen(heightFraction);

  graphicsScene.addLine(
      x1 * SCALE_FACTOR + offsetX, y1 * SCALE_FACTOR + offsetY,
      x2 * SCALE_FACTOR + offsetX, y2 * SCALE_FACTOR + offsetY, pen);
}
