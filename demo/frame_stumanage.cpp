#include "frame_stumanage.h"
#include "ui_frame_stumanage.h"
#include "frame_sign.h"
#include <QMessageBox>

#define FirstTime 1
#define Update 2

Frame_stuManage::Frame_stuManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Frame_stuManage)
{
     ui->setupUi(this);
     ui->btn_updateFace->setEnabled(false);
     ui->btn_delete->setEnabled(false);
     ui->addstu_id_LineEdit->setPlaceholderText(QString("num"));
     ui->addstu_name_LineEdit->setPlaceholderText(QString("name"));
     ui->tb_id_update->setPlaceholderText(QString("num"));
     ui->tb_id_delete->setPlaceholderText(QString("num"));

     ui->upstu_name_Label->setVisible(false);
     ui->destu_name_Label->setVisible(false);
}

Frame_stuManage::~Frame_stuManage()
{
    delete ui;
}

//判断输入是否合法以及学号是否已存在，用于添加学生
int check_add_input(QString stuid,QString name)
{   
	int flag=1;
	if (getId(stuid) >=0)flag = -1;
    if(stuid==NULL||name==NULL)
        return -1;
    return flag;
}

//判断输入是否合法以及学号是否已存在，用于更新和删除学生,返回学生姓名或一个特殊串表示失败
QString check_stu_existed(QString stuid)
{
	
	if (stuid == NULL || getId(stuid) == -1)
		return QString("_NULL_");//危险的写法
	return getName(stuid);
}

//增加学生信息 ***
void Frame_stuManage::on_btn_addFace_clicked()
{
    QString stuid=ui->addstu_id_LineEdit->text();
    QString name=ui->addstu_name_LineEdit->text();
    int flag=check_add_input(stuid,name);
    if(flag==-1){
        QMessageBox::warning(this,tr("警告"),tr("输入并不合法!/或者学号已存在"),QMessageBox::Yes);
        this->ui->addstu_id_LineEdit->clear();
        this->ui->addstu_name_LineEdit->clear();
        this->ui->addstu_id_LineEdit->setFocus();
    }
    else{

        Frame_sign *fs=new Frame_sign(FirstTime,stuid.toStdString());
        fs->setParent(ui->stu_add);
        fs->show();
		//新增一个学生
		int id=-1;
		/////////这里应该向后台新增一个学生，并返回其id

		/////////
		Student_List->push_back(Student(id,stuid, name));

        ui->addstu_id_LineEdit->clear();
        ui->addstu_name_LineEdit->clear();
    }
}

//更新学生信息 ***
void Frame_stuManage::on_btn_updateFace_clicked()
{
	QString id = ui->tb_id_update->text();
    Frame_sign *fs=new Frame_sign(Update, id.toStdString());
    fs->setParent(ui->stu_update);
    fs->show();
	/////////这里应该向后台更新学生信息

	/////////
    ui->tb_id_update->clear();
    ui->tip_name_update->clear();
}

//删除学生信息 ***
void Frame_stuManage::on_btn_delete_clicked()
{
    QString id=ui->tb_id_delete->text();
    QString name=ui->tip_name_delete->text();

    QMessageBox msgBox;
      msgBox.setText(id+" "+name+" 的信息将会被删除");
      msgBox.setInformativeText("确定删除吗？");
      msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
      msgBox.setDefaultButton(QMessageBox::Ok);
      int ret = msgBox.exec();
      switch (ret) {
          case QMessageBox::Ok:
              // Ok was clicked
			  ////
              break;
          case QMessageBox::Cancel:
              // Cancel was clicked
              break;
          default:
              // should never be reached
              break;
        }
}

//更新学生 学号输入框 文本改变时的函数 合法且有效时按钮才enable
void Frame_stuManage::on_tb_id_update_textChanged(QString id)
{
    QString name=check_stu_existed(id);
	if (id == "") {
		ui->tip_name_update->clear();
		return;
	}
    if(name=="_NULL_"){//为空或者不合法不存在
        ui->btn_updateFace->setEnabled(false);
        ui->upstu_name_Label->setVisible(false);
        ui->tip_name_update->clear();
		ui->tip_name_update->setStyleSheet("color:#ff0000;");
		ui->tip_name_update->setText(QString(tr("该学号不存在")));
    }
    else{
        ui->btn_updateFace->setEnabled(true);
        ui->upstu_name_Label->setVisible(true);
		ui->tip_name_update->setStyleSheet("color:#00a99d;");
        ui->tip_name_update->setText(name);
    }

}

//删除学生 学号输入框 文本改变时的函数 合法且有效时按钮才enable
void Frame_stuManage::on_tb_id_delete_textChanged(QString id)
{
    QString name=check_stu_existed(id);
	if (id == "") {
		ui->tip_name_delete->clear();
		return;
	}
    if(name=="_NULL_"){//为空或者不合法不存在
        ui->btn_delete->setEnabled(false);
        ui->destu_name_Label->setVisible(false);
        ui->tip_name_delete->clear();
		ui->tip_name_delete->setStyleSheet("color:#ff0000;");
		ui->tip_name_delete->setText(QString(tr("该学号不存在")));
    }
    else{
        ui->btn_delete->setEnabled(true);
        ui->destu_name_Label->setVisible(true);
		ui->tip_name_delete->setStyleSheet("color:#00a99d;");
        ui->tip_name_delete->setText(name);
    }
}
