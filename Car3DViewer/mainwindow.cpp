#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "car3dwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Car3DWidget *carWidget = new Car3DWidget(this);
    setCentralWidget(carWidget);

    // 示例四元数：绕 Y 轴旋转 45 度
    QQuaternion quat = QQuaternion::fromAxisAndAngle(0, 1, 0, 45);
    carWidget->setCarRotation(quat);
}

MainWindow::~MainWindow()
{
    delete ui;
}