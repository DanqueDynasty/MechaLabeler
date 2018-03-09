#include "settingswindow.h"

/*
_______  _______ ___________________________ _        _______  _______
(  ____ \(  ____ \\__   __/\__   __/\__   __/( (    /|(  ____ \(  ____ \
| (    \/| (    \/   ) (      ) (      ) (   |  \  ( || (    \/| (    \/
| (_____ | (__       | |      | |      | |   |   \ | || |      | (_____
(_____  )|  __)      | |      | |      | |   | (\ \) || | ____ (_____  )
     ) || (         | |      | |      | |   | | \   || | \_  )      ) |
/\____) || (____/\   | |      | |   ___) (___| )  \  || (___) |/\____) |
\_______)(_______/   )_(      )_(   \_______/|/    )_)(_______)\_______)

*/

SettingsWindow::SettingsWindow()
{
    initGUI();
}

void SettingsWindow::initGUI()
{
    this->setWindowTitle("Preferences");
    m_prefOptions = new QListWidget(this);              //TODO Prettify this
    m_prefOptions->addItem("Tool");
    m_prefOptions->addItem("Local");
    m_prefOptions->addItem("Network");

    m_toolPanel = new ToolPanel(this);
    m_localPanel = new LocalPanel(this);
    m_networkPanel = new NetworkPanel(this);

    auto stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(m_toolPanel);
    stackedWidget->addWidget(m_localPanel);
    stackedWidget->addWidget(m_networkPanel);
    stackedWidget->setCurrentIndex(0);
    auto splitter = new QSplitter(this);
    splitter->addWidget(m_prefOptions);
    splitter->addWidget(stackedWidget);

    auto okBtn = new QPushButton("Ok", this);
    auto applyBtn = new QPushButton("Apply", this);
    auto cancelBtn = new QPushButton("Cancel", this);

    auto btnLayout = new QHBoxLayout;
    btnLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    btnLayout->addWidget(okBtn);
    btnLayout->addWidget(applyBtn);
    btnLayout->addWidget(cancelBtn);

    auto centralLayout = new QVBoxLayout;
    centralLayout->addWidget(splitter);
    centralLayout->addLayout(btnLayout);
    setLayout(centralLayout);

    connect(m_prefOptions, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));
}
/*
_________ _______  _______  _        _______
\__   __/(  ___  )(  ___  )( \      (  ____ \
   ) (   | (   ) || (   ) || (      | (    \/
   | |   | |   | || |   | || |      | (_____
   | |   | |   | || |   | || |      (_____  )
   | |   | |   | || |   | || |            ) |
   | |   | (___) || (___) || (____/\/\____) |
   )_(   (_______)(_______)(_______/\_______)
*/
ToolPanel::ToolPanel(QWidget *parent) : QWidget(parent)
{
    initGUI();
}

/**
 * @brief ToolPanel::addTarget
 */
void ToolPanel::addTarget()
{
    qDebug() << "Adding Target" << endl;
    m_toolDiag->show();
}

/**
 * @brief ToolPanel::remTarget
 */
void ToolPanel::remTarget()
{
    int index = m_targetListWidget->currentRow();
}

/**
 * @brief ToolPanel::assignConfigPath
 */
void ToolPanel::assignConfigPath()
{
    auto path = QFileDialog::getOpenFileName(this, "Config file", QDir::currentPath(), "*.mconfig");
    m_configPathLE->setText(path);
    m_configPath = path;
}

void ToolPanel::addNewTool(int index, QString name, QString color)
{
    auto targetDescription = TargetDescription();
    targetDescription.index = index;
    targetDescription.name = name;
    targetDescription.color = color;
    m_targetDecriptions.push_back(targetDescription);
    m_targetListWidget->addItem(name);
}

/**
 * @brief ToolPanel::initGUI
 * Generates the UI for Tools Panel
 */
