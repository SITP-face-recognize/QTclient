/********************************************************************************
** Form generated from reading UI file 'Frame_sign.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAME_SIGN_H
#define UI_FRAME_SIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frame_sign
{
public:
    QWidget *view_sign;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *ImageView;
    QLabel *tip_info;
    QLabel *view_frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *RightView;
    QWidget *view_first;
    QPushButton *buttonCapture;
    QLabel *tips;
    QPushButton *buttonQuit;
    QWidget *view_start;
    QPushButton *btn_start;
    QLabel *label;

    void setupUi(QWidget *Frame_sign)
    {
        if (Frame_sign->objectName().isEmpty())
            Frame_sign->setObjectName(QStringLiteral("Frame_sign"));
        Frame_sign->resize(485, 337);
        view_sign = new QWidget(Frame_sign);
        view_sign->setObjectName(QStringLiteral("view_sign"));
        view_sign->setGeometry(QRect(10, 10, 471, 311));
        horizontalLayoutWidget = new QWidget(view_sign);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 261, 261));
        ImageView = new QHBoxLayout(horizontalLayoutWidget);
        ImageView->setObjectName(QStringLiteral("ImageView"));
        ImageView->setContentsMargins(0, 0, 0, 0);
        tip_info = new QLabel(horizontalLayoutWidget);
        tip_info->setObjectName(QStringLiteral("tip_info"));

        ImageView->addWidget(tip_info);

        view_frame = new QLabel(horizontalLayoutWidget);
        view_frame->setObjectName(QStringLiteral("view_frame"));

        ImageView->addWidget(view_frame);

        verticalLayoutWidget = new QWidget(view_sign);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(280, 20, 101, 261));
        RightView = new QVBoxLayout(verticalLayoutWidget);
        RightView->setObjectName(QStringLiteral("RightView"));
        RightView->setContentsMargins(0, 0, 0, 0);
        view_first = new QWidget(verticalLayoutWidget);
        view_first->setObjectName(QStringLiteral("view_first"));
        buttonCapture = new QPushButton(view_first);
        buttonCapture->setObjectName(QStringLiteral("buttonCapture"));
        buttonCapture->setGeometry(QRect(0, 140, 99, 23));
        tips = new QLabel(view_first);
        tips->setObjectName(QStringLiteral("tips"));
        tips->setGeometry(QRect(0, 0, 101, 141));

        RightView->addWidget(view_first);

        buttonQuit = new QPushButton(verticalLayoutWidget);
        buttonQuit->setObjectName(QStringLiteral("buttonQuit"));

        RightView->addWidget(buttonQuit);

        view_start = new QWidget(Frame_sign);
        view_start->setObjectName(QStringLiteral("view_start"));
        view_start->setGeometry(QRect(150, 90, 111, 91));
        btn_start = new QPushButton(view_start);
        btn_start->setObjectName(QStringLiteral("btn_start"));
        btn_start->setGeometry(QRect(20, 10, 71, 61));
        label = new QLabel(Frame_sign);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(440, 330, 54, 12));

        retranslateUi(Frame_sign);

        QMetaObject::connectSlotsByName(Frame_sign);
    } // setupUi

    void retranslateUi(QWidget *Frame_sign)
    {
        Frame_sign->setWindowTitle(QApplication::translate("Frame_sign", "Form", nullptr));
        tip_info->setText(QString());
        view_frame->setText(QString());
        buttonCapture->setText(QApplication::translate("Frame_sign", "\345\274\200\345\247\213\345\275\225\345\205\245", nullptr));
        tips->setText(QApplication::translate("Frame_sign", "\347\202\271\345\207\273\345\274\200\345\247\213\345\275\225\345\205\245", nullptr));
        buttonQuit->setText(QApplication::translate("Frame_sign", "\347\273\223\346\235\237\347\255\276\345\210\260", nullptr));
        btn_start->setText(QApplication::translate("Frame_sign", "\345\274\200\345\247\213\347\255\276\345\210\260", nullptr));
        label->setText(QApplication::translate("Frame_sign", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frame_sign: public Ui_Frame_sign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAME_SIGN_H
