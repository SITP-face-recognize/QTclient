#include "choosecoursedialog.h"
#include "ui_choosecoursedialog.h"

ChooseCourseDialog::ChooseCourseDialog(QString id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseCourseDialog)
{
    ui->setupUi(this);
    this->get_teacher_info(id);
    this->getcourselist(id);
}

ChooseCourseDialog::~ChooseCourseDialog()
{
    delete ui;
}

void ChooseCourseDialog::getcourselist(QString id)
{
    //根据老师id获取课程列表

}

void ChooseCourseDialog::on_btn_test_clicked()
{
    //获取选中的信息
    course=QString("beg you");
    accept();
}

void ChooseCourseDialog::get_teacher_info(QString id)
{
    ui->lb_id_pro->setText(id);
    //应查询后台
    ui->lb_name_pro->setText(QString(tr("王老师")));
}
