#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(std::make_unique<Ui::MainWindow>()), scene(this) {
  ui->setupUi(this);
  SetupScene();
  SetupFacade();
  SetupConnections();
}

MainWindow::~MainWindow() = default;

void MainWindow::SetupScene() {
  scene.setSceneRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT);
  scene.setBackgroundBrush(QBrush(QColor(BG_COLOR_R, BG_COLOR_G, BG_COLOR_B)));
  ui->graphicsView->setScene(&scene);
  ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::SetupFacade() {
  fileReader = std::make_shared<FileReader>();
  drawer = std::make_shared<QtSceneDrawer>(scene);
  facade = std::make_unique<Facade>(fileReader, drawer);
}

void MainWindow::SetupConnections() {
  connect(ui->browseButton, &QPushButton::clicked, this,
          &MainWindow::OnBrowseClicked);
  connect(ui->loadButton, &QPushButton::clicked, this,
          &MainWindow::OnLoadClicked);
  connect(ui->moveButton, &QPushButton::clicked, this,
          &MainWindow::OnMoveClicked);
  connect(ui->rotateButton, &QPushButton::clicked, this,
          &MainWindow::OnRotateClicked);
  connect(ui->scaleButton, &QPushButton::clicked, this,
          &MainWindow::OnScaleClicked);

  connect(ui->graphicsView, &InteractiveGraphicsView::mouseMoveRequested,
          this, &MainWindow::OnMouseMove);
  connect(ui->graphicsView, &InteractiveGraphicsView::mouseRotateRequested,
          this, &MainWindow::OnMouseRotate);
  connect(ui->graphicsView, &InteractiveGraphicsView::mouseScaleRequested,
          this, &MainWindow::OnMouseScale);
}

NormalizationParameters MainWindow::ReadNormalizationParams() const {
  return NormalizationParameters(
      ui->minNormEdit->text().toFloat(),
      ui->maxNormEdit->text().toFloat(),
      ui->dxStepEdit->text().toFloat(),
      ui->dyStepEdit->text().toFloat()
  );
}

void MainWindow::HandleFacadeResult(const FacadeOperationResult &result) {
  if (!result.IsSuccess())
    QMessageBox::critical(this, "Error", QString::fromStdString(result.GetErrorMessage()));
}

void MainWindow::OnBrowseClicked() {
  QString desktopPath =
      QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
  QString initialDir = desktopPath + "/figures";

  QString path = QFileDialog::getOpenFileName(
      this, "Select CSV File", initialDir, "CSV Files (*.csv);;All Files (*)");

  if (!path.isEmpty())
    ui->filePathEdit->setText(path);
}

void MainWindow::OnLoadClicked() {
  if (ui->filePathEdit->text().isEmpty()) {
    QMessageBox::warning(this, "Input Required",
                         "Please select a CSV file first.");
    return;
  }
  NormalizationParameters params = ReadNormalizationParams();
  FacadeOperationResult loadResult =
      facade->LoadScene(ui->filePathEdit->text().toStdString(), params);
  HandleFacadeResult(loadResult);
  if (!loadResult.IsSuccess())
    return;
  HandleFacadeResult(facade->DrawScene());
}

void MainWindow::OnMoveClicked() {
  float x = ui->moveXEdit->text().toFloat();
  float y = ui->moveYEdit->text().toFloat();
  float z = ui->moveZEdit->text().toFloat();
  FacadeOperationResult res = facade->MoveScene(x, y, z);
  HandleFacadeResult(res);
  if (!res.IsSuccess())
    return;
  HandleFacadeResult(facade->DrawScene());
}

void MainWindow::OnRotateClicked() {
  float x = ui->rotXEdit->text().toFloat() * DEG_TO_RAD;
  float y = ui->rotYEdit->text().toFloat() * DEG_TO_RAD;
  float z = ui->rotZEdit->text().toFloat() * DEG_TO_RAD;
  FacadeOperationResult res = facade->RotateScene(x, y, z);
  HandleFacadeResult(res);
  if (!res.IsSuccess())
    return;
  HandleFacadeResult(facade->DrawScene());
}

void MainWindow::OnScaleClicked() {
  float x = ui->scaleXEdit->text().toFloat();
  float y = ui->scaleYEdit->text().toFloat();
  float z = ui->scaleZEdit->text().toFloat();
  FacadeOperationResult res = facade->ScaleScene(x, y, z);
  HandleFacadeResult(res);
  if (!res.IsSuccess())
    return;
  HandleFacadeResult(facade->DrawScene());
}

void MainWindow::OnMouseMove(float dx, float dy) {
  FacadeOperationResult res = facade->MoveScene(dx, dy, 0.0f);
  HandleFacadeResult(res);
  if (!res.IsSuccess())
    return;
  HandleFacadeResult(facade->DrawScene());
}

void MainWindow::OnMouseRotate(float rx, float ry) {
  FacadeOperationResult res = facade->RotateScene(rx, ry, 0.0f);
  HandleFacadeResult(res);
  if (!res.IsSuccess())
    return;
  HandleFacadeResult(facade->DrawScene());
}

void MainWindow::OnMouseScale(float factor) {
  FacadeOperationResult res = facade->ScaleScene(factor, factor, factor);
  HandleFacadeResult(res);
  if (!res.IsSuccess())
    return;
  HandleFacadeResult(facade->DrawScene());
}
