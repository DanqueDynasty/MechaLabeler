#include "settingswindow.h"

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

void ToolPanel::initGUI()
{

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
