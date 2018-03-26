#ifndef CHOOSECOURSEDIALOG_H
#define CHOOSECOURSEDIALOG_H

#include <QNetworkReply>
#include <QDialog>
#include <QStandardItemModel>

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
    void show_courselist();

    QStandardItemModel* course_model;
    QString course;//这里先假设课程为STRING类型，只是用来表示，待修改

private slots:
    void on_btn_test_clicked();
    void get_teacher_info(QString id);
    void slot_requestFinished(bool bSuccess, QNetworkReply &strResult);//结果处理

private:
    Ui::ChooseCourseDialog *ui;
};

#endif // CHOOSECOURSEDIALOG_H
