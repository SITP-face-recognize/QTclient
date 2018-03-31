/********************************************************************************
** Form generated from reading UI file 'login_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_DIALOG_H
#define UI_LOGIN_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login_Dialog
{
public:
    QGroupBox *view_login;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *tb_id;
    QLabel *lb_id;
    QLabel *lb_password;
    QLineEdit *tb_password;
    QPushButton *btn_login;
    QLabel *logo;

    void setupUi(QDialog *Login_Dialog)
    {
        if (Login_Dialog->objectName().isEmpty())
            Login_Dialog->setObjectName(QStringLiteral("Login_Dialog"));
        Login_Dialog->resize(299, 400);
        view_login = new QGroupBox(Login_Dialog);
        view_login->setObjectName(QStringLiteral("view_login"));
        view_login->setGeometry(QRect(20, 50, 251, 301));
        view_login->setFlat(false);
        view_login->setCheckable(false);
        layoutWidget = new QWidget(view_login);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 130, 151, 81));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tb_id = new QLineEdit(layoutWidget);
        tb_id->setObjectName(QStringLiteral("tb_id"));

        gridLayout->addWidget(tb_id, 0, 1, 1, 1);

        lb_id = new QLabel(layoutWidget);
        lb_id->setObjectName(QStringLiteral("lb_id"));

        gridLayout->addWidget(lb_id, 0, 0, 1, 1);

        lb_password = new QLabel(layoutWidget);
        lb_password->setObjectName(QStringLiteral("lb_password"));

        gridLayout->addWidget(lb_password, 1, 0, 1, 1);

        tb_password = new QLineEdit(layoutWidget);
        tb_password->setObjectName(QStringLiteral("tb_password"));
        tb_password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(tb_password, 1, 1, 1, 1);

        btn_login = new QPushButton(view_login);
        btn_login->setObjectName(QStringLiteral("btn_login"));
        btn_login->setGeometry(QRect(90, 230, 75, 23));
        logo = new QLabel(view_login);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(90, 30, 81, 81));

        retranslateUi(Login_Dialog);

        QMetaObject::connectSlotsByName(Login_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Login_Dialog)
    {
        Login_Dialog->setWindowTitle(QApplication::translate("Login_Dialog", "\344\272\272\350\204\270\350\257\206\345\210\253\347\255\276\345\210\260-\347\231\273\345\275\225", nullptr));
        view_login->setTitle(QApplication::translate("Login_Dialog", "\347\231\273\345\275\225\347\263\273\347\273\237", nullptr));
        lb_id->setText(QApplication::translate("Login_Dialog", "\345\267\245\345\217\267", nullptr));
        lb_password->setText(QApplication::translate("Login_Dialog", "\345\257\206\347\240\201", nullptr));
        btn_login->setText(QApplication::translate("Login_Dialog", "\347\231\273\345\275\225", nullptr));
        logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login_Dialog: public Ui_Login_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_DIALOG_H
