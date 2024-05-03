#include "MainPanel.h"

MainPanel::MainPanel(QWidget *parent)
    :QWidget(parent)
{ 

}

void MainPanel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); 

    painter.fillRect(rect(), Qt::white);

    QWidget::paintEvent(event);
}
