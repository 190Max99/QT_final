#ifndef CAR3DWIDGET_H
#define CAR3DWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QQuaternion>
#include <QTimer>

class Car3DWidget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT

public:
    Car3DWidget(QWidget *parent = nullptr);
    void setCarRotation(const QQuaternion &quat);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    QQuaternion rotation;
    QTimer updateTimer;
};

#endif // CAR3DWIDGET_H