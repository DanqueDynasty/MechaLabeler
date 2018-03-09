#include "imagecontainer.h"

ImageContainer::ImageContainer(QWidget *parent) : QLabel(parent)
{
    m_isMouseDown = false;
}

void ImageContainer::mousePressEvent(QMouseEvent *ev)
{
    if(!m_isMouseDown){
        m_isMouseDown = true;
        m_point1 = m_point2 = ev->pos();
        m_tmpRect = QRect(m_point1, m_point2);
        update();
    }
}

void ImageContainer::mouseMoveEvent(QMouseEvent *ev)
{
    if(m_isMouseDown){
        m_point2 = ev->pos();
        m_tmpRect.setBottomRight(ev->pos());
        update();
    }
}

void ImageContainer::mouseReleaseEvent(QMouseEvent *ev)
{
    if(m_isMouseDown){
        m_isMouseDown = false;
        m_point2 = ev->pos();
        m_tmpRect.setBottomRight(ev->pos());
        ActiveRectManager::Get()->addRect(0, "Test", "Test", m_tmpRect);
        //m_drawnRects.push_back(m_tmpRect);
        m_tmpRect = QRect(0, 0, 0, 0);
        update();
    }
}

void ImageContainer::paintEvent(QPaintEvent *ev)
{
    QLabel::paintEvent(ev);
    QPainter p(this);
    QPen pen(Qt::red);
    pen.setWidth(4);
    p.setPen(pen);
    p.setBrush(Qt::transparent);
    if(m_tmpRect.top() != 0 && m_tmpRect.left() != 0 && m_tmpRect.right() != 0) p.drawRect(m_tmpRect);

    for(auto rects : ActiveRectManager::Get()->GetCurrentRects()){
        p.drawRect(rects);
    }
}
