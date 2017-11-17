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

void MainWindow::assignImageFolderPath()
{
    QString path = QFileDialog::getExistingDirectory(this, "Get Image Path" ,QDir::currentPath());
    qDebug() << path << endl;
    QDirIterator it(path);
    while(it.hasNext()){
        QString img = it.next();
        qDebug() << img << endl;
        m_labelingWidget->addImage(img);
    }
}

void MainWindow::initGUI()
{
    m_tasksContainer = new QComboBox(this);
    auto openLclAction = new QAction("&Open Local Folder", this);
    auto connectToNetworkFolder = new QAction("&Connect To Folder", this);
    auto quitAct = new QAction("Quit", this);

    auto undoAct = new QAction("&Undo", this);
    auto redoAct = new QAction("&Redo", this);

    auto nextFrameAct = new QAction("&Next Frame", this);
    auto prevFrameAct = new QAction("&Previous Frame", this);

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

    auto toolBar = addToolBar("Tools");
    toolBar->addAction(undoAct);
    toolBar->addAction(redoAct);
    toolBar->addSeparator();
    toolBar->addAction(prevFrameAct);
    toolBar->addAction(nextFrameAct);
    toolBar->addSeparator();
    toolBar->addWidget(new QLabel("Tasks: ", this));
    toolBar->addWidget(m_tasksContainer);

    m_labelingWidget = new LabellingArea(this);

    m_rectManagement = new RectManagement(this);

    setCentralWidget(m_labelingWidget);

    addDockWidget(Qt::RightDockWidgetArea, m_rectManagement);

    connect(openLclAction, SIGNAL(triggered()), SLOT(assignImageFolderPath()));
    connect(quitAct, SIGNAL(triggered(bool)), SLOT(close()));
    connect(nextFrameAct, SIGNAL(triggered(bool)), m_labelingWidget, SLOT(nextFrame()));
    connect(prevFrameAct, SIGNAL(triggered(bool)), m_labelingWidget, SLOT(previousFrame()));
    connect(preferenceAct, SIGNAL(triggered(bool)), m_settingsWindow, SLOT(show()));
    statusBar()->showMessage("Ready", 2000);
    statusBar()->setSizeGripEnabled(true);
}
