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
    m_panel(new CustomPanel(this))
{
    setWindowTitle(m_title);
    resize(m_size);

    m_layout->setMenuBar(menuBar);

    m_layout->addWidget(m_panel);

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
    editMenu->addAction(undoAct);

    QAction* redoAct = new QAction(tr("Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    editMenu->addAction(redoAct);

    QToolBar *verticalToolBar = new QToolBar(tr("Tools"), this);
    verticalToolBar->setOrientation(Qt::Vertical);

    connect(undoAct, &QAction::triggered, m_panel, &CustomPanel::undo);
    connect(redoAct, &QAction::triggered, m_panel, &CustomPanel::redo);
}


void MainWindow::setupToolBar()
{
    QToolBar *verticalToolBar = new QToolBar(tr("Tools"), this);
    verticalToolBar->setOrientation(Qt::Vertical);

    QVBoxLayout *v_layout = new QVBoxLayout;

    QAction *tool1Action = new QAction(tr("Tool 1"), this);
    QAction *tool2Action = new QAction(tr("Tool 2"), this);

    QAction *clearAction = new QAction(tr("Clear"), this);
    verticalToolBar->addAction(clearAction);

    verticalToolBar->addAction(tool1Action);
    verticalToolBar->addAction(tool2Action);

   auto toolActionClicked = [&](QAction *action)
   {
        QList<QAction*> toolActions = verticalToolBar->actions();
        for (auto toolAction : toolActions)
        {
            if (toolAction != action)
            {
                toolAction->setCheckable(false);
                toolAction->setChecked(false);
            }
        }

        action->setCheckable(true);
        action->setChecked(true);

    };

    connect(tool1Action, &QAction::triggered, this, [&]() {
        toolActionClicked(tool1Action);
    });

    connect(tool2Action, &QAction::triggered, this, [&]() {
        toolActionClicked(tool2Action);
    });

    connect(clearAction, &QAction::triggered, m_panel, &CustomPanel::clearPanel);

    v_layout->addWidget(verticalToolBar);
    m_layout->insertLayout(0, v_layout);
}

