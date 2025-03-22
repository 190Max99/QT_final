/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabLED;
    QGroupBox *groupBox_fpga_led;
    QCheckBox *checkBox_LED1;
    QCheckBox *checkBox_LED0;
    QCheckBox *checkBox_LED2;
    QCheckBox *checkBox_LED3;
    QCheckBox *checkBox_LED4;
    QCheckBox *checkBox_LED5;
    QCheckBox *checkBox_LED6;
    QCheckBox *checkBox_LED7;
    QGroupBox *groupBox_hps_led;
    QCheckBox *checkBox_HPS_LED0;
    QPushButton *pushButton_LightAllLed;
    QPushButton *pushButton_UnlightAllLed;
    QWidget *tabButton;
    QGroupBox *groupBox_3;
    QLabel *label_hps_key0;
    QGroupBox *groupBox_4;
    QLabel *label_key0;
    QLabel *label_key1;
    QLabel *label_sw0;
    QLabel *label_sw1;
    QLabel *label_sw2;
    QLabel *label_sw3;
    QWidget *tabGsensor;
    QLabel *label_Z;
    QLabel *label_X;
    QLabel *label_Y;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::ApplicationModal);
        Dialog->resize(462, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setCursor(QCursor(Qt::ArrowCursor));
        Dialog->setContextMenuPolicy(Qt::DefaultContextMenu);
        Dialog->setSizeGripEnabled(false);
        Dialog->setModal(false);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setCursor(QCursor(Qt::ArrowCursor));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(32, 32));
        tabWidget->setMovable(false);
        tabLED = new QWidget();
        tabLED->setObjectName(QStringLiteral("tabLED"));
        tabLED->setCursor(QCursor(Qt::ArrowCursor));
        tabLED->setAutoFillBackground(false);
        groupBox_fpga_led = new QGroupBox(tabLED);
        groupBox_fpga_led->setObjectName(QStringLiteral("groupBox_fpga_led"));
        groupBox_fpga_led->setGeometry(QRect(30, 20, 221, 201));
        checkBox_LED1 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED1->setObjectName(QStringLiteral("checkBox_LED1"));
        checkBox_LED1->setGeometry(QRect(10, 70, 95, 35));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setKerning(false);
        checkBox_LED1->setFont(font);
        checkBox_LED1->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/Myresource/GLED.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox_LED1->setIcon(icon);
        checkBox_LED1->setTristate(false);
        checkBox_LED0 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED0->setObjectName(QStringLiteral("checkBox_LED0"));
        checkBox_LED0->setGeometry(QRect(10, 30, 95, 35));
        checkBox_LED0->setFont(font);
        checkBox_LED0->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED0->setIcon(icon);
        checkBox_LED0->setTristate(false);
        checkBox_LED2 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED2->setObjectName(QStringLiteral("checkBox_LED2"));
        checkBox_LED2->setGeometry(QRect(10, 110, 95, 35));
        checkBox_LED2->setFont(font);
        checkBox_LED2->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED2->setIcon(icon);
        checkBox_LED2->setTristate(false);
        checkBox_LED3 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED3->setObjectName(QStringLiteral("checkBox_LED3"));
        checkBox_LED3->setGeometry(QRect(10, 150, 95, 35));
        checkBox_LED3->setFont(font);
        checkBox_LED3->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED3->setIcon(icon);
        checkBox_LED3->setTristate(false);
        checkBox_LED4 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED4->setObjectName(QStringLiteral("checkBox_LED4"));
        checkBox_LED4->setGeometry(QRect(120, 30, 95, 35));
        checkBox_LED4->setFont(font);
        checkBox_LED4->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED4->setIcon(icon);
        checkBox_LED4->setTristate(false);
        checkBox_LED5 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED5->setObjectName(QStringLiteral("checkBox_LED5"));
        checkBox_LED5->setGeometry(QRect(120, 70, 95, 35));
        checkBox_LED5->setFont(font);
        checkBox_LED5->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED5->setIcon(icon);
        checkBox_LED5->setTristate(false);
        checkBox_LED6 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED6->setObjectName(QStringLiteral("checkBox_LED6"));
        checkBox_LED6->setGeometry(QRect(120, 110, 95, 35));
        checkBox_LED6->setFont(font);
        checkBox_LED6->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED6->setIcon(icon);
        checkBox_LED6->setTristate(false);
        checkBox_LED7 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED7->setObjectName(QStringLiteral("checkBox_LED7"));
        checkBox_LED7->setGeometry(QRect(120, 150, 95, 35));
        checkBox_LED7->setFont(font);
        checkBox_LED7->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED7->setIcon(icon);
        checkBox_LED7->setTristate(false);
        groupBox_hps_led = new QGroupBox(tabLED);
        groupBox_hps_led->setObjectName(QStringLiteral("groupBox_hps_led"));
        groupBox_hps_led->setGeometry(QRect(280, 20, 121, 81));
        checkBox_HPS_LED0 = new QCheckBox(groupBox_hps_led);
        checkBox_HPS_LED0->setObjectName(QStringLiteral("checkBox_HPS_LED0"));
        checkBox_HPS_LED0->setGeometry(QRect(10, 30, 95, 35));
        checkBox_HPS_LED0->setFont(font);
        checkBox_HPS_LED0->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_HPS_LED0->setIcon(icon);
        checkBox_HPS_LED0->setTristate(false);
        pushButton_LightAllLed = new QPushButton(tabLED);
        pushButton_LightAllLed->setObjectName(QStringLiteral("pushButton_LightAllLed"));
        pushButton_LightAllLed->setGeometry(QRect(280, 140, 80, 23));
        pushButton_LightAllLed->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_UnlightAllLed = new QPushButton(tabLED);
        pushButton_UnlightAllLed->setObjectName(QStringLiteral("pushButton_UnlightAllLed"));
        pushButton_UnlightAllLed->setGeometry(QRect(280, 170, 80, 23));
        pushButton_UnlightAllLed->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget->addTab(tabLED, icon, QString());
        tabButton = new QWidget();
        tabButton->setObjectName(QStringLiteral("tabButton"));
        tabButton->setCursor(QCursor(Qt::ArrowCursor));
        groupBox_3 = new QGroupBox(tabButton);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(290, 20, 101, 111));
        label_hps_key0 = new QLabel(groupBox_3);
        label_hps_key0->setObjectName(QStringLiteral("label_hps_key0"));
        label_hps_key0->setGeometry(QRect(30, 40, 44, 44));
        label_hps_key0->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/BUTTON_DOWN.bmp")));
        groupBox_4 = new QGroupBox(tabButton);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 20, 231, 191));
        label_key0 = new QLabel(groupBox_4);
        label_key0->setObjectName(QStringLiteral("label_key0"));
        label_key0->setGeometry(QRect(100, 40, 44, 44));
        label_key0->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/BUTTON_UP.bmp")));
        label_key1 = new QLabel(groupBox_4);
        label_key1->setObjectName(QStringLiteral("label_key1"));
        label_key1->setGeometry(QRect(30, 40, 44, 44));
        label_key1->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/BUTTON_UP.bmp")));
        label_sw0 = new QLabel(groupBox_4);
        label_sw0->setObjectName(QStringLiteral("label_sw0"));
        label_sw0->setGeometry(QRect(180, 110, 19, 63));
        label_sw0->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/SW_down.bmp")));
        label_sw1 = new QLabel(groupBox_4);
        label_sw1->setObjectName(QStringLiteral("label_sw1"));
        label_sw1->setGeometry(QRect(130, 110, 19, 63));
        label_sw1->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/SW_down.bmp")));
        label_sw2 = new QLabel(groupBox_4);
        label_sw2->setObjectName(QStringLiteral("label_sw2"));
        label_sw2->setGeometry(QRect(80, 110, 19, 63));
        label_sw2->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/SW_down.bmp")));
        label_sw3 = new QLabel(groupBox_4);
        label_sw3->setObjectName(QStringLiteral("label_sw3"));
        label_sw3->setGeometry(QRect(30, 110, 19, 63));
        label_sw3->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/SW_down.bmp")));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/Myresource/BUTTON_UP.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabButton, icon1, QString());
        tabGsensor = new QWidget();
        tabGsensor->setObjectName(QStringLiteral("tabGsensor"));
        tabGsensor->setCursor(QCursor(Qt::ArrowCursor));
        label_Z = new QLabel(tabGsensor);
        label_Z->setObjectName(QStringLiteral("label_Z"));
        label_Z->setGeometry(QRect(20, 160, 87, 41));
        QFont font1;
        font1.setPointSize(11);
        label_Z->setFont(font1);
        label_X = new QLabel(tabGsensor);
        label_X->setObjectName(QStringLiteral("label_X"));
        label_X->setGeometry(QRect(20, 60, 87, 41));
        label_X->setFont(font1);
        label_Y = new QLabel(tabGsensor);
        label_Y->setObjectName(QStringLiteral("label_Y"));
        label_Y->setGeometry(QRect(20, 110, 87, 41));
        label_Y->setFont(font1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/Myresource/tab/G-Sensor.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabGsensor, icon2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(Dialog);
        QObject::connect(checkBox_HPS_LED0, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED0, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED1, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED2, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED3, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED4, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED5, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED6, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED7, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Control Panel", 0));
        groupBox_fpga_led->setTitle(QApplication::translate("Dialog", "FPGA LED", 0));
        checkBox_LED1->setText(QApplication::translate("Dialog", "LED1", 0));
        checkBox_LED0->setText(QApplication::translate("Dialog", "LED0", 0));
        checkBox_LED2->setText(QApplication::translate("Dialog", "LED2", 0));
        checkBox_LED3->setText(QApplication::translate("Dialog", "LED3", 0));
        checkBox_LED4->setText(QApplication::translate("Dialog", "LED4", 0));
        checkBox_LED5->setText(QApplication::translate("Dialog", "LED5", 0));
        checkBox_LED6->setText(QApplication::translate("Dialog", "LED6", 0));
        checkBox_LED7->setText(QApplication::translate("Dialog", "LED7", 0));
        groupBox_hps_led->setTitle(QApplication::translate("Dialog", "HPS LED", 0));
        checkBox_HPS_LED0->setText(QApplication::translate("Dialog", "LED0", 0));
        pushButton_LightAllLed->setText(QApplication::translate("Dialog", "Light All", 0));
        pushButton_UnlightAllLed->setText(QApplication::translate("Dialog", "Unlight All", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabLED), QApplication::translate("Dialog", "LED", 0));
        groupBox_3->setTitle(QApplication::translate("Dialog", "HPS", 0));
        label_hps_key0->setText(QString());
        groupBox_4->setTitle(QApplication::translate("Dialog", "FPGA", 0));
        label_key0->setText(QString());
        label_key1->setText(QString());
        label_sw0->setText(QString());
        label_sw1->setText(QString());
        label_sw2->setText(QString());
        label_sw3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabButton), QApplication::translate("Dialog", "Button", 0));
        label_Z->setText(QApplication::translate("Dialog", "Z: xxxx.xxx", 0));
        label_X->setText(QApplication::translate("Dialog", "X: xxxx.xxx", 0));
        label_Y->setText(QApplication::translate("Dialog", "Y: xxxx.xxx", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabGsensor), QApplication::translate("Dialog", "G-Sensor", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
