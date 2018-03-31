/********************************************************************************
** Form generated from reading UI file 'frame_stumanage.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAME_STUMANAGE_H
#define UI_FRAME_STUMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frame_stuManage
{
public:
    QTabWidget *tabWidget;
    QWidget *stu_add;
    QWidget *view_add_input;
    QPushButton *btn_addFace;
    QLabel *tip;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *addstu_id_Label;
    QLineEdit *addstu_id_LineEdit;
    QLabel *addstu_name_Label;
    QLineEdit *addstu_name_LineEdit;
    QWidget *stu_update;
    QWidget *view_update_input;
    QPushButton *btn_updateFace;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QLineEdit *tb_id_update;
    QLabel *upstu_name_Label;
    QLabel *upstu_id_Label;
    QLabel *tip_name_update;
    QWidget *stu_delete;
    QPushButton *btn_delete;
    QWidget *widget2;
    QGridLayout *gridLayout_3;
    QLabel *destu_id_Label;
    QLineEdit *tb_id_delete;
    QLabel *destu_name_Label;
    QLabel *tip_name_delete;

    void setupUi(QWidget *Frame_stuManage)
    {
        if (Frame_stuManage->objectName().isEmpty())
            Frame_stuManage->setObjectName(QStringLiteral("Frame_stuManage"));
        Frame_stuManage->resize(492, 384);
        tabWidget = new QTabWidget(Frame_stuManage);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 461, 351));
        tabWidget->setIconSize(QSize(20, 20));
        stu_add = new QWidget();
        stu_add->setObjectName(QStringLiteral("stu_add"));
        view_add_input = new QWidget(stu_add);
        view_add_input->setObjectName(QStringLiteral("view_add_input"));
        view_add_input->setGeometry(QRect(70, 50, 201, 211));
        btn_addFace = new QPushButton(view_add_input);
        btn_addFace->setObjectName(QStringLiteral("btn_addFace"));
        btn_addFace->setGeometry(QRect(70, 160, 75, 23));
        tip = new QLabel(view_add_input);
        tip->setObjectName(QStringLiteral("tip"));
        tip->setGeometry(QRect(50, 40, 111, 21));
        widget = new QWidget(view_add_input);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 70, 181, 71));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        addstu_id_Label = new QLabel(widget);
        addstu_id_Label->setObjectName(QStringLiteral("addstu_id_Label"));

        gridLayout->addWidget(addstu_id_Label, 0, 0, 1, 1);

        addstu_id_LineEdit = new QLineEdit(widget);
        addstu_id_LineEdit->setObjectName(QStringLiteral("addstu_id_LineEdit"));

        gridLayout->addWidget(addstu_id_LineEdit, 0, 1, 1, 1);

        addstu_name_Label = new QLabel(widget);
        addstu_name_Label->setObjectName(QStringLiteral("addstu_name_Label"));

        gridLayout->addWidget(addstu_name_Label, 1, 0, 1, 1);

        addstu_name_LineEdit = new QLineEdit(widget);
        addstu_name_LineEdit->setObjectName(QStringLiteral("addstu_name_LineEdit"));

        gridLayout->addWidget(addstu_name_LineEdit, 1, 1, 1, 1);

        QIcon icon;
        icon.addFile(QStringLiteral(":/assets/img/addButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(stu_add, icon, QString());
        stu_update = new QWidget();
        stu_update->setObjectName(QStringLiteral("stu_update"));
        view_update_input = new QWidget(stu_update);
        view_update_input->setObjectName(QStringLiteral("view_update_input"));
        view_update_input->setGeometry(QRect(50, 50, 221, 201));
        btn_updateFace = new QPushButton(view_update_input);
        btn_updateFace->setObjectName(QStringLiteral("btn_updateFace"));
        btn_updateFace->setGeometry(QRect(90, 120, 75, 31));
        widget1 = new QWidget(view_update_input);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 50, 171, 51));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        tb_id_update = new QLineEdit(widget1);
        tb_id_update->setObjectName(QStringLiteral("tb_id_update"));

        gridLayout_2->addWidget(tb_id_update, 0, 1, 1, 1);

        upstu_name_Label = new QLabel(widget1);
        upstu_name_Label->setObjectName(QStringLiteral("upstu_name_Label"));

        gridLayout_2->addWidget(upstu_name_Label, 1, 0, 1, 1);

        upstu_id_Label = new QLabel(widget1);
        upstu_id_Label->setObjectName(QStringLiteral("upstu_id_Label"));

        gridLayout_2->addWidget(upstu_id_Label, 0, 0, 1, 1);

        tip_name_update = new QLabel(widget1);
        tip_name_update->setObjectName(QStringLiteral("tip_name_update"));

        gridLayout_2->addWidget(tip_name_update, 1, 1, 1, 1);

        QIcon icon1;
        icon1.addFile(QStringLiteral(":/assets/img/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(stu_update, icon1, QString());
        stu_delete = new QWidget();
        stu_delete->setObjectName(QStringLiteral("stu_delete"));
        btn_delete = new QPushButton(stu_delete);
        btn_delete->setObjectName(QStringLiteral("btn_delete"));
        btn_delete->setGeometry(QRect(140, 170, 75, 31));
        widget2 = new QWidget(stu_delete);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(80, 100, 171, 51));
        gridLayout_3 = new QGridLayout(widget2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        destu_id_Label = new QLabel(widget2);
        destu_id_Label->setObjectName(QStringLiteral("destu_id_Label"));
        destu_id_Label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(destu_id_Label, 0, 0, 1, 1);

        tb_id_delete = new QLineEdit(widget2);
        tb_id_delete->setObjectName(QStringLiteral("tb_id_delete"));

        gridLayout_3->addWidget(tb_id_delete, 0, 1, 1, 1);

        destu_name_Label = new QLabel(widget2);
        destu_name_Label->setObjectName(QStringLiteral("destu_name_Label"));

        gridLayout_3->addWidget(destu_name_Label, 1, 0, 1, 1);

        tip_name_delete = new QLabel(widget2);
        tip_name_delete->setObjectName(QStringLiteral("tip_name_delete"));

        gridLayout_3->addWidget(tip_name_delete, 1, 1, 1, 1);

        QIcon icon2;
        icon2.addFile(QStringLiteral(":/assets/img/finalNode.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(stu_delete, icon2, QString());

        retranslateUi(Frame_stuManage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Frame_stuManage);
    } // setupUi

    void retranslateUi(QWidget *Frame_stuManage)
    {
        Frame_stuManage->setWindowTitle(QApplication::translate("Frame_stuManage", "Form", nullptr));
        btn_addFace->setText(QApplication::translate("Frame_stuManage", "+ \346\267\273\345\212\240\347\205\247\347\211\207", nullptr));
        tip->setText(QApplication::translate("Frame_stuManage", "\350\257\267\350\276\223\345\205\245\345\255\246\345\217\267\345\222\214\345\247\223\345\220\215", nullptr));
        addstu_id_Label->setText(QApplication::translate("Frame_stuManage", "\345\255\246\345\217\267:", nullptr));
        addstu_name_Label->setText(QApplication::translate("Frame_stuManage", "\345\247\223\345\220\215:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(stu_add), QApplication::translate("Frame_stuManage", "\346\267\273\345\212\240\345\255\246\347\224\237", nullptr));
        btn_updateFace->setText(QApplication::translate("Frame_stuManage", "\346\233\264\346\226\260\347\205\247\347\211\207", nullptr));
        upstu_name_Label->setText(QApplication::translate("Frame_stuManage", "\345\247\223\345\220\215:", nullptr));
        upstu_id_Label->setText(QApplication::translate("Frame_stuManage", "\345\255\246\345\217\267:", nullptr));
        tip_name_update->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(stu_update), QApplication::translate("Frame_stuManage", "\346\233\264\346\226\260\345\255\246\347\224\237\347\205\247\347\211\207", nullptr));
        btn_delete->setText(QApplication::translate("Frame_stuManage", "\345\210\240\351\231\244", nullptr));
        destu_id_Label->setText(QApplication::translate("Frame_stuManage", "\345\255\246\345\217\267:", nullptr));
        destu_name_Label->setText(QApplication::translate("Frame_stuManage", "\345\247\223\345\220\215:", nullptr));
        tip_name_delete->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(stu_delete), QApplication::translate("Frame_stuManage", "\345\210\240\351\231\244\345\255\246\347\224\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frame_stuManage: public Ui_Frame_stuManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAME_STUMANAGE_H
