#pragma once

#include <QWidget>
#include <QPainter>
#include <qcolor.h>

class MainPanel : public QWidget
{
    Q_OBJECT

    public:
        MainPanel(QWidget *parent = nullptr);

    protected:
        void paintEvent(QPaintEvent *event) override;

    private:
        QColor m_backgroundColor;
};
