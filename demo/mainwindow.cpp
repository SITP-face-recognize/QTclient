
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "frame_sign.h"
#include "frame_query.h"
#include "frame_stumanage.h"
#include "frame_manual_sign.h"
#include "choosecoursedialog.h"
#include "login_dialog.h"

#include <QLayout>
#include <QPainter>
#include <QPainterPath>
#include <QtMath>
#include <QtUiTools\QUiLoader>
#include <QPushButton>
#include <QLabel>
#include <QTextCodec>
#define shadow_width 6

MainWindow::MainWindow(QString teacherId,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

    // FramelessWindowHint属性设置窗口去除边框;
    // WindowMinimizeButtonHint 属性设置在窗口最小化时，点击任务栏窗口可以显示出原窗口;
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);    //设置窗体透明

    this->setFixedWidth(600);
    this->setFixedHeight(400);
	initTitleBar();

    this->teacher_id=teacherId;//获得输入老师id

    this->tabWidget = new TabWidget(Qt::Horizontal);
    tabWidget->setTabPosition(QTabWidget::West);
    tabWidget->move(shadow_width,32);

    //选择课程
    tabWidget->hide();
    tabWidget->tabBar()->setStyleSheet(QString("font:17pt"));
    tabWidget->setParent(this);
    tabWidget->resize(this->width()-2*shadow_width,this->height()-26-2*shadow_width);

  //  ui->mainLayout->addWidget(tabWidget);
    QObject::connect(tabWidget,SIGNAL(currentChanged(int)),this,SLOT(on_tabwidget_currentChanged(int)));

    ChooseCourseDialog *cc_dialog=new ChooseCourseDialog(teacherId);
    if(cc_dialog->exec()==QDialog::Accepted)
    {
        this->course_id=cc_dialog->course_id;
		Course_Id = this->course_id;
		this->course_name = cc_dialog->course_name;
		this->course_time = cc_dialog->course_time;
		
        tabWidget->show();
        qDebug()<<course_id;
    }

    Frame_sign * fs=new Frame_sign;
    fs->setStyleSheet("backgroud:white;");
    tabWidget->addTab(fs,QIcon(":/assets/img/face_sign.png"), QString(tr("学生签到")));

    Frame_query *fq=new Frame_query(course_id);
    tabWidget->addTab(fq,QIcon(":/assets/img/query.png"),QString(tr("信息查询")));

    Frame_stuManage *fm=new Frame_stuManage;
    tabWidget->addTab(fm,QIcon(":/assets/img/stumanage.png"),QString(tr("学生管理")));

    Frame_manual_sign *fms=new Frame_manual_sign;
    tabWidget->addTab(fms,QIcon(":/assets/img/manual_sign.png"),QString(tr("手动签到")));

	view_course = new QWidget(this);
	view_course->setFixedWidth(100);
	view_course->setFixedHeight(80);
	view_course->move(20, 230);
	cur_course = new QLabel(view_course);
	cur_course->setText("当前课程:\n" + this->course_name+"\n"+this->course_time);
	cur_course->setStyleSheet("color:white;");

    change_course=new QPushButton(this);
    change_course->setIcon(QIcon(":/assets/img/change_course.png"));
    change_course->setText("切换课程");
    change_course->setStyleSheet("QPushButton{border: none;border-radius:0px;background:#00a99d;}QPushButton::hover{background: #65dbdb;}");
    change_course->move(20,310);
    QObject::connect(change_course,SIGNAL(clicked()),this,SLOT(on_change_course_clicked()));

    change_login=new QPushButton(this);
    change_login->setIcon(QIcon(":/assets/img/change_login.png"));
    change_login->setText("log out");
    change_login->setStyleSheet("QPushButton{border: none;border-radius:0px;background:#00a99d;}QPushButton::hover{background: #65dbdb;}");
    change_login->move(20,340);
    QObject::connect(change_login,SIGNAL(clicked()),this,SLOT(on_change_login_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::initTitleBar()
{   m_titleBar = new TitleBar(this);
    installEventFilter(m_titleBar);

    setWindowTitle("人脸识别课堂签到系统");
    setWindowIcon(QIcon(":/assets/img/face_sign.png"));

    m_titleBar->setTitleContent("人脸识别课堂签到系统");
    m_titleBar->setTitleWidth(this->width()-2*shadow_width);
    m_titleBar->move(shadow_width,2);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);  //设置反锯齿

    for (int i = 0; i <10; i++)   //绘制阴影

    {

        painter.setPen(QColor(0,0,0,0));

        painter.setBrush(QColor(0,0,0,10 + i));

        painter.drawRoundedRect(i,i,this->width() - 2 * i,this->height() - 2 * i,10,10);

    }

    painter.setPen(QColor("#00a99d"));

    painter.setBrush(QColor("#00a99d"));

    painter.drawRoundedRect(shadow_width,shadow_width,this->width()-2*shadow_width,this->height()-2*shadow_width,0,0);
}


void MainWindow::on_change_course_clicked()
{   
    this->hide();
    ChooseCourseDialog *cc_dialog=new ChooseCourseDialog(this->teacher_id);
    if(cc_dialog->exec()==QDialog::Accepted)
    {
		this->course_id = cc_dialog->course_id;
		this->course_name = cc_dialog->course_name;
		this->course_time = cc_dialog->course_time;
		this->cur_course->setText("当前课程:\n" + this->course_name + "\n" + this->course_time);
		this->tabWidget->setCurrentIndex(0);
		this->show();
    }
	else this->close();
}

void MainWindow::on_change_login_clicked()
{
    this->hide();
    Login_Dialog *dialog=new Login_Dialog();
    if(dialog->exec()==QDialog::Accepted)
    {
        teacher_id=dialog->teacher_id;
        ChooseCourseDialog *cc_dialog=new ChooseCourseDialog(this->teacher_id);
        if(cc_dialog->exec()==QDialog::Accepted)
        {
			this->course_id = cc_dialog->course_id;
			this->course_name = cc_dialog->course_name;
			this->course_time = cc_dialog->course_time;
			this->cur_course->setText("当前课程:\n" + this->course_name + "\n" + this->course_time);
			this->tabWidget->setCurrentIndex(0);
			this->show();
        }
		else this->close();

    }
    //this->tabWidget->show();
  
}

void MainWindow::on_tabwidget_currentChanged(int index)
{
        qDebug()<<"current index:"<<index;
        if(index!=0){
            ;
        }
}
