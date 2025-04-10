#include "viewerwidget.h"
#include "stldata.h"
#include <QMatrix4x4>
#include <QTimer>
#include <QtMath>

ViewerWidget::ViewerWidget(QWidget *parent) : QOpenGLWidget(parent) {
    triangles = getStlTriangles();
}

void ViewerWidget::initializeGL() {
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
}

void ViewerWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void ViewerWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 proj, view, model;
    proj.perspective(45.0f, float(width())/height(), 0.1f, 100.0f);
    view.translate(0, 0, -10);
    model.rotate(30, 1, 0, 0);
    model.rotate(45, 0, 1, 0);

    QMatrix4x4 mvp = proj * view * model;
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(mvp.constData());

    glBegin(GL_TRIANGLES);
    glColor3f(0.7f, 0.8f, 1.0f);
    for (const auto& v : triangles)
        glVertex3f(v.x(), v.y(), v.z());
    glEnd();
}