#include "MainWindow.h"

#include <QMenuBar>
#include <QAction>
#include <QPushButton>
#include <QTabBar>
#include <QToolBar>

MainWindow::MainWindow()
    : QWidget(),
    menuBar(new QMenuBar(this)), 
    m_layout(new QHBoxLayout(this)),
    tabWidget(new QTabWidget(this)),
    image(new ImageFormat(this)),
    m_panel(new MainPanel(this)) 
{
    setWindowTitle(m_title);
    resize(m_size);

    m_layout->setMenuBar(menuBar);

    m_layout->addWidget(tabWidget);
    tabWidget->addTab(m_panel, "Панель");

    tabWidget->tabBar()->setTabsClosable(true);
    connect(tabWidget->tabBar(), &QTabBar::tabCloseRequested, this, [&](const int &index){
                tabWidget->removeTab(index);
            });

    setupMenuBar();
    
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

    QToolBar *verticalToolBar = new QToolBar(tr("Tools"), this);
    verticalToolBar->setOrientation(Qt::Vertical);
}

void MainWindow::setupToolBar()
{
    QToolBar *verticalToolBar = new QToolBar(tr("Tools"), this);
    verticalToolBar->setOrientation(Qt::Vertical);

    QVBoxLayout *v_layout = new QVBoxLayout;
    
    QAction *brushAction = new QAction("B", this);
    verticalToolBar->addAction(brushAction);

    QAction *eraserAction = new QAction("E", this);
    verticalToolBar->addAction(eraserAction);
 
    v_layout->addWidget(verticalToolBar);
    
    m_layout->addLayout(v_layout);
}

