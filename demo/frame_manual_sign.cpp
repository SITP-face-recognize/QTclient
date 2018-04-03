#include "frame_manual_sign.h"
#include "ui_frame_manual_sign.h"
#include <QMessageBox>

Frame_manual_sign::Frame_manual_sign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Frame_manual_sign)
{
    ui->setupUi(this);
    ui->btn_submit->setEnabled(false);
    ui->tb_id->setPlaceholderText(QString("num"));
    ui->stu_name->setVisible(false);
}

Frame_manual_sign::~Frame_manual_sign()
{
    delete ui;
}

//判断输入是否合法以及学号是否已存在，用于手动签到,返回学生姓名或一个特殊串表示失败
QString Frame_manual_sign::check_stu_existed_for_sign(QString stuid)
{
	if (stuid == NULL || getId(stuid) == -1)
		return QString("_NULL_");//危险的写法
	return getName(stuid);
}

//确认手动签到 ***
void Frame_manual_sign::on_btn_submit_clicked()
{
    QString stuid=ui->tb_id->text();
    QString name=ui->tip_name->text();

      QMessageBox msgBox;
      msgBox.setText(stuid+name);
      msgBox.setInformativeText("turn up");
      msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
      msgBox.setDefaultButton(QMessageBox::Ok);
      int ret = msgBox.exec();
      switch (ret) {
          case QMessageBox::Ok:
              // Ok was clicked
			  ////////确定签到，新建一个签到信息 ***

			  ////////
              break;
          case QMessageBox::Cancel:
              // Cancel was clicked
              break;
          default:
              // should never be reached
              break;
        }


}

//手动签到 学号输入框 文本改变时的函数 合法且有效时按钮才enable
void Frame_manual_sign::on_tb_id_textChanged(QString id)
{
    QString name=check_stu_existed_for_sign(id);
	if (id == "") {
		ui->tip_name->clear();
		return;
	}
    if(name=="_NULL_"){//为空或者不合法不存在
        ui->btn_submit->setEnabled(false);
        ui->stu_name->setVisible(false);
        ui->tip_name->clear();
		ui->tip_name->setStyleSheet("color:#ff0000;");
		ui->tip_name->setText(QString(tr("该学号不存在")));
    }
    else{
        ui->btn_submit->setEnabled(true);
        ui->stu_name->setVisible(true);
		ui->tip_name->setStyleSheet("color:#00a99d;");
        ui->tip_name->setText(name);
    }
}
