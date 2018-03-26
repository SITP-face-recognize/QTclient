#include "mainwindow.h"
#include "login_dialog.h"

#include <QApplication>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Login_Dialog ld;
    if(ld.exec()==QDialog::Accepted)
       {
            MainWindow w(ld.teacher_id);
            w.show();
            return a.exec();
       }
       else return 0;
}
