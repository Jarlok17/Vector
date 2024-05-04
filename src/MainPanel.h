#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QStack>

class CustomPanel : public QWidget
{
    Q_OBJECT

public:
    explicit CustomPanel(QWidget *parent = nullptr);
    void setColor(const QColor &color);

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

    QPixmap m_pixmap;
    QStack<QPixmap> m_undoStack;
    QStack<QPixmap> m_redoStack;

    void drawLineTo(const QPoint &endPoint);
    void updatePixmap();
};
