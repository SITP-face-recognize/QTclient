#ifndef CHOOSECOURSEDIALOG_H
#define CHOOSECOURSEDIALOG_H

#include <QDialog>

namespace Ui {
class ChooseCourseDialog;
}

class ChooseCourseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseCourseDialog(QString id,QWidget *parent = 0);
    ~ChooseCourseDialog();
    void getcourselist(QString id);
    QString course;//这里先假设课程为STRING类型，只是用来表示，待修改

private slots:
    void on_btn_test_clicked();
    void get_teacher_info(QString id);

private:
    Ui::ChooseCourseDialog *ui;
};

#endif // CHOOSECOURSEDIALOG_H
