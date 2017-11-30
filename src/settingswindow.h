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
#include <QComboBox>
#include <QGridLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QTextEdit>
#include <QDebug>
#include <QFileDialog>

class AddToolModal : public QWidget{
    Q_OBJECT
public:
    AddToolModal(QWidget* parent = 0);
signals:
    void newToolEmitted(int, QString, QString);
private slots:
    void processNewTool();
private:
    void initGUI();
    QLineEdit*      m_targetNameLE;
    QLineEdit*      m_indexLE;
    QComboBox*      m_colorCMBX;
};

//Helper Widgets
class ToolPanel : public QWidget
{
    Q_OBJECT
public:
    ToolPanel(QWidget* parent = 0);
private slots:
    void addTarget();
    void remTarget();
    void assignConfigPath();
    void addNewTool(int, QString, QString);
private:
    void initGUI();
    QLineEdit*      m_configPathLE;
    QListWidget*    m_targetListWidget;
    QTextEdit*      m_targetDescriptionList;
    QString         m_configPath;
    AddToolModal*   m_addToolModal;
    QDialog*        m_toolDiag;
};

/**
 * @brief The LocalPanel class. Handles Local file operations
 */
class LocalPanel: public QWidget
{
public:
    LocalPanel(QWidget* parent = 0);
private:
    void initGUI();
};

/**
 * @brief The NetworkPanel class Handles Network Connections
 */
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
