/********************************************************************************
** Form generated from reading UI file 'frame_query.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAME_QUERY_H
#define UI_FRAME_QUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frame_query
{
public:
    QPushButton *query_by_course;
    QTableView *courseSign;
    QTableView *signInfo;
    QLabel *signedNum;
    QLabel *unSignedNum;

    void setupUi(QWidget *Frame_query)
    {
        if (Frame_query->objectName().isEmpty())
            Frame_query->setObjectName(QStringLiteral("Frame_query"));
        Frame_query->resize(493, 320);
        query_by_course = new QPushButton(Frame_query);
        query_by_course->setObjectName(QStringLiteral("query_by_course"));
        query_by_course->setGeometry(QRect(10, 10, 151, 31));
        courseSign = new QTableView(Frame_query);
        courseSign->setObjectName(QStringLiteral("courseSign"));
        courseSign->setGeometry(QRect(10, 50, 211, 231));
        signInfo = new QTableView(Frame_query);
        signInfo->setObjectName(QStringLiteral("signInfo"));
        signInfo->setGeometry(QRect(230, 50, 221, 231));
        signedNum = new QLabel(Frame_query);
        signedNum->setObjectName(QStringLiteral("signedNum"));
        signedNum->setGeometry(QRect(230, 10, 101, 16));
        unSignedNum = new QLabel(Frame_query);
        unSignedNum->setObjectName(QStringLiteral("unSignedNum"));
        unSignedNum->setGeometry(QRect(230, 30, 111, 16));

        retranslateUi(Frame_query);

        QMetaObject::connectSlotsByName(Frame_query);
    } // setupUi

    void retranslateUi(QWidget *Frame_query)
    {
        Frame_query->setWindowTitle(QApplication::translate("Frame_query", "Form", nullptr));
        query_by_course->setText(QApplication::translate("Frame_query", "\346\234\254\345\255\246\346\234\237\346\257\217\346\254\241\350\257\276\345\207\272\345\213\244\346\246\202\350\247\210", nullptr));
        signedNum->setText(QApplication::translate("Frame_query", "\347\255\276\345\210\260\344\272\272\346\225\260:", nullptr));
        unSignedNum->setText(QApplication::translate("Frame_query", "\347\274\272\345\213\244\344\272\272\346\225\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frame_query: public Ui_Frame_query {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAME_QUERY_H
