#pragma once

#include "MainPanel.h"

#include <QMainWindow>
#include <QHBoxLayout>
#include <QWidget>
#include <QScrollArea>

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow();

    private slots:
        
    private:
        void setupMenuBar();
        void setupToolBar();

        CustomPanel *m_panel;

        const QSize m_size{1200, 600};
        const QString m_title = "AI";

        QMenuBar *menuBar;
        QHBoxLayout *m_layout;
        QScrollArea* scrollArea;
};

