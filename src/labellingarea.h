#ifndef LABELLINGAREA_H
#define LABELLINGAREA_H

#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QVector>
#include <QVBoxLayout>

class LabellingArea : public QWidget
{
    Q_OBJECT
public:
    explicit LabellingArea(QWidget *parent = 0);
    ~LabellingArea();
    void addImage(QString path);
signals:

public slots:
    void nextFrame();
    void previousFrame();
private:
    void initGUI();
    QLabel *m_imgContainer;
    QVector<QPixmap*> m_images;
    unsigned int    m_currentIndex;
};

#endif // LABELLINGAREA_H
