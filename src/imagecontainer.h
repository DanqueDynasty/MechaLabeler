#ifndef IMAGECONTAINER_H
#define IMAGECONTAINER_H

#include <QImage>
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include <QMouseEvent>
#include "activerectmanager.h"

class ImageContainer : public QLabel
{
    Q_OBJECT
public:
    ImageContainer(QWidget* parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev)override;
    void paintEvent(QPaintEvent *ev) override;
private:
    bool m_isMouseDown;
    QPoint m_point1;
    QPoint m_point2;
    QRect  m_tmpRect;
    QVector<QRect> m_drawnRects;
};

#endif // IMAGECONTAINER_H
