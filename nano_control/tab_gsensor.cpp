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


        uint32_t count1 = 0;
        fpga->Encoder1Read(&count1);
        uint32_t count2 = 0;
        fpga->Encoder2Read(&count2);

        char szText1[32];

            sprintf(szText1, "e1=%p", count1);
            ui->label_encoder1->setText(szText1);

            sprintf(szText1, "e2=%p", count2);
            ui->label_encoder2->setText(szText1);

        // **刷新 UI**
        ui->tabGsensor->update();
    } else {
        ui->label_X->setText("Roll=NA");
        ui->label_Y->setText("Pitch=NA");
        ui->label_Z->setText("Yaw=NA");
    }
}


void Dialog::TabGsensorDraw() {
    static QVector<QPointF> carPath;

    QPainter painter;
    QRect rc = ui->tabGsensor->rect();
    QPoint center = rc.center();  // 起始中心点
    const int CarSize = rc.height() / 15;

    static QPointF carPos = center;
    static float lastDistance = 0;
    static float direction = 0;
    uint32_t count2 = 0;
    fpga->Encoder2Read(&count2);
    float currentDistance = count2; // ✅ 使用你的编码器总里程变量（单位：像素或毫米）

    if (m_bGsensorDataValid) {
        float step = currentDistance - lastDistance; // 本次移动距离
        lastDistance = currentDistance;
        direction = m_Yaw;

        float dx = step * qSin(qDegreesToRadians(direction));
        float dy = -step * qCos(qDegreesToRadians(direction));
        carPos += QPointF(dx, dy);
        carPath.append(carPos);
    }

    painter.begin(ui->tabGsensor);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillRect(rc, Qt::white);

    // 轨迹绘制
    painter.setPen(QPen(Qt::blue, 1.5));
    for (int i = 1; i < carPath.size(); ++i)
        painter.drawLine(carPath[i - 1], carPath[i]);

    // 朝向变换
    QTransform transform;
    transform.translate(carPos.x(), carPos.y());
    transform.rotate(direction);
    transform.translate(-carPos.x(), -carPos.y());
    painter.setTransform(transform);

    // 小车体
    QRect carBody(carPos.x() - CarSize, carPos.y() - CarSize / 2, CarSize * 2, CarSize);
    painter.setBrush(QColor(100, 100, 255));
    painter.drawRoundedRect(carBody, 5, 5);

    // 方向箭头
    QPolygon arrow;
    arrow << QPoint(carPos.x(), carPos.y() - CarSize / 2)
          << QPoint(carPos.x() - 5, carPos.y() - CarSize - 5)
          << QPoint(carPos.x() + 5, carPos.y() - CarSize - 5);
    painter.setBrush(Qt::red);
    painter.drawPolygon(arrow);

    painter.end();
}
