#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QPushButton>
#include <QListWidget>
#include <QFileDialog>
#include <QVector>
#include <QImage>
#include <QDirIterator>
#include <QComboBox>

#include "settingswindow.h"
#include "rectmanagement.h"
#include "labellingarea.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void assignImageFolderPath();
private:
    /*
    * Initializes the GUI
    */
    void initGUI();

    void saveSettings();
    void loadSettings();

    SettingsWindow* m_settingsWindow;
    RectManagement* m_rectManagement;
    LabellingArea*  m_labelingWidget;
    QComboBox*      m_tasksContainer;
    QVector<QImage> m_images;
};

#endif // MAINWINDOW_H
