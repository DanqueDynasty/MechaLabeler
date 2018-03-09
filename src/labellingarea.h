#ifndef LABELLINGAREA_H
#define LABELLINGAREA_H

#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QVector>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>

#include "imagecontainer.h"
#include "activerectmanager.h"

class LabellingArea : public QWidget
{
    Q_OBJECT
public:
    explicit LabellingArea(QWidget *parent = 0);
    ~LabellingArea();
    void addImage(QString path);
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
signals:

public slots:
    void nextFrame();
    void previousFrame();
private:
    void initGUI();
    bool m_isMouseDown;
    QLabel *m_imgContainer;
    ImageContainer* m_imageContainer;
    QVector<QPixmap*> m_images;
    unsigned int    m_currentIndex;
    QPoint m_point1;
    QPoint m_point2;
    QRect  m_tmpRect;
};

#endif // LABELLINGAREA_H
