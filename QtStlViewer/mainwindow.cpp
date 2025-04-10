#include "mainwindow.h"
#include "viewerwidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    auto *w = new ViewerWidget(this);
    setCentralWidget(w);
    resize(800, 600);
}