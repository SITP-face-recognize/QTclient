#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QTabBar>

#include <QPushButton>
#include "tabwidget.h"
#include "mytitlebar.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString id,QWidget *parent = 0);
    ~MainWindow();

    QString teacher_id;//当前老师工号
    QString course;//这里先假设课程为STRING类型，只是用来表示，待修改,和choosecoursedialog.h的中定义一样
    TabWidget * tabWidget ;
    //添加数据成员，当前课程

    QPushButton * change_course;
    QPushButton * change_login;

    TitleBar* m_titleBar;

private slots:
   void on_change_course_clicked();//按钮绑定的槽函数
   void on_change_login_clicked();
   void on_tabwidget_currentChanged(int);//切换页面的槽函数

private:
    Ui::MainWindow *ui;
    void initTitleBar();
};

#endif // MAINWINDOW_H
