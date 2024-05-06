#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QStack>
#include <QUndoCommand>
#include <QUndoStack>

class CustomPanel : public QWidget
{
    Q_OBJECT

public:
    explicit CustomPanel(QWidget *parent = nullptr);

    void setColor(const QColor &color);
    void setSize(const size_t& width, const size_t& height) { ((width < 0) || (height < 0)) ? qDebug("Size can not be fewer than 0") : this->setFixedSize(width, height); this->update(); }

public slots:
    void clearPanel();
    void undo();
    void redo();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override; 

private:
    QColor m_drawColor;

    QPoint m_lastPoint;
    QVector<QVector<QPoint>> m_lines;

    QPixmap m_image;

    void drawLineTo(const QPoint &endPoint);
    void updatePixmap();
};
