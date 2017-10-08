#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>


#include "settingswindow.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    /*
    * Initializes the GUI
    */
    void initGUI();
    SettingsWindow* m_settingsWindow;
};

#endif // MAINWINDOW_H
