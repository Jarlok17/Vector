#include "MainPanel.h"

#include <QMouseEvent>
#include <cmath>

CustomPanel::CustomPanel(QWidget *parent)
    : QWidget(parent)
{
    m_drawColor = Qt::black;
}

void CustomPanel::setColor(const QColor &color)
{
    m_drawColor = color;
}

void CustomPanel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_lastPoint = event->pos();
        m_lines.append(QVector<QPoint>());
        m_lines.last().append(m_lastPoint);
    }
}

void CustomPanel::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) 
    {
        drawLineTo(event->pos());
    }
}

void CustomPanel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        update();
    }
}

void CustomPanel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);
    painter.setRenderHint(QPainter::Antialiasing);

    int fixedRadius = 5;
    for (const auto &line : m_lines)
    {
        for (int i = 1; i < line.size(); ++i)
        {
            QPoint center = (line.at(i - 1) + line.at(i)) / 2;

            painter.setBrush(m_drawColor);
            painter.setPen(Qt::NoPen);

            painter.drawEllipse(center, fixedRadius, fixedRadius);
        }
    }

    QWidget::paintEvent(event);
}

void CustomPanel::drawLineTo(const QPoint &endPoint)
{
    if (m_lines.isEmpty())
    {
        m_lines.append(QVector<QPoint>());
        m_lines.last().append(endPoint);
    }
    else
    {
        QPoint diff = endPoint - m_lastPoint;
        int steps = qMax(qAbs(diff.x()), qAbs(diff.y()));
        float dx = diff.x() / (float)steps;
        float dy = diff.y() / (float)steps;

        for (int i = 0; i < steps; ++i)
        {
            QPoint nextPoint(round(m_lastPoint.x() + dx * i * 2), round(m_lastPoint.y() + dy * i * 2));
            QVector<QPoint> line;
            line.append(m_lastPoint);
            line.append(nextPoint);
            m_lines.append(line);
        }
    }

    m_lastPoint = endPoint;
    update();
}

void CustomPanel::clearPanel()
{
    for (auto &line : m_lines)
    {
        line.clear();
    }
    m_lines.clear();
    update();
}

void CustomPanel::undo()
{
}

void CustomPanel::redo()
{
}
