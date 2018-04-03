#ifndef CHOOSECOURSEDIALOG_H
#define CHOOSECOURSEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QMovie>
#include <QStandardItemModel>
#include <httpop.h>

namespace Ui {
class ChooseCourseDialog;
}

class ChooseCourseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseCourseDialog(QString id,QWidget *parent = 0);
    ~ChooseCourseDialog();
    void get_courselist(QString id);
	void get_studentlist(int course_id);
    void show_courselist();

    QStandardItemModel* course_model;//表格显示内容

    QString teacher_name;//教师名字
    int course_id;//选中的课程id
	QString course_name;//选中的课程名
	QString course_time;//选中的课程时间

	QLabel *load_view;

private slots:
    void on_btn_test_clicked();
    void get_teacher_info(QString id);
    void slot_requestTeacherFinished(bool bSuccess, QNetworkReply &strResult);//结果处理
    void slot_requestCourseFinished(bool bSuccess, QNetworkReply &strResult);//结果处理
	void slot_requestStudentFinished(bool, QNetworkReply&);

	
private:
    Ui::ChooseCourseDialog *ui;
};

#endif // CHOOSECOURSEDIALOG_H
