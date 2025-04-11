#include "dialog.h"
#include "ui_dialog.h"
#include "mpu6050.h"
#include <stdio.h>
#include <QPainter>
#include <QtCore>


void Dialog::TabGsensorPolling(HPS *hps) {
    int16_t GyroX, GyroY, GyroZ;
    static const float dt = 0.1;  // 采样时间（100ms）

    m_bGsensorDataValid = hps->GsensorQuery(&GyroX, &GyroY, &GyroZ);

    if (m_bGsensorDataValid) {
        // 角速度转换为角度 (Roll, Pitch)
        m_Roll += (GyroX / 131.0) * dt;   // 计算 X 轴旋转角度（Roll）
        m_Pitch += (GyroY / 131.0) * dt;  // 计算 Y 轴旋转角度（Pitch）
        m_Yaw -= (GyroZ / 131.0) * dt;

        // 限制角度范围，防止溢出
        if (m_Roll > 180) m_Roll -= 360;
        if (m_Roll < -180) m_Roll += 360;
        if (m_Pitch > 90) m_Pitch = 90;   // Pitch 角度范围（防止翻转）
        if (m_Pitch < -90) m_Pitch = -90;
        if (m_Yaw > 180) m_Yaw -= 360;   // Pitch 角度范围（防止翻转）
        if (m_Yaw < -180) m_Yaw +=360 ;

        // 更新 UI 角度显示
        char szText[64];
        sprintf(szText, "Roll=%.1f°", m_Roll);
        ui->label_X->setText(szText);

        sprintf(szText, "Pitch=%.1f°", m_Pitch);
        ui->label_Y->setText(szText);

        sprintf(szText, "Yaw=%.1f°", m_Yaw);
        ui->label_Z->setText(szText);

        // 更新 UI 绘制
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
    static float direction = 0;  // 初始朝向角度（0 朝上）

    // 移动逻辑（基于航向角）
    if (m_bGsensorDataValid) {
        float step = 3.0;  // 可根据编码器速度计算
        direction = m_Yaw;

        float dx = step * qSin(qDegreesToRadians(direction));
        float dy = -step * qCos(qDegreesToRadians(direction));  // Y 轴向下

        carPos += QPointF(dx, dy);
        carPath.append(carPos);
    }

    painter.begin(ui->tabGsensor);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 背景
    painter.fillRect(rc, Qt::white);

    // 轨迹绘制
    painter.setPen(QPen(Qt::blue, 1.5));
    for (int i = 1; i < carPath.size(); ++i)
        painter.drawLine(carPath[i - 1], carPath[i]);

    // 变换：小车朝向
    QTransform transform;
    transform.translate(carPos.x(), carPos.y());
    transform.rotate(direction);
    transform.translate(-carPos.x(), -carPos.y());
    painter.setTransform(transform);

    // 小车矩形车身
    QRect carBody(carPos.x() - CarSize, carPos.y() - CarSize / 2, CarSize * 2, CarSize);
    painter.setBrush(QColor(100, 100, 255));
    painter.drawRoundedRect(carBody, 5, 5);

    // 前方箭头表示方向
    QPolygon arrow;
    arrow << QPoint(carPos.x(), carPos.y() - CarSize / 2)
          << QPoint(carPos.x() - 5, carPos.y() - CarSize - 5)
          << QPoint(carPos.x() + 5, carPos.y() - CarSize - 5);
    painter.setBrush(Qt::red);
    painter.drawPolygon(arrow);

    painter.end();
}

