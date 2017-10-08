#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_settingsWindow = new SettingsWindow();
    initGUI();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initGUI()
{
    auto openLclAction = new QAction("&Open Local Folder", this);
    auto connectToNetworkFolder = new QAction("&Connect To Folder", this);
    auto quitAct = new QAction("Quit", this);

    auto undoAct = new QAction("&Undo", this);
    auto redoAct = new QAction("&Redo", this);

    auto nextFrameAct = new QAction("&Next Frame", this);
    auto prevFrameAct = new QAction("&Previous Frame");

    auto preferenceAct = new QAction("Settings", this);

    auto fileMenu = menuBar()->addMenu("&File");
    auto openMenu = fileMenu->addMenu("&Open");
    openMenu->addAction(openLclAction);
    openMenu->addAction(connectToNetworkFolder);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    auto editMenu = menuBar()->addMenu("&Edit");
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(nextFrameAct);
    editMenu->addAction(prevFrameAct);
    editMenu->addSeparator();
    editMenu->addAction(preferenceAct);

    auto helpMenu = menuBar()->addMenu("&Help");

    connect(quitAct, SIGNAL(triggered(bool)), SLOT(close()));
    connect(preferenceAct, SIGNAL(triggered(bool)), m_settingsWindow, SLOT(show()));
}
