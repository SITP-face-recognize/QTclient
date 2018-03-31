/********************************************************************************
** Form generated from reading UI file 'choosecoursedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSECOURSEDIALOG_H
#define UI_CHOOSECOURSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ChooseCourseDialog
{
public:
    QGroupBox *view_choose_course;
    QLabel *lb_id_pro;
    QLabel *lb_name_pro;
    QPushButton *btn_test;
    QTableView *tableView;
    QLabel *noChoiceWarning;

    void setupUi(QDialog *ChooseCourseDialog)
    {
        if (ChooseCourseDialog->objectName().isEmpty())
            ChooseCourseDialog->setObjectName(QStringLiteral("ChooseCourseDialog"));
        ChooseCourseDialog->resize(310, 400);
        view_choose_course = new QGroupBox(ChooseCourseDialog);
        view_choose_course->setObjectName(QStringLiteral("view_choose_course"));
        view_choose_course->setGeometry(QRect(10, 30, 281, 321));
        lb_id_pro = new QLabel(view_choose_course);
        lb_id_pro->setObjectName(QStringLiteral("lb_id_pro"));
        lb_id_pro->setGeometry(QRect(80, 30, 61, 16));
        lb_id_pro->setTextFormat(Qt::AutoText);
        lb_id_pro->setAlignment(Qt::AlignCenter);
        lb_name_pro = new QLabel(view_choose_course);
        lb_name_pro->setObjectName(QStringLiteral("lb_name_pro"));
        lb_name_pro->setGeometry(QRect(150, 30, 61, 20));
        lb_name_pro->setTextFormat(Qt::AutoText);
        lb_name_pro->setAlignment(Qt::AlignCenter);
        btn_test = new QPushButton(view_choose_course);
        btn_test->setObjectName(QStringLiteral("btn_test"));
        btn_test->setGeometry(QRect(100, 240, 81, 23));
        tableView = new QTableView(view_choose_course);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(40, 60, 201, 171));
        noChoiceWarning = new QLabel(view_choose_course);
        noChoiceWarning->setObjectName(QStringLiteral("noChoiceWarning"));
        noChoiceWarning->setGeometry(QRect(90, 270, 111, 16));
        noChoiceWarning->setTextFormat(Qt::AutoText);
        noChoiceWarning->setAlignment(Qt::AlignCenter);

        retranslateUi(ChooseCourseDialog);

        QMetaObject::connectSlotsByName(ChooseCourseDialog);
    } // setupUi

    void retranslateUi(QDialog *ChooseCourseDialog)
    {
        ChooseCourseDialog->setWindowTitle(QApplication::translate("ChooseCourseDialog", "\344\272\272\350\204\270\350\257\206\345\210\253\347\255\276\345\210\260-\351\200\211\346\213\251\350\257\276\347\250\213", nullptr));
        view_choose_course->setTitle(QApplication::translate("ChooseCourseDialog", "\351\200\211\346\213\251\350\257\276\347\250\213", nullptr));
        lb_id_pro->setText(QString());
        lb_name_pro->setText(QString());
        btn_test->setText(QApplication::translate("ChooseCourseDialog", "\347\241\256\350\256\244\350\277\233\345\205\245", nullptr));
        noChoiceWarning->setText(QApplication::translate("ChooseCourseDialog", "\350\257\267\351\200\211\346\213\251\350\257\276\347\250\213\345\206\215\347\241\256\345\256\232!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseCourseDialog: public Ui_ChooseCourseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSECOURSEDIALOG_H
