#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "frame_sign.h"
#include "frame_query.h"
#include "frame_stumanage.h"
#include "frame_manual_sign.h"
#include "choosecoursedialog.h"

#include <QLayout>
#include <QtUiTools\QUiLoader>
#include <QPushButton>

MainWindow::MainWindow(QString id,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->teacher_id=id;

    this->tabWidget = new TabWidget(Qt::Horizontal);
    tabWidget->setTabPosition(QTabWidget::West);

    Frame_sign * fs=new Frame_sign;
    fs->show();
    tabWidget->addTab(fs, QString(tr("学生签到")));

    Frame_query *fq=new Frame_query;
    fq->show();
    tabWidget->addTab(fq,QString(tr("信息查询")));

    Frame_stuManage *fm=new Frame_stuManage;
    tabWidget->addTab(fm,QString(tr("学生管理")));

    Frame_manual_sign *fms=new Frame_manual_sign;
    tabWidget->addTab(fms,QString(tr("手动签到")));


    tabWidget->tabBar()->setStyleSheet(QString("font:17pt"));
    tabWidget->setParent(this);

    QPushButton change_course;
    change_course.setText("切换课程");
    change_course.setParent(this);
    QObject::connect(&change_course,SIGNAL(clicked()),this,SLOT(on_change_course_clicked()));

    tabWidget->hide();

    ChooseCourseDialog *cc_dialog=new ChooseCourseDialog(id);
    if(cc_dialog->exec()==QDialog::Accepted)
    {
        course=cc_dialog->course;
        tabWidget->show();
        qDebug()<<course;
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
        this->tabWidget->show();
    }
}
