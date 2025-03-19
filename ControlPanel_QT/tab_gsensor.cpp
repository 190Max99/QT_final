#include "dialog.h"
#include "ui_dialog.h"
#include "mpu6050.h"
#include <stdio.h>
#include <QPainter>
#include <QtCore>


void Dialog::TabGsensorPolling(HPS *hps) {
    int16_t accel[3], gyro[3];

    if (m_bGsensorDataValid = hps->GsensorQuery(accel, gyro)) {
        // **使用四元数更新姿态**
        MPU6050_UpdateQuaternion(accel, gyro);

        // **获取欧拉角**
        MPU6050_GetEulerAngles(&m_Roll, &m_Pitch, &m_Yaw);

        // 限制角度范围
        if (m_Roll > 180) m_Roll -= 360;
        if (m_Roll < -180) m_Roll += 360;
        if (m_Pitch > 90) m_Pitch = 90;
        if (m_Pitch < -90) m_Pitch = -90;
        if (m_Yaw > 180) m_Yaw -= 360;
        if (m_Yaw < -180) m_Yaw += 360;

        // **更新 UI 显示**
        char szText[64];
        sprintf(szText, "Roll=%.1f°", m_Roll);
        ui->label_X->setText(szText);

        sprintf(szText, "Pitch=%.1f°", m_Pitch);
        ui->label_Y->setText(szText);

        sprintf(szText, "Yaw=%.1f°", m_Yaw);
        ui->label_Z->setText(szText);

        // **刷新 UI**
        ui->tabGsensor->update();
    } else {
        ui->label_X->setText("Roll=NA");
        ui->label_Y->setText("Pitch=NA");
        ui->label_Z->setText("Yaw=NA");
    }
}


void Dialog::TabGsensorDraw() {
    QPainter painter;
    QRect rc = ui->tabGsensor->rect();
    QPoint center = rc.center();  // 旋转中心
    const int PlaneSize = rc.height() / 4;  // 纸飞机尺寸

    painter.begin(ui->tabGsensor);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // **绘制背景圆盘**
    painter.setPen(QPen(Qt::black, 2, Qt::DashDotLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::lightGray, Qt::SolidPattern));
    painter.drawEllipse(center, PlaneSize + 20, PlaneSize + 20);

    // **绘制十字线**
    painter.setPen(QPen(Qt::gray, 1, Qt::DotLine, Qt::RoundCap));
    painter.drawLine(rc.left(), center.y(), rc.right(), center.y());
    painter.drawLine(center.x(), rc.top(), center.x(), rc.bottom());

    if (m_bGsensorDataValid) {
        // **正确的旋转顺序 (Yaw -> Pitch -> Roll)**
        QTransform transform;
        transform.translate(center.x(), center.y());
        transform.rotate(m_Yaw, Qt::ZAxis);   // 偏航角（绕 Z 轴旋转）
        transform.rotate(m_Pitch, Qt::XAxis); // 俯仰角（绕 X 轴旋转）
        transform.rotate(m_Roll, Qt::YAxis);  // 滚转角（绕 Y 轴旋转）
        transform.translate(-center.x(), -center.y());
        painter.setTransform(transform);

        // **绘制 3D 纸飞机**
        QPolygon body, leftWing, rightWing, tail;

        // **机身**
        body << QPoint(center.x(), center.y() - PlaneSize)  // 顶点
             << QPoint(center.x() - 10, center.y() + PlaneSize)
             << QPoint(center.x() + 10, center.y() + PlaneSize);

        // **左翼**
        leftWing << QPoint(center.x(), center.y() - PlaneSize / 2)
                 << QPoint(center.x() - PlaneSize, center.y() + PlaneSize / 3)
                 << QPoint(center.x(), center.y() + PlaneSize / 2);

        // **右翼**
        rightWing << QPoint(center.x(), center.y() - PlaneSize / 2)
                  << QPoint(center.x() + PlaneSize, center.y() + PlaneSize / 3)
                  << QPoint(center.x(), center.y() + PlaneSize / 2);

        // **尾翼**
        tail << QPoint(center.x() - 5, center.y() + PlaneSize / 2)
             << QPoint(center.x() + 5, center.y() + PlaneSize / 2)
             << QPoint(center.x(), center.y() + PlaneSize);

        // **绘制机身**
        painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
        painter.drawPolygon(body);

        // **绘制左翼**
        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
        painter.drawPolygon(leftWing);

        // **绘制右翼**
        painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
        painter.drawPolygon(rightWing);

        // **绘制尾翼**
        painter.setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
        painter.drawPolygon(tail);
    }

    painter.end();
}
