#include "car3dwidget.h"
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <cmath>

Car3DWidget::Car3DWidget(QWidget *parent) : QOpenGLWidget(parent) {
    rotation = QQuaternion(); // 初始单位四元数

    // 每秒60帧刷新
    connect(&updateTimer, &QTimer::timeout, this, QOverload<>::of(&Car3DWidget::update));
    updateTimer.start(16);
}

void Car3DWidget::setCarRotation(const QQuaternion &quat) {
    rotation = quat;
}

void Car3DWidget::initializeGL() {
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
}

void Car3DWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void Car3DWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 projection;
    projection.perspective(45.0f, float(width()) / height(), 0.1f, 100.0f);

    QMatrix4x4 view;
    view.translate(0, 0, -10); // 拉远相机

    QMatrix4x4 model;
    model.rotate(rotation);

    QMatrix4x4 mvp = projection * view * model;

    // 简单绘制一个立方体
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(mvp.constData());

    glBegin(GL_QUADS);
    // Front face (z+)
    glColor3f(1, 0, 0);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);

    // Back face (z-)
    glColor3f(0, 1, 0);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);

    // Left face
    glColor3f(0, 0, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);

    // Right face
    glColor3f(1, 1, 0);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);

    // Top face
    glColor3f(1, 0, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);

    // Bottom face
    glColor3f(0, 1, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);
    glEnd();
}
