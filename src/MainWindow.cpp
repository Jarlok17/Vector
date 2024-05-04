#include "MainWindow.h"

#include "MainPanel.h"

#include <QMenuBar>
#include <QAction>
#include <QPushButton>
#include <QTabBar>
#include <QToolBar>
#include <QApplication>
#include <QScrollBar>

MainWindow::MainWindow()
    : QWidget(),
    menuBar(new QMenuBar(this)), 
    m_layout(new QHBoxLayout(this)),
    m_panel(new CustomPanel(this)),
    scrollArea(new QScrollArea(this))
{
    setWindowTitle(m_title);
    resize(m_size);

    m_layout->setMenuBar(menuBar);
    
    scrollArea->setWidgetResizable(true);
    
    scrollArea->setWidget(m_panel);
    m_layout->addWidget(scrollArea);

    setupMenuBar();
    setupToolBar();
    
    this->setLayout(m_layout);
}

void MainWindow::setupMenuBar()
{
    QMenu* fileMenu = menuBar->addMenu(tr("File"));
    QMenu* editMenu = menuBar->addMenu(tr("Edit"));
    QMenu* selectMenu = menuBar->addMenu(tr("Select"));
    QMenu* imageMenu = menuBar->addMenu(tr("Image"));
    QMenu* viewMenu = menuBar->addMenu(tr("View"));
    QMenu* windowMenu = menuBar->addMenu(tr("Window"));
    QMenu* helpMenu = menuBar->addMenu(tr("Help"));

    QAction* newAct = new QAction(tr("New..."), this);
    newAct->setShortcuts(QKeySequence::New);
    fileMenu->addAction(newAct);

    QAction* openAct = new QAction(tr("Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    fileMenu->addAction(openAct);

    QAction* saveAct = new QAction(tr("Save..."), this);
    saveAct->setShortcuts(QKeySequence::Save);
    fileMenu->addAction(saveAct);

    QAction* saveAsAct = new QAction(tr("Save As..."), this);
    saveAsAct->setShortcut(QKeySequence(tr("Ctrl+Shift+S", "File | Save as...")));
    fileMenu->addAction(saveAsAct);

    QAction* exportAct = new QAction(tr("Export..."), this);
    exportAct->setShortcut(QKeySequence(tr("Ctrl+E", "File | Export...")));
    fileMenu->addAction(exportAct);

    QAction* exportAsAct = new QAction(tr("Export as..."), this);
    exportAsAct->setShortcut(QKeySequence(tr("Shift+Ctrl+E", "File | Export as...")));
    fileMenu->addAction(exportAsAct);

    QAction* undoAct = new QAction(tr("Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    connect(undoAct, &QAction::triggered, m_panel, &CustomPanel::undo);
    editMenu->addAction(undoAct);

    QAction* redoAct = new QAction(tr("Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    connect(redoAct, &QAction::triggered, m_panel, &CustomPanel::redo);
    editMenu->addAction(redoAct);

    QToolBar *verticalToolBar = new QToolBar(tr("Tools"), this);
    verticalToolBar->setOrientation(Qt::Vertical);
}

void MainWindow::setupToolBar()
{
    QToolBar *verticalToolBar = new QToolBar(tr("Tools"), this);
    verticalToolBar->setOrientation(Qt::Vertical);

    QVBoxLayout *v_layout = new QVBoxLayout;
    
    for (int i = 0; i < 10; ++i) 
    {
        QPushButton *button = new QPushButton(QString::number(i), this);
        verticalToolBar->addWidget(button);
    }

    QAction *clearAction = new QAction(tr("Clear"), this);
    connect(clearAction, &QAction::triggered, m_panel, &CustomPanel::clearPanel);
    verticalToolBar->addAction(clearAction);

    v_layout->addWidget(verticalToolBar);
    m_layout->addLayout(v_layout);
}


