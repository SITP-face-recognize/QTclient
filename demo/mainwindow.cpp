#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "frame_sign.h"
#include "frame_query.h"
#include "frame_stumanage.h"
#include "frame_manual_sign.h"
#include "choosecoursedialog.h"

#include <QFile>
#include <QLayout>

MainWindow::MainWindow(QString id,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->teacher_id=id;

    this->tabWidget = new TabWidget(Qt::Horizontal);

    QFile f(":/assets/StyleSheet.css");
    if (f.open(QIODevice::ReadOnly)) {
   //     tabWidget->setStyleSheet(f.readAll());
        f.close();
    }
    //this->setStyleSheet("backgroud:#00a99d;");

    tabWidget->setTabPosition(QTabWidget::West);

    //选择课程


    Frame_sign * fs=new Frame_sign;
    tabWidget->addTab(fs, QString(tr("学生签到")));

    Frame_query *fq=new Frame_query;
    tabWidget->addTab(fq,QString(tr("信息查询")));

    Frame_stuManage *fm=new Frame_stuManage;
    tabWidget->addTab(fm,QString(tr("学生管理")));

    Frame_manual_sign *fms=new Frame_manual_sign;
    tabWidget->addTab(fms,QString(tr("手动签到")));


    tabWidget->tabBar()->setStyleSheet(QString("font:17pt"));
    tabWidget->setParent(this);
    QObject::connect(tabWidget,SIGNAL(currentChanged(int)),this,SLOT(on_tabwidget_currentChanged(int)));

    change_course=new QPushButton(this);
    change_course->setText("切换课程");
    change_course->move(10,300);
    QObject::connect(change_course,SIGNAL(clicked()),this,SLOT(on_change_course_clicked()));

  //  tabWidget->hide();

    ChooseCourseDialog *cc_dialog=new ChooseCourseDialog(id);
    if(cc_dialog->exec()==QDialog::Accepted)
    {
        course=cc_dialog->course;
        tabWidget->show();
        qDebug()<<course;
    }
    else{
       // tabWidget->show();
        //change_course.show();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_change_course_clicked()
{
    this->tabWidget->hide();
    ChooseCourseDialog *cc_dialog=new ChooseCourseDialog(this->teacher_id);
    if(cc_dialog->exec()==QDialog::Accepted)
    {
        course=cc_dialog->course;
    }
    this->tabWidget->show();
}

void MainWindow::on_tabwidget_currentChanged(int index)
{
        qDebug()<<"current index:"<<index;
        if(index!=0){
        //    tabWidget->setCurrentIndex(0);
        }

}
