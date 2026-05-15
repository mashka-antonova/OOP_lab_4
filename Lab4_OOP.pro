QT += core gui widgets

CONFIG += c++17

TARGET = Lab4_OOP
TEMPLATE = app

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    QtSceneDrawer.cpp \
    Facade.cpp \
    FacadeOperationResult.cpp \
    FileReader.cpp \
    Vertex.cpp \
    Figure.cpp \
    Scene.cpp \
    TransformMatrix.cpp \
    TransformMatrixBuilder.cpp \
    InteractiveGraphicsView.cpp

HEADERS += \
    MainWindow.h \
    QtSceneDrawer.h \
    Facade.h \
    FacadeOperationResult.h \
    FileReader.h \
    BaseFileReader.h \
    NormalizationParameters.h \
    Point3D.h \
    Vertex.h \
    Figure.h \
    Scene.h \
    SceneObject.h \
    SceneDrawerBase.h \
    TransformMatrix.h \
    TransformMatrixBuilder.h \
    InteractiveGraphicsView.h

FORMS += \
    MainWindow.ui

RESOURCES += \
    resources.qrc

