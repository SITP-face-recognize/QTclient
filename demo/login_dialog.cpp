#include "login_dialog.h"
#include "ui_login_dialog.h"
#include "httpop.h"

#include <QByteArray>
#include <QCryptographicHash>

QString token;

Login_Dialog::Login_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login_Dialog)
{
	login_fail = false;
    ui->setupUi(this);
	QPixmap img(":/assets/img/logo.png");
	ui->logo->setPixmap(img);
}

Login_Dialog::~Login_Dialog()
{
    delete ui;
}

//检查老师ID和密码
int Login_Dialog::check_teacher_id(QString id,QString password)
{
    //此处应为查询后台
    //密码使用md5加密
    
    /*btarray.append(password);
    QByteArray hash_btarray=QCryptographicHash::hash(btarray,QCryptographicHash::Md5);
    QString md5_p=hash_btarray.toHex();*/
	
	QByteArray post_data;
	post_data.append("username="+id+"&password="+password);

    HttpOp* ho = new HttpOp();
	QString strUrl = ho->reBaseUrl();
	strUrl += ("/login");
	qDebug() << strUrl;

    connect(ho,SIGNAL(signal_requestFinished(bool,QNetworkReply&)), //http请求结束信号
            this,SLOT(slot_postFinished(bool,QNetworkReply&)));
	
    ho->postRequest(strUrl, post_data);

    //测试用
    if(id==NULL||password==NULL)
        return -1;
    return 1;
}

void Login_Dialog::slot_postFinished(bool bSuccess,QNetworkReply &reply)
{
	if (bSuccess)
	{
		qDebug() << "request finished" << reply.Text;
		QJsonParseError p_error;
		QJsonDocument jsonDocument = QJsonDocument::fromJson(reply.readAll(), &p_error);

		if (p_error.error == QJsonParseError::NoError) {
			if (!(jsonDocument.isNull() || jsonDocument.isEmpty())) {
				if (jsonDocument.isObject())
				{
					QJsonObject object = jsonDocument.object();
					QJsonValue value = object.value("token");//取出key为name的值
															//判断是否是string类型
					qDebug() << "token:" << value.toString();
					if (value.isString())
						token = value.toString();
					qDebug() << token;					
				}
			}
		}
	}
	else
	{
		login_fail = true;
		qDebug() << "post请求失效";
		/*QMessageBox::warning(this, tr("警告"), tr("用户名或密码错误!"), QMessageBox::Yes);
		this->ui->tb_id->clear();
		this->ui->tb_password->clear();
		this->ui->tb_id->setFocus();*/
	}
}

//点击登录
void Login_Dialog::on_btn_login_clicked()
{
    QString id=ui->tb_id->text();
    QString password=ui->tb_password->text();

    int flag=check_teacher_id(id,password);
    if(flag==1){//检查
        this->teacher_id=id;
        accept();
    }
    else if(flag==-1){
		QMessageBox::warning(this, tr("警告"), tr("用户名或密码错误!"), QMessageBox::Yes);
		this->ui->tb_id->clear();
		this->ui->tb_password->clear();
		this->ui->tb_id->setFocus();
    }
}

