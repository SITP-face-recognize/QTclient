#include "choosecoursedialog.h"
#include "ui_choosecoursedialog.h"
#include "httpop.h"

#include <QStandardItemModel>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QVariantMap>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QList>
#include <QJsonValue>

ChooseCourseDialog::ChooseCourseDialog(QString id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseCourseDialog)
{
    ui->setupUi(this);
    this->get_teacher_info(id);
    this->get_courselist(id);

    ui->noChoiceWarning->setVisible(false);
}

ChooseCourseDialog::~ChooseCourseDialog()
{
    delete ui;//这里删掉后还要返回登录窗口或者关闭主窗口
}

void ChooseCourseDialog::get_courselist(QString id)
{
    //根据老师id获取课程列表
    HttpOp* ho = new HttpOp();
    //设置URL
    QString strUrl = ho->reBaseUrl();
    strUrl += ("/teacherCourse/teacher_id=" +id);

    connect(ho,SIGNAL(signal_requestFinished(bool,QNetworkReply&)), //http请求结束信号
            this,SLOT(slot_requestFinished(bool,QNetworkReply&)));

    qDebug() << strUrl << endl;
    ho->sendRequest(strUrl,"get");


}

void ChooseCourseDialog::slot_requestFinished(bool bSuccess, QNetworkReply &reply)
{
    if(bSuccess)
    {
        course_model = new QStandardItemModel();
        qDebug() <<"request finished"<< reply.Text;
        QJsonParseError p_error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(reply.readAll(),&p_error);

        if(p_error.error == QJsonParseError::NoError){
            if(!(jsonDocument.isNull()||jsonDocument.isEmpty())){
                if(jsonDocument.isObject())
                {
                    ;
                }
                else if(jsonDocument.isArray())//判断类型是否为array，并且将array遍历出来
                {
                    QJsonArray array = jsonDocument.array();
                    QStandardItem* item = 0;

                    for(int i=0;i<array.size();i++)
                    {
                        QJsonValue value = array[i];

                        //似乎Json里面的数字只能用toInt函数，再转成String
                        //item = new QStandardItem(QString("%1").arg(value["courseId"].toInt()));
                        item = new QStandardItem(QString::number(value["courseId"].toInt(),10));
                        //course_model->item(i,0)->setTextAlignment(Qt::AlignCenter);
                        course_model->setItem(i,0,item);

                        item = new QStandardItem(value["courseName"].toString());
                        //course_model->item(i,1)->setTextAlignment(Qt::AlignCenter);
                        course_model->setItem(i,1,item);
                    }
                }
            }
        }

        show_courselist();
    }
    else
    {
        qDebug()<<"failed request";
    }
}

void ChooseCourseDialog::on_btn_test_clicked()
{
    int row_selected = ui->tableView->currentIndex().row();//获取选中的行

    if(row_selected == -1)//未选择任何选项
    {
        ui->noChoiceWarning->setVisible(true);
        return;//不放行
    }
    else
    {
        //根据row进行网络请求...
    }

    course = course_model->item(row_selected,0)->text();//course=course_id[row_selected]

    accept();
}

void ChooseCourseDialog::get_teacher_info(QString id)
{
    ui->lb_id_pro->setText(id);
    //应查询后台
    ui->lb_name_pro->setText(QString(tr("王老师")));
}

void ChooseCourseDialog::show_courselist()
{
    QStringList labels = QObject::trUtf8("课程ID,课程名称").simplified().split(",");
    course_model->setHorizontalHeaderLabels(labels);

    ui->tableView->setModel(course_model);
    ui->tableView->setShowGrid(false);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//内容不可编辑
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::
                                                            ResizeToContents);//设置列宽随文本增长
    ui->tableView->horizontalHeader()->setResizeContentsPrecision(QHeaderView::Fixed);//设置鼠标不可改变列宽
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);//设置只能选择一行，不能多行选中
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//单击选择一行
    ui->tableView->setAlternatingRowColors(true);//设置隔一行变一颜色，即：一灰一白
    QHeaderView *header = ui->tableView->horizontalHeader();
    header->setStretchLastSection(true);
    ui->tableView->show();
}













