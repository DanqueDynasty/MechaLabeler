#include "rectmanagement.h"

RectManagement::RectManagement(QWidget* parent) : QDockWidget(parent)
{
    setWindowTitle("Labels");
    initGUI();
}

/**
 * @brief RectManagement::initGUI
 */
void RectManagement::initGUI()
{
    m_rectListWidget = new QListWidget(this);
    m_addRectBtn = new QPushButton("[+]",this);
    m_remRectBtn = new QPushButton("[-]", this);

    auto btnLayout = new QHBoxLayout;
    btnLayout->addWidget(m_addRectBtn);
    btnLayout->addWidget(m_remRectBtn);

    auto centralLayout = new QVBoxLayout;
    centralLayout->addWidget(m_rectListWidget);
    centralLayout->addLayout(btnLayout);
    centralLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

    auto centralWidget = new QWidget(this);
    centralWidget->setLayout(centralLayout);
    setWidget(centralWidget);
}
