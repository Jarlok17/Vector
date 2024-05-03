#pragma once

#include "ImageFormat.h"
#include "MainPanel.h"

#include <QMainWindow>
#include <QHBoxLayout>
#include <QTabWidget>
#include <QWidget>

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow();

    private slots:

    private:
        void setupMenuBar();
        void setupToolBar();

        MainPanel *m_panel;
        ImageFormat *image;

        const QSize m_size{1200, 600};
        const QString m_title = "Vector";

        QMenuBar *menuBar;
        QTabWidget *tabWidget;
        QHBoxLayout *m_layout;
};

