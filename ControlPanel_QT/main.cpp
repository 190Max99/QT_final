#include "dialog.h"
#include "Gyroscope3DWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    Gyroscope3DWidget *gyroWidget = new Gyroscope3DWidget();
    gyroWidget->show();
    w.show();

    return a.exec();
}
