#include "labellingarea.h"

LabellingArea::LabellingArea(QWidget *parent) : QWidget(parent)
{
    m_currentIndex = 0;
    m_isMouseDown = false;
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
        //m_imgContainer->setPixmap(*m_images.front());
        m_imageContainer->setPixmap(*m_images.front());
    }
}

void LabellingArea::mousePressEvent(QMouseEvent *event)
{
    if(!m_isMouseDown){
        m_isMouseDown = true;
        m_point1 = m_point2 = event->pos();
        m_tmpRect = QRect(m_point1, m_point2);
    }
    qDebug() << "Mouse Pressed At: " << event->pos() << endl;
}

void LabellingArea::mouseMoveEvent(QMouseEvent *event)
{
    if(m_isMouseDown){
        m_point2 = event->pos();
        m_tmpRect.setBottomRight(m_point2);
    }
}

void LabellingArea::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Mouse Released At: " << event->pos() << endl;
    if(m_isMouseDown){
        m_point2 = event->pos();
        m_isMouseDown = false;
    }
}

void LabellingArea::nextFrame()
{
    if(m_images.length() > 0 && m_currentIndex <= m_images.length() - 1){
        m_currentIndex = (m_currentIndex + 1) % m_images.length();
        ActiveRectManager::Get()->nextFrame();
        m_imageContainer->setPixmap(*m_images.at(m_currentIndex));
    }
    update();
}

void LabellingArea::previousFrame()
{
    if(m_images.length() > 0 && m_currentIndex >= 0){
        m_currentIndex = (m_currentIndex - 1) % m_images.length();
        ActiveRectManager::Get()->previousFrame();
        m_imageContainer->setPixmap(*m_images.at(m_currentIndex));
    }
    update();
}

void LabellingArea::initGUI()
{
    m_imageContainer = new ImageContainer(this);
    m_imageContainer->setAlignment(Qt::AlignCenter);

    auto centralLayout = new QVBoxLayout;
    centralLayout->addWidget(m_imageContainer);
    setLayout(centralLayout);
}
