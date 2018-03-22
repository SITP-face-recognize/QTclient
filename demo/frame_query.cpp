#include "frame_query.h"
#include "ui_frame_query.h"

Frame_query::Frame_query(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Frame_query)
{
    ui->setupUi(this);


}

Frame_query::~Frame_query()
{
    delete ui;
}

void Frame_query::on_btn_submit_clicked()
{

}

void Frame_query::on_query_by_course_clicked()
{

}

void Frame_query::on_query_by_stu_clicked()
{

}

void Frame_query::query_all_by_course()
{

}

void Frame_query::query_all_by_student()
{

}

void Frame_query::query_by_time(int weeknum, QString order, QString stuid)
{

}