void ToolPanel::initGUI()
{
    auto configPathLbl = new QLabel("ConfigPath", this);
    m_configPathLE = new QLineEdit(this);
    auto pathBtn = new QPushButton("[*]", this);

    auto configLayout = new QHBoxLayout;
    configLayout->addWidget(configPathLbl);
    configLayout->addWidget(m_configPathLE);
    configLayout->addWidget(pathBtn);

    m_targetListWidget = new QListWidget(this);
    m_targetListWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    auto addTargetBtn = new QPushButton("[+]", this);
    addTargetBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    auto remTargetBtn = new QPushButton("[-]", this);
    remTargetBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    auto btnLayout0 = new QHBoxLayout;
    btnLayout0->addWidget(addTargetBtn);
    btnLayout0->addWidget(remTargetBtn);

    auto leftListLayout = new QVBoxLayout;
    leftListLayout->addWidget(new QLabel("Targets:", this));
    leftListLayout->addWidget(m_targetListWidget);
    leftListLayout->addLayout(btnLayout0);

    m_targetDescriptionList = new QTextEdit(this);

    auto targetLayout = new QHBoxLayout;
    targetLayout->addLayout(leftListLayout);
    targetLayout->addWidget(m_targetDescriptionList);

    auto centralLayout = new QVBoxLayout;
    centralLayout->addLayout(configLayout);
    centralLayout->addLayout(targetLayout);
    centralLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

    m_addToolModal = new AddToolModal(this);
    m_toolDiag = new QDialog(this);
    auto hLayout = new QHBoxLayout;
    hLayout->addWidget(m_addToolModal);
    m_toolDiag->setLayout(hLayout);
    m_toolDiag->setModal(true);

    connect(addTargetBtn, SIGNAL(clicked(bool)), SLOT(addTarget()));
    connect(remTargetBtn, SIGNAL(clicked(bool)), SLOT(remTarget()));
    connect(m_addToolModal, SIGNAL(newToolEmitted(int,QString,QString)), SLOT(addNewTool(int,QString,QString)));
    connect(pathBtn, SIGNAL(clicked(bool)), SLOT(assignConfigPath()));

    setLayout(centralLayout);
}
/*
_        _______  _______  _______  _
( \      (  ___  )(  ____ \(  ___  )( \
| (      | (   ) || (    \/| (   ) || (
| |      | |   | || |      | (___) || |
| |      | |   | || |      |  ___  || |
| |      | |   | || |      | (   ) || |
| (____/\| (___) || (____/\| )   ( || (____/\
(_______/(_______)(_______/|/     \|(_______/
*/
LocalPanel::LocalPanel(QWidget *parent) : QWidget(parent)
{
    initGUI();
}

void LocalPanel::initGUI()
{
    auto pathLbl = new QLabel("Path: ", this);
    m_pathLE = new QLineEdit(this);
    auto pathBtn = new QPushButton("...", this);

    auto pathLayout = new QHBoxLayout;
    pathLayout->addWidget(pathLbl);
    pathLayout->addWidget(m_pathLE);
    pathLayout->addWidget(pathBtn);

    auto centralLayout = new QVBoxLayout;
    centralLayout->addLayout(pathLayout);
    centralLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    setLayout(centralLayout);
}

/*
 _        _______ _________          _______  _______  _
( (    /|(  ____ \\__   __/|\     /|(  ___  )(  ____ )| \    /\
|  \  ( || (    \/   ) (   | )   ( || (   ) || (    )||  \  / /
|   \ | || (__       | |   | | _ | || |   | || (____)||  (_/ /
| (\ \) ||  __)      | |   | |( )| || |   | ||     __)|   _ (
| | \   || (         | |   | || || || |   | || (\ (   |  ( \ \
| )  \  || (____/\   | |   | () () || (___) || ) \ \__|  /  \ \
|/    )_)(_______/   )_(   (_______)(_______)|/   \__/|_/    \/

*/
NetworkPanel::NetworkPanel(QWidget *parent) : QWidget(parent)
{
    initGUI();
}

void NetworkPanel::initGUI()
{

}

AddToolModal::AddToolModal(QWidget *parent)
{
    m_targetNameLE = new QLineEdit(this);
    m_indexLE = new QLineEdit(this);
    m_colorCMBX = new QComboBox(this);
    m_colorCMBX->addItem("Red");
    m_colorCMBX->addItem("Green");
    m_colorCMBX->addItem("Blue");
    m_colorCMBX->addItem("Orange");
    m_colorCMBX->addItem("Yellow");
    m_colorCMBX->addItem("Purple");

    auto addBtn = new QPushButton("Add", this);
    auto cancelBtn = new QPushButton("Cancel", this);

    auto infoLayout = new QHBoxLayout;
    infoLayout->addWidget(new QLabel("Index: ", this));
    infoLayout->addWidget(m_indexLE);
    infoLayout->addWidget(new QLabel("Name: ", this));
    infoLayout->addWidget(m_targetNameLE);
    infoLayout->addWidget(m_colorCMBX);

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Minimum));
    buttonLayout->addWidget(addBtn);
    buttonLayout->addWidget(cancelBtn);

    auto centralLayout = new QVBoxLayout;
    centralLayout->addLayout(infoLayout);
    centralLayout->addLayout(buttonLayout);
    connect(addBtn, SIGNAL(clicked(bool)), SLOT(processNewTool()));

    setLayout(centralLayout);
}

/**
 * @brief AddToolModal::processNewTool
 * Emits new event
 */
void AddToolModal::processNewTool()
{
    auto ind = m_indexLE->text().toInt();
    auto name = m_targetNameLE->text();
    auto color = m_colorCMBX->currentText();
    emit newToolEmitted(ind, name, color);
    close();
}
