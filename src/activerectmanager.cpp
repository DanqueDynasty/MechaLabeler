#include "activerectmanager.h"

ActiveRectManager* ActiveRectManager::Instance = nullptr;

ActiveRectManager::ActiveRectManager()
{
    m_currentIndex = 0;
    m_frames.push_back(RectFrame());
}

ActiveRectManager *ActiveRectManager::Get()
{
    if(Instance == nullptr){
        Instance = new ActiveRectManager();
    }
    return Instance;
}

void ActiveRectManager::addRect(int index, QString name, QString color, QRect rect)
{
    m_frames[m_currentIndex].m_info.push_back(RectInfo(index, name, color, rect));
}

void ActiveRectManager::nextFrame()
{
    m_currentIndex++;
    if(m_currentIndex == m_frames.length()){
        m_frames.push_back(RectFrame());
    }
}

void ActiveRectManager::previousFrame()
{
    if(m_currentIndex > 0){
        m_currentIndex--;
    }
}

QVector<QRect> ActiveRectManager::GetCurrentRects() const
{
    QVector<QRect> ret;
    auto rects = m_frames[m_currentIndex].m_info;
    for(int j = 0, J = rects.length(); j < J; j++){
        ret.push_back(rects[j].rect);
    }
    return ret;
}
