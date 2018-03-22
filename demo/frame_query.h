#ifndef FRAME_QUERY_H
#define FRAME_QUERY_H

#include <QWidget>

namespace Ui {
class Frame_query;
}

class Frame_query : public QWidget
{
    Q_OBJECT

public:
    explicit Frame_query(QWidget *parent = 0);
    ~Frame_query();
    int weeknum;//周数，例如“第2周”即2
    QString order;//每一周内的上课时间，如“周二 3 4节（双）”，类型待定
    QString stuid;//学生学号

private slots:
    void on_btn_submit_clicked();//点击查询按钮绑定的槽函数
    void on_query_by_course_clicked();
    void on_query_by_stu_clicked();

    void query_all_by_course();//查询本学期每次课出勤状况
    void query_all_by_student();//查询本学期所有学生出勤情况
    void query_by_time(int weeknum,QString order,QString stuid=0);//根据三个条件查询

private:
    Ui::Frame_query *ui;
};

#endif // FRAME_QUERY_H
