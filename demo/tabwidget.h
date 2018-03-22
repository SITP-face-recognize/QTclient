#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include <QTabBar>
#include <tabstyle.h>

class TabWidget : public QTabWidget
{
public:
    explicit TabWidget(Qt::Orientation orientation, QWidget * parent = 0)
        : QTabWidget(parent)
    {
        QTabBar * tabBar = new QTabBar;
        tabBar->setStyle(new TabStyle(orientation));
        setTabBar(tabBar);
    }
};

#endif // TABWIDGET_H
