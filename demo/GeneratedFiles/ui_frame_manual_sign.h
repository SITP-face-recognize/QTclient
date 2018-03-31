/********************************************************************************
** Form generated from reading UI file 'frame_manual_sign.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAME_MANUAL_SIGN_H
#define UI_FRAME_MANUAL_SIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frame_manual_sign
{
public:
    QPushButton *btn_submit;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *stu_id;
    QLineEdit *tb_id;
    QLabel *stu_name;
    QLabel *tip_name;

    void setupUi(QWidget *Frame_manual_sign)
    {
        if (Frame_manual_sign->objectName().isEmpty())
            Frame_manual_sign->setObjectName(QStringLiteral("Frame_manual_sign"));
        Frame_manual_sign->resize(400, 300);
        btn_submit = new QPushButton(Frame_manual_sign);
        btn_submit->setObjectName(QStringLiteral("btn_submit"));
        btn_submit->setGeometry(QRect(170, 170, 75, 31));
        widget = new QWidget(Frame_manual_sign);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(80, 113, 195, 51));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stu_id = new QLabel(widget);
        stu_id->setObjectName(QStringLiteral("stu_id"));
        stu_id->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(stu_id, 0, 0, 1, 1);

        tb_id = new QLineEdit(widget);
        tb_id->setObjectName(QStringLiteral("tb_id"));

        gridLayout->addWidget(tb_id, 0, 1, 1, 1);

        stu_name = new QLabel(widget);
        stu_name->setObjectName(QStringLiteral("stu_name"));
        stu_name->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(stu_name, 1, 0, 1, 1);

        tip_name = new QLabel(widget);
        tip_name->setObjectName(QStringLiteral("tip_name"));

        gridLayout->addWidget(tip_name, 1, 1, 1, 1);


        retranslateUi(Frame_manual_sign);

        QMetaObject::connectSlotsByName(Frame_manual_sign);
    } // setupUi

    void retranslateUi(QWidget *Frame_manual_sign)
    {
        Frame_manual_sign->setWindowTitle(QApplication::translate("Frame_manual_sign", "Form", nullptr));
        btn_submit->setText(QApplication::translate("Frame_manual_sign", "\346\211\213\345\212\250\347\255\276\345\210\260", nullptr));
        stu_id->setText(QApplication::translate("Frame_manual_sign", "\345\255\246\345\217\267:", nullptr));
        stu_name->setText(QApplication::translate("Frame_manual_sign", "\345\247\223\345\220\215:", nullptr));
        tip_name->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Frame_manual_sign: public Ui_Frame_manual_sign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAME_MANUAL_SIGN_H
