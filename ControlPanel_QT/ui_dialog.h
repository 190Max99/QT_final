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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QCheckBox *checkBox_LED9;
    QCheckBox *checkBox_LED0;
    QCheckBox *checkBox_LED2;
    QCheckBox *checkBox_LED3;
    QCheckBox *checkBox_LED4;
    QCheckBox *checkBox_LED5;
    QCheckBox *checkBox_LED6;
    QCheckBox *checkBox_LED7;
    QCheckBox *checkBox_LED8;
    QGroupBox *groupBox_hps_led;
    QCheckBox *checkBox_HPS_LED0;
    QPushButton *pushButton_LightAllLed;
    QPushButton *pushButton_UnlightAllLed;
    QWidget *tabHEX;
    QLabel *label_hex0;
    QSpinBox *spinBox_hex0;
    QLabel *label_hex1;
    QSpinBox *spinBox_hex1;
    QSpinBox *spinBox_hex3;
    QLabel *label_hex2;
    QLabel *label_hex3;
    QSpinBox *spinBox_hex2;
    QSpinBox *spinBox_hex5;
    QLabel *label_hex4;
    QLabel *label_hex5;
    QSpinBox *spinBox_hex4;
    QWidget *tabButton;
    QGroupBox *groupBox_3;
    QLabel *label_hps_key0;
    QGroupBox *groupBox_4;
    QLabel *label_key0;
    QLabel *label_key1;
    QLabel *label_key2;
    QLabel *label_key3;
    QLabel *label_sw0;
    QLabel *label_sw1;
    QLabel *label_sw2;
    QLabel *label_sw3;
    QLabel *label_sw5;
    QLabel *label_sw4;
    QLabel *label_sw6;
    QLabel *label_sw8;
    QLabel *label_sw7;
    QLabel *label_sw9;
    QWidget *tabGsensor;
    QLabel *label_Z;
    QLabel *label_X;
    QLabel *label_Y;
    QWidget *tabLCD;
    QCheckBox *checkBox_LCD_Backlight;
    QComboBox *comboBox_LcdDemo;
    QLabel *label_3;
    QLabel *label_lcd_demo_image;
    QWidget *tabVideoIn;
    QLabel *label_2;
    QWidget *Audio;
    QPushButton *tone_c;
    QPushButton *tone_d;
    QPushButton *tone_e;
    QPushButton *tone_f;
    QPushButton *tone_g;
    QPushButton *tone_a;
    QPushButton *tone_b;
    QLabel *label;
    QWidget *tabIR;
    QGroupBox *groupBox_IR_RX;
    QLabel *label_ir_controller;
    QCheckBox *checkBox;

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
        tabWidget->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget->setAutoFillBackground(false);
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
        checkBox_LED1->setGeometry(QRect(15, 60, 95, 35));
        QFont font;
        font.setBold(false);
        font.setStrikeOut(false);
        font.setKerning(false);
        checkBox_LED1->setFont(font);
        checkBox_LED1->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/Myresource/RLED.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox_LED1->setIcon(icon);
        checkBox_LED1->setTristate(false);
        checkBox_LED9 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED9->setObjectName(QStringLiteral("checkBox_LED9"));
        checkBox_LED9->setGeometry(QRect(120, 150, 95, 35));
        checkBox_LED9->setFont(font);
        checkBox_LED9->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED9->setIcon(icon);
        checkBox_LED9->setTristate(false);
        checkBox_LED0 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED0->setObjectName(QStringLiteral("checkBox_LED0"));
        checkBox_LED0->setGeometry(QRect(15, 30, 95, 35));
        checkBox_LED0->setFont(font);
        checkBox_LED0->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED0->setIcon(icon);
        checkBox_LED0->setTristate(false);
        checkBox_LED2 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED2->setObjectName(QStringLiteral("checkBox_LED2"));
        checkBox_LED2->setGeometry(QRect(15, 90, 95, 35));
        checkBox_LED2->setFont(font);
        checkBox_LED2->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED2->setIcon(icon);
        checkBox_LED2->setTristate(false);
        checkBox_LED3 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED3->setObjectName(QStringLiteral("checkBox_LED3"));
        checkBox_LED3->setGeometry(QRect(15, 120, 95, 35));
        checkBox_LED3->setFont(font);
        checkBox_LED3->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED3->setIcon(icon);
        checkBox_LED3->setTristate(false);
        checkBox_LED4 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED4->setObjectName(QStringLiteral("checkBox_LED4"));
        checkBox_LED4->setGeometry(QRect(15, 150, 95, 35));
        checkBox_LED4->setFont(font);
        checkBox_LED4->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED4->setIcon(icon);
        checkBox_LED4->setTristate(false);
        checkBox_LED5 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED5->setObjectName(QStringLiteral("checkBox_LED5"));
        checkBox_LED5->setGeometry(QRect(120, 30, 95, 35));
        checkBox_LED5->setFont(font);
        checkBox_LED5->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED5->setIcon(icon);
        checkBox_LED5->setTristate(false);
        checkBox_LED6 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED6->setObjectName(QStringLiteral("checkBox_LED6"));
        checkBox_LED6->setGeometry(QRect(120, 60, 95, 35));
        checkBox_LED6->setFont(font);
        checkBox_LED6->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED6->setIcon(icon);
        checkBox_LED6->setTristate(false);
        checkBox_LED7 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED7->setObjectName(QStringLiteral("checkBox_LED7"));
        checkBox_LED7->setGeometry(QRect(120, 90, 95, 35));
        checkBox_LED7->setFont(font);
        checkBox_LED7->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED7->setIcon(icon);
        checkBox_LED7->setTristate(false);
        checkBox_LED8 = new QCheckBox(groupBox_fpga_led);
        checkBox_LED8->setObjectName(QStringLiteral("checkBox_LED8"));
        checkBox_LED8->setGeometry(QRect(120, 120, 95, 35));
        checkBox_LED8->setFont(font);
        checkBox_LED8->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_LED8->setIcon(icon);
        checkBox_LED8->setTristate(false);
        groupBox_hps_led = new QGroupBox(tabLED);
        groupBox_hps_led->setObjectName(QStringLiteral("groupBox_hps_led"));
        groupBox_hps_led->setGeometry(QRect(280, 20, 121, 81));
        checkBox_HPS_LED0 = new QCheckBox(groupBox_hps_led);
        checkBox_HPS_LED0->setObjectName(QStringLiteral("checkBox_HPS_LED0"));
        checkBox_HPS_LED0->setGeometry(QRect(10, 30, 95, 35));
        checkBox_HPS_LED0->setFont(font);
        checkBox_HPS_LED0->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/Myresource/GLED.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox_HPS_LED0->setIcon(icon1);
        checkBox_HPS_LED0->setTristate(false);
        pushButton_LightAllLed = new QPushButton(tabLED);
        pushButton_LightAllLed->setObjectName(QStringLiteral("pushButton_LightAllLed"));
        pushButton_LightAllLed->setGeometry(QRect(280, 140, 80, 23));
        pushButton_LightAllLed->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_UnlightAllLed = new QPushButton(tabLED);
        pushButton_UnlightAllLed->setObjectName(QStringLiteral("pushButton_UnlightAllLed"));
        pushButton_UnlightAllLed->setGeometry(QRect(280, 170, 80, 23));
        pushButton_UnlightAllLed->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget->addTab(tabLED, icon1, QString());
        tabHEX = new QWidget();
        tabHEX->setObjectName(QStringLiteral("tabHEX"));
        tabHEX->setCursor(QCursor(Qt::ArrowCursor));
        label_hex0 = new QLabel(tabHEX);
        label_hex0->setObjectName(QStringLiteral("label_hex0"));
        label_hex0->setGeometry(QRect(350, 70, 40, 59));
        label_hex0->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/HEX_0.bmp")));
        spinBox_hex0 = new QSpinBox(tabHEX);
        spinBox_hex0->setObjectName(QStringLiteral("spinBox_hex0"));
        spinBox_hex0->setGeometry(QRect(350, 130, 40, 24));
        spinBox_hex0->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_hex0->setMaximum(9);
        label_hex1 = new QLabel(tabHEX);
        label_hex1->setObjectName(QStringLiteral("label_hex1"));
        label_hex1->setGeometry(QRect(290, 70, 40, 59));
        label_hex1->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/HEX_1.bmp")));
        spinBox_hex1 = new QSpinBox(tabHEX);
        spinBox_hex1->setObjectName(QStringLiteral("spinBox_hex1"));
        spinBox_hex1->setGeometry(QRect(290, 130, 40, 24));
        spinBox_hex1->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_hex1->setMaximum(9);
        spinBox_hex3 = new QSpinBox(tabHEX);
        spinBox_hex3->setObjectName(QStringLiteral("spinBox_hex3"));
        spinBox_hex3->setGeometry(QRect(170, 130, 40, 24));
        spinBox_hex3->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_hex3->setMaximum(9);
        label_hex2 = new QLabel(tabHEX);
        label_hex2->setObjectName(QStringLiteral("label_hex2"));
        label_hex2->setGeometry(QRect(230, 70, 40, 59));
        label_hex2->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/HEX_2.bmp")));
        label_hex3 = new QLabel(tabHEX);
        label_hex3->setObjectName(QStringLiteral("label_hex3"));
        label_hex3->setGeometry(QRect(170, 70, 40, 59));
        label_hex3->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/HEX_3.bmp")));
        spinBox_hex2 = new QSpinBox(tabHEX);
        spinBox_hex2->setObjectName(QStringLiteral("spinBox_hex2"));
        spinBox_hex2->setGeometry(QRect(230, 130, 40, 24));
        spinBox_hex2->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_hex2->setMaximum(9);
        spinBox_hex5 = new QSpinBox(tabHEX);
        spinBox_hex5->setObjectName(QStringLiteral("spinBox_hex5"));
        spinBox_hex5->setGeometry(QRect(50, 130, 40, 24));
        spinBox_hex5->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_hex5->setMaximum(9);
        label_hex4 = new QLabel(tabHEX);
        label_hex4->setObjectName(QStringLiteral("label_hex4"));
        label_hex4->setGeometry(QRect(110, 70, 40, 59));
        label_hex4->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/HEX_4.bmp")));
        label_hex5 = new QLabel(tabHEX);
        label_hex5->setObjectName(QStringLiteral("label_hex5"));
        label_hex5->setGeometry(QRect(50, 70, 40, 59));
        label_hex5->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/HEX_5.bmp")));
        spinBox_hex4 = new QSpinBox(tabHEX);
        spinBox_hex4->setObjectName(QStringLiteral("spinBox_hex4"));
        spinBox_hex4->setGeometry(QRect(110, 130, 40, 24));
        spinBox_hex4->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox_hex4->setMaximum(9);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/Myresource/HEX_8.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabHEX, icon2, QString());
        tabButton = new QWidget();
        tabButton->setObjectName(QStringLiteral("tabButton"));
        tabButton->setCursor(QCursor(Qt::ArrowCursor));
        groupBox_3 = new QGroupBox(tabButton);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(380, 10, 41, 71));
        label_hps_key0 = new QLabel(groupBox_3);
        label_hps_key0->setObjectName(QStringLiteral("label_hps_key0"));
        label_hps_key0->setGeometry(QRect(10, 30, 21, 31));
        label_hps_key0->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/SMALL_BUTTON_DOWN.bmp")));
        groupBox_4 = new QGroupBox(tabButton);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 10, 340, 210));
        label_key0 = new QLabel(groupBox_4);
        label_key0->setObjectName(QStringLiteral("label_key0"));
        label_key0->setGeometry(QRect(270, 50, 44, 44));
        label_key0->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/BUTTON_UP.bmp")));
        label_key1 = new QLabel(groupBox_4);
        label_key1->setObjectName(QStringLiteral("label_key1"));
        label_key1->setGeometry(QRect(220, 50, 44, 44));
        label_key1->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/BUTTON_UP.bmp")));
        label_key2 = new QLabel(groupBox_4);
        label_key2->setObjectName(QStringLiteral("label_key2"));
        label_key2->setGeometry(QRect(170, 50, 44, 44));
        label_key2->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/BUTTON_UP.bmp")));
        label_key3 = new QLabel(groupBox_4);
        label_key3->setObjectName(QStringLiteral("label_key3"));
        label_key3->setGeometry(QRect(120, 50, 44, 44));
        label_key3->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/BUTTON_UP.bmp")));
        label_sw0 = new QLabel(groupBox_4);
        label_sw0->setObjectName(QStringLiteral("label_sw0"));
        label_sw0->setGeometry(QRect(300, 120, 19, 63));
        label_sw0->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/SW_down.bmp")));
        label_sw1 = new QLabel(groupBox_4);
        label_sw1->setObjectName(QStringLiteral("label_sw1"));
        label_sw1->setGeometry(QRect(270, 120, 19, 63));
        label_sw1->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/SW_down.bmp")));
        label_sw2 = new QLabel(groupBox_4);
        label_sw2->setObjectName(QStringLiteral("label_sw2"));
        label_sw2->setGeometry(QRect(240, 120, 19, 63));
        label_sw2->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/SW_down.bmp")));
        label_sw3 = new QLabel(tabButton);
        label_sw3->setObjectName(QStringLiteral("label_sw3"));
        label_sw3->setGeometry(QRect(230, 130, 19, 63));
        label_sw3->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/SW_down.bmp")));
        label_sw5 = new QLabel(tabButton);
        label_sw5->setObjectName(QStringLiteral("label_sw5"));
        label_sw5->setGeometry(QRect(170, 130, 19, 63));
        label_sw5->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/SW_down.bmp")));
        label_sw4 = new QLabel(tabButton);
        label_sw4->setObjectName(QStringLiteral("label_sw4"));
        label_sw4->setGeometry(QRect(200, 130, 19, 63));
        label_sw4->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/SW_down.bmp")));
        label_sw6 = new QLabel(tabButton);
        label_sw6->setObjectName(QStringLiteral("label_sw6"));
        label_sw6->setGeometry(QRect(140, 130, 19, 63));
        label_sw6->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/SW_down.bmp")));
        label_sw8 = new QLabel(tabButton);
        label_sw8->setObjectName(QStringLiteral("label_sw8"));
        label_sw8->setGeometry(QRect(80, 130, 19, 63));
        label_sw8->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/SW_down.bmp")));
        label_sw7 = new QLabel(tabButton);
        label_sw7->setObjectName(QStringLiteral("label_sw7"));
        label_sw7->setGeometry(QRect(110, 130, 19, 63));
        label_sw7->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/SW_down.bmp")));
        label_sw9 = new QLabel(tabButton);
        label_sw9->setObjectName(QStringLiteral("label_sw9"));
        label_sw9->setGeometry(QRect(50, 130, 19, 63));
        label_sw9->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/SW_down.bmp")));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/Myresource/BUTTON_UP.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabButton, icon3, QString());
        tabGsensor = new QWidget();
        tabGsensor->setObjectName(QStringLiteral("tabGsensor"));
        tabGsensor->setCursor(QCursor(Qt::ArrowCursor));
        label_Z = new QLabel(tabGsensor);
        label_Z->setObjectName(QStringLiteral("label_Z"));
        label_Z->setGeometry(QRect(20, 160, 87, 35));
        QFont font1;
        font1.setPointSize(11);
        label_Z->setFont(font1);
        label_X = new QLabel(tabGsensor);
        label_X->setObjectName(QStringLiteral("label_X"));
        label_X->setGeometry(QRect(20, 80, 87, 35));
        label_X->setFont(font1);
        label_Y = new QLabel(tabGsensor);
        label_Y->setObjectName(QStringLiteral("label_Y"));
        label_Y->setGeometry(QRect(20, 120, 87, 35));
        label_Y->setFont(font1);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/Myresource/tab/G-Sensor.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabGsensor, icon4, QString());
        tabLCD = new QWidget();
        tabLCD->setObjectName(QStringLiteral("tabLCD"));
        checkBox_LCD_Backlight = new QCheckBox(tabLCD);
        checkBox_LCD_Backlight->setObjectName(QStringLiteral("checkBox_LCD_Backlight"));
        checkBox_LCD_Backlight->setGeometry(QRect(30, 20, 261, 20));
        comboBox_LcdDemo = new QComboBox(tabLCD);
        comboBox_LcdDemo->setObjectName(QStringLiteral("comboBox_LcdDemo"));
        comboBox_LcdDemo->setGeometry(QRect(130, 50, 201, 22));
        label_3 = new QLabel(tabLCD);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 50, 101, 20));
        label_lcd_demo_image = new QLabel(tabLCD);
        label_lcd_demo_image->setObjectName(QStringLiteral("label_lcd_demo_image"));
        label_lcd_demo_image->setGeometry(QRect(130, 80, 200, 136));
        label_lcd_demo_image->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/LCD_hello.png")));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/Myresource/LCD_checkerboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabLCD, icon5, QString());
        tabVideoIn = new QWidget();
        tabVideoIn->setObjectName(QStringLiteral("tabVideoIn"));
        label_2 = new QLabel(tabVideoIn);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 215, 360, 16));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/Myresource/tab/movie.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabVideoIn, icon6, QString());
        Audio = new QWidget();
        Audio->setObjectName(QStringLiteral("Audio"));
        tone_c = new QPushButton(Audio);
        tone_c->setObjectName(QStringLiteral("tone_c"));
        tone_c->setGeometry(QRect(48, 40, 50, 150));
        tone_c->setCursor(QCursor(Qt::PointingHandCursor));
        tone_c->setIconSize(QSize(50, 244));
        tone_d = new QPushButton(Audio);
        tone_d->setObjectName(QStringLiteral("tone_d"));
        tone_d->setGeometry(QRect(98, 40, 50, 150));
        tone_d->setCursor(QCursor(Qt::PointingHandCursor));
        tone_d->setIconSize(QSize(50, 244));
        tone_e = new QPushButton(Audio);
        tone_e->setObjectName(QStringLiteral("tone_e"));
        tone_e->setGeometry(QRect(148, 40, 50, 150));
        tone_e->setCursor(QCursor(Qt::PointingHandCursor));
        tone_e->setIconSize(QSize(50, 244));
        tone_f = new QPushButton(Audio);
        tone_f->setObjectName(QStringLiteral("tone_f"));
        tone_f->setGeometry(QRect(198, 40, 50, 150));
        tone_f->setCursor(QCursor(Qt::PointingHandCursor));
        tone_f->setIconSize(QSize(50, 244));
        tone_g = new QPushButton(Audio);
        tone_g->setObjectName(QStringLiteral("tone_g"));
        tone_g->setGeometry(QRect(248, 40, 50, 150));
        tone_g->setCursor(QCursor(Qt::PointingHandCursor));
        tone_g->setIconSize(QSize(50, 244));
        tone_a = new QPushButton(Audio);
        tone_a->setObjectName(QStringLiteral("tone_a"));
        tone_a->setGeometry(QRect(298, 40, 50, 150));
        tone_a->setCursor(QCursor(Qt::PointingHandCursor));
        tone_a->setIconSize(QSize(50, 244));
        tone_b = new QPushButton(Audio);
        tone_b->setObjectName(QStringLiteral("tone_b"));
        tone_b->setGeometry(QRect(348, 40, 50, 150));
        tone_b->setCursor(QCursor(Qt::PointingHandCursor));
        tone_b->setIconSize(QSize(50, 244));
        label = new QLabel(Audio);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 215, 281, 16));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/Myresource/tab/audio.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(Audio, icon7, QString());
        tabIR = new QWidget();
        tabIR->setObjectName(QStringLiteral("tabIR"));
        groupBox_IR_RX = new QGroupBox(tabIR);
        groupBox_IR_RX->setObjectName(QStringLiteral("groupBox_IR_RX"));
        groupBox_IR_RX->setGeometry(QRect(140, 10, 161, 201));
        label_ir_controller = new QLabel(groupBox_IR_RX);
        label_ir_controller->setObjectName(QStringLiteral("label_ir_controller"));
        label_ir_controller->setEnabled(true);
        label_ir_controller->setGeometry(QRect(30, 30, 95, 159));
        label_ir_controller->setPixmap(QPixmap(QString::fromUtf8(":/new/Myresource/IR_RX.bmp")));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/Myresource/tab/IRDA.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabIR, icon8, QString());

        verticalLayout->addWidget(tabWidget);

        checkBox = new QCheckBox(Dialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);


        retranslateUi(Dialog);
        QObject::connect(checkBox_HPS_LED0, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED9, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED0, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED1, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED2, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED3, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED4, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED5, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED6, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED7, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));
        QObject::connect(checkBox_LED8, SIGNAL(clicked()), Dialog, SLOT(ClickLED()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "DE10-Standard Control Panel", 0));
        groupBox_fpga_led->setTitle(QApplication::translate("Dialog", "FPGA LED", 0));
        checkBox_LED1->setText(QApplication::translate("Dialog", "LED1", 0));
        checkBox_LED9->setText(QApplication::translate("Dialog", "LED9", 0));
        checkBox_LED0->setText(QApplication::translate("Dialog", "LED0", 0));
        checkBox_LED2->setText(QApplication::translate("Dialog", "LED2", 0));
        checkBox_LED3->setText(QApplication::translate("Dialog", "LED3", 0));
        checkBox_LED4->setText(QApplication::translate("Dialog", "LED4", 0));
        checkBox_LED5->setText(QApplication::translate("Dialog", "LED5", 0));
        checkBox_LED6->setText(QApplication::translate("Dialog", "LED6", 0));
        checkBox_LED7->setText(QApplication::translate("Dialog", "LED7", 0));
        checkBox_LED8->setText(QApplication::translate("Dialog", "LED8", 0));
        groupBox_hps_led->setTitle(QApplication::translate("Dialog", "HPS LED", 0));
        checkBox_HPS_LED0->setText(QApplication::translate("Dialog", "orige", 0));
        pushButton_LightAllLed->setText(QApplication::translate("Dialog", "Light All", 0));
        pushButton_UnlightAllLed->setText(QApplication::translate("Dialog", "Unlight All", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabLED), QApplication::translate("Dialog", "LED", 0));
        label_hex0->setText(QString());
        label_hex1->setText(QString());
        label_hex2->setText(QString());
        label_hex3->setText(QString());
        label_hex4->setText(QString());
        label_hex5->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabHEX), QApplication::translate("Dialog", "HEX", 0));
        groupBox_3->setTitle(QApplication::translate("Dialog", "HPS", 0));
        label_hps_key0->setText(QString());
        groupBox_4->setTitle(QApplication::translate("Dialog", "FPGA", 0));
        label_key0->setText(QString());
        label_key1->setText(QString());
        label_key2->setText(QString());
        label_key3->setText(QString());
        label_sw0->setText(QString());
        label_sw1->setText(QString());
        label_sw2->setText(QString());
        label_sw3->setText(QString());
        label_sw5->setText(QString());
        label_sw4->setText(QString());
        label_sw6->setText(QString());
        label_sw8->setText(QString());
        label_sw7->setText(QString());
        label_sw9->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabButton), QApplication::translate("Dialog", "Button", 0));
        label_Z->setText(QApplication::translate("Dialog", "Z: xxxx.xxx", 0));
        label_X->setText(QApplication::translate("Dialog", "X: xxxx.xxx", 0));
        label_Y->setText(QApplication::translate("Dialog", "Y: xxxx.xxx", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabGsensor), QApplication::translate("Dialog", "G-Sensor", 0));
        checkBox_LCD_Backlight->setText(QApplication::translate("Dialog", "LCD Backlight", 0));
        label_3->setText(QApplication::translate("Dialog", "Demo Pattern:", 0));
        label_lcd_demo_image->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabLCD), QApplication::translate("Dialog", "LCD", 0));
        label_2->setText(QApplication::translate("Dialog", "Please connect PAL/NTSC video signal to the RCA-in port.", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabVideoIn), QApplication::translate("Dialog", "Video-In", 0));
        tone_c->setText(QApplication::translate("Dialog", "Do", 0));
        tone_d->setText(QApplication::translate("Dialog", "Re", 0));
        tone_e->setText(QApplication::translate("Dialog", "Mi", 0));
        tone_f->setText(QApplication::translate("Dialog", "Fa", 0));
        tone_g->setText(QApplication::translate("Dialog", "Sol", 0));
        tone_a->setText(QApplication::translate("Dialog", "La", 0));
        tone_b->setText(QApplication::translate("Dialog", "Ti", 0));
        label->setText(QApplication::translate("Dialog", "Please connect speaker to the line-out port.", 0));
        tabWidget->setTabText(tabWidget->indexOf(Audio), QApplication::translate("Dialog", "Audio", 0));
        groupBox_IR_RX->setTitle(QApplication::translate("Dialog", "RX", 0));
        label_ir_controller->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabIR), QApplication::translate("Dialog", "IR", 0));
        checkBox->setText(QApplication::translate("Dialog", "CheckBox", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
