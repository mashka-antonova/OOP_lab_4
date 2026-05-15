#include <QApplication>
#include <QFile>
#include <QStyleFactory>
#include "MainWindow.h"

static QString LoadStyleSheet(const QString& path) {
    QFile file(path);
    QString result;
    if (file.open(QFile::ReadOnly)) {
        result = QString::fromUtf8(file.readAll());
        file.close();
    }
    return result;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setApplicationName("3D Surface Visualizer");
    app.setOrganizationName("Lab4_OOP");

    app.setStyle(QStyleFactory::create("Fusion"));

    QString styleSheet = LoadStyleSheet(":/style.qss");
    if (!styleSheet.isEmpty())
        app.setStyleSheet(styleSheet);

    MainWindow window;
    window.resize(1280, 800);
    window.show();
    return app.exec();
}
