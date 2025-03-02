#include "dialog.h"
#include "ui_dialog.h"
#include <stdio.h>
#include <QPainter>
#include <QtCore>


// QRect: http://qt-project.org/doc/qt-5.0/qtcore/qrect.html
// QPoint: http://qt-project.org/doc/qt-5.0/qtcore/qpoint.html





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
    QPainter painter;
    QRect rc = ui->tabGsensor->rect();
    const int ArrowLength = rc.height() / 3;  // 箭头长度
    QPoint center = rc.center();  // 旋转中心

    painter.begin(ui->tabGsensor);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 画背景圆盘
    painter.setPen(QPen(Qt::black, 2, Qt::DashDotLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::lightGray, Qt::SolidPattern));
    painter.drawEllipse(rc.center(), ArrowLength + 10, ArrowLength + 10);

    // 画十字线
    painter.setPen(QPen(Qt::gray, 1, Qt::DotLine, Qt::RoundCap));
    painter.drawLine(rc.left(), center.y(), rc.right(), center.y());
    painter.drawLine(center.x(), rc.top(), center.x(), rc.bottom());

    if (m_bGsensorDataValid) {
        // 旋转箭头
        QTransform transform;
        transform.translate(center.x(), center.y());
        transform.rotate(m_Yaw);  // 根据 Roll 角度旋转箭头
        painter.setTransform(transform);

        // 绘制箭头
        QPoint arrowHead(0, -ArrowLength);  // 指向顶部
        QPoint leftWing(-10, -ArrowLength + 15);
        QPoint rightWing(10, -ArrowLength + 15);
        QPolygon arrow;
        arrow << arrowHead << leftWing << rightWing << arrowHead;

        painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
        painter.drawPolygon(arrow);
    }

    painter.end();
}
