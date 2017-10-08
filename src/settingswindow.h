#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QStackedWidget>
#include <QSplitter>
#include <QLabel>

//Helper Widgets
class ToolPanel : public QWidget
{
public:
    ToolPanel(QWidget* parent = 0);
private:
    void initGUI();
};

class LocalPanel: public QWidget
{
public:
    LocalPanel(QWidget* parent = 0);
private:
    void initGUI();
};

class NetworkPanel : public QWidget
{
public:
    NetworkPanel(QWidget* parent = 0);
private:
    void initGUI();
};

//Handles the Network Credentials stuff
class SettingsWindow : public QDialog
{
public:
    SettingsWindow();
private:
    void initGUI();

    QListWidget*    m_prefOptions;
    ToolPanel*      m_toolPanel;
    LocalPanel*     m_localPanel;
    NetworkPanel*   m_networkPanel;
};

#endif // SETTINGSWINDOW_H
