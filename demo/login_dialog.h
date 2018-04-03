#ifndef LOGIN_DIALOG_H
#define LOGIN_DIALOG_H

#include "httpop.h"

#include <QDialog>
#include <QMessageBox>


namespace Ui {
class Login_Dialog;
}

class Login_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Login_Dialog(QWidget *parent = 0);
    ~Login_Dialog();
    QString teacher_id;
	int check_teacher_id(QString id, QString password);
private:
    Ui::Login_Dialog *ui;
	bool login_fail;

private slots:
    void on_btn_login_clicked();
	void slot_postFinished(bool,QNetworkReply&);
};

#endif // LOGIN_DIALOG_H
