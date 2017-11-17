#ifndef RECTMANAGEMENT_H
#define RECTMANAGEMENT_H


#include <QDockWidget>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

class RectManagement : public QDockWidget
{
    Q_OBJECT
public:
    RectManagement(QWidget* parent = 0);
signals:
    void indexChanged(int);

private:
    void initGUI();
    QListWidget* m_rectListWidget;
    QPushButton* m_addRectBtn;
    QPushButton* m_remRectBtn;
};

#endif // RECTMANAGEMENT_H
