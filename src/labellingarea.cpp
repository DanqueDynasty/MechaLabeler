#include "labellingarea.h"

LabellingArea::LabellingArea(QWidget *parent) : QWidget(parent)
{
    m_currentIndex = 0;
    initGUI();
}

LabellingArea::~LabellingArea()
{
    m_images.clear();
}

void LabellingArea::addImage(QString path)
{
    m_images.push_back(new QPixmap(path));
    if(m_images.length() > 0){
        m_imgContainer->setPixmap(*m_images.front());
    }
}

void LabellingArea::nextFrame()
{
    if(m_images.length() > 0 && m_currentIndex <= m_images.length() - 1){
        m_currentIndex = (m_currentIndex + 1) % m_images.length();
        m_imgContainer->setPixmap(*m_images.at(m_currentIndex));
    }
}

void LabellingArea::previousFrame()
{
    if(m_images.length() > 0 && m_currentIndex >= 0){
        m_currentIndex = (m_currentIndex + 1) % m_images.length();
        m_imgContainer->setPixmap(*m_images.at(m_currentIndex));
    }
}

void LabellingArea::initGUI()
{
    m_imgContainer = new QLabel("IMG Here" ,this);
    m_imgContainer->setAlignment(Qt::AlignCenter);

    auto centralLayout = new QVBoxLayout;
    centralLayout->addWidget(m_imgContainer);
    setLayout(centralLayout);
}
