#ifndef ACTIVERECTMANAGER_H
#define ACTIVERECTMANAGER_H


#include <QVector>
#include <QRect>

struct RectInfo{
  QString name;
  QString color;
  int index;
  QRect rect;
  RectInfo(){

  }

  RectInfo(int index, QString name, QString color, QRect rect){
      this->index = index;
      this->name = name;
      this->color = color;
      this->rect = rect;
  }
};

struct RectFrame{
    QVector<RectInfo> m_info;
};

class ActiveRectManager
{
public:
    ActiveRectManager();
    static ActiveRectManager* Instance;
    static ActiveRectManager* Get();

    void addRect(int index, QString name, QString color, QRect rect);

    void nextFrame();
    void previousFrame();

    QVector<QRect> GetCurrentRects()const;
private:
    QVector<RectFrame> m_frames;
    int m_currentIndex;
};

#endif // ACTIVERECTMANAGER_H
