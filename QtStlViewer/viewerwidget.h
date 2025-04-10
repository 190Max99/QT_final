#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QVector3D>
#include <vector>

class ViewerWidget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT
public:
    ViewerWidget(QWidget *parent = nullptr);
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
private:
    std::vector<QVector3D> triangles;
};