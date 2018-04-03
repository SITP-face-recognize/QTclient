#include "frame_sign.h"
#include "ui_Frame_sign.h"
#include "httpop.h"
#include<opencv2\opencv.hpp>
#include <opencv2\imgproc.hpp>
#include<opencv2\face\facerec.hpp>
#include <iostream>
#include<direct.h>
#include<io.h>
#include <vector>
#include<windows.h>
#include <fstream>
#include <sstream>
#include <math.h>
#include <string>

#include <QDir>
#include <QTimer>
#include <QGraphicsScene>

using namespace cv;
using namespace std;
using namespace face;
#define PHOTO_NUM 10

bool is_networkError = false;
const string PICPATH = "F:\\SITP_pic";
const string CASCADEPATH = "E:\\OpenCV\\etc\\haarcascades\\haarcascade_frontalface_alt.xml";

Frame_sign::Frame_sign(int flag,string id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Frame_sign)
{
    ui->setupUi(this);
	this->flag = flag;
    this->new_stuid=id;
    
	camera=new QCamera(this);
    viewfinder=new QCameraViewfinder(this);
    imageCapture=new QCameraImageCapture(camera);
    camera->setViewfinder(viewfinder);
    ui->ImageView->addWidget(viewfinder);
    //ui->ImageCapture->setScaledContents(true);
	
    if(flag>0){//为录入信息时
        init();
		int j = 0;
		if (flag == 1) {//添加照片时 找dirPath
			while (1) {
				this->dirPath = format("people%d", j);
				//代码  "../path"为目录路径
				QDir dir;
				dir.cd("F:\\SITP_pic");  //进入某文件夹
				if (!dir.exists(QString::fromStdString(dirPath)))//判断需要创建的文件夹是否存在
				{
					dir.mkdir(QString::fromStdString(dirPath)); //创建文件夹
					break;
				}
				else {
					j++;
				}
			}
		}

		ui->tips->setText("got 0 photos\n 10 remain");
		ui->buttonCapture->setText(QString(tr("拍照")));
        ui->buttonQuit->setText(QString(tr("结束录入")));
        ui->view_start->hide();

        connect(ui->buttonCapture, SIGNAL(clicked()), this, SLOT(captureImage()));
        connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(saveImage(int,QImage)));
        connect(ui->buttonQuit, SIGNAL(clicked()), this, SLOT(sign_first_over()));

    }
    else{ //为正常签到时
        ui->view_sign->hide();
        ui->view_first->hide();

        connect(ui->btn_start,SIGNAL(clicked()), this, SLOT(sign_start()));
        connect(ui->buttonQuit, SIGNAL(clicked()), this, SLOT(sign_over()));
	  }
}

Frame_sign::~Frame_sign()
{
    delete ui;
}


void Frame_sign::init()
{
	this->camera->start();
}

//正常签到开始
void Frame_sign::sign_start()
{
	stu_signed_stuId.clear();
	stu_signed_id.clear();

    ui->view_start->hide();
    ui->view_sign->show();

	if (!this->capture.open(0))
	{
		cout << "Capture didn't work" << endl;
		return;
	}
	createSign();
	this->faceRecognition();
}
//正常签到结束
void Frame_sign::sign_over()
{
	this->capture.release();
	
	detailSign();
	// this->camera->stop();
	//viewfinder->hide();
	ui->view_sign->hide();
	ui->view_start->show();

}
//录入照片信息结束
void Frame_sign::sign_first_over()
{
    //保存工作等
	
	//this->capture.release();
    this->camera->stop();
  //  ui->ImageCapture->clear();
		
	if (flag == 1) {
		//预处理和训练 
		/*preprocessing();
		csv();
		mmodel_training();*/
	}
	else {

		Ptr<FaceRecognizer> modelLBP = LBPHFaceRecognizer::create();
		modelLBP->read("MyFaceLBPHModel.xml");

		modelLBP->update(newImages, label);
		modelLBP->save("MyFaceLBPHModel.xml");
	}
	this->close();
}

void Frame_sign::slot_createSignFinished(bool bSuccess, QNetworkReply & reply)
{
	if (bSuccess)
	{
		QJsonParseError p_error;
		QJsonDocument jsonDocument = QJsonDocument::fromJson(reply.readAll(), &p_error);

		int r = 0;
		if (p_error.error == QJsonParseError::NoError) {
			if (!(jsonDocument.isNull() || jsonDocument.isEmpty()) && jsonDocument.isObject()) {
				QJsonObject object = jsonDocument.object();
				if (object.contains("sign")) {
					QJsonValue value = object.value("sign");
					sign_id = value.toString();
				}
			}
		}
	}
	else
	{
		qDebug()<<"创建 sign 请求失败!";
	}
}

void Frame_sign::slot_detailSignFinished(bool bSuccess, QNetworkReply & reply)
{
	if (bSuccess)
	{
		is_networkError = true;
	}
	else
	{
		qDebug() << "发送 sign 请求失败!";
	}
}



//正常签到的过程
int Frame_sign::faceRecognition()
{
	Mat frame, gray;

	CascadeClassifier cascade;
	//cascade.load("E:\\GitHub\\opencv - practice\\opencv - practice1\\data\\haarcascades\\haarcascade_frontalface_alt.xml");
	if (!cascade.load(CASCADEPATH))
	{
		cerr << "ERROR: Could not load classifier cascade" << endl;
		return -1;
	}
	//Ptr<FaceRecognizer> modelPCA = EigenFaceRecognizer::create();
	Ptr<FaceRecognizer> modelLBP = LBPHFaceRecognizer::create();
	//Ptr<FaceRecognizer> modelFisher = FisherFaceRecognizer::create();
	//modelPCA->read("MyFacePCAModel.xml");
	modelLBP->read("MyFaceLBPHModel.xml"); 
	//modelFisher->read("MyFaceFisherModel.xml");
	while (1)
	{
		capture >> frame;
		char key = waitKey(1);
		vector<Rect> faces(0);
		//white_balance(frame, gray);
		cvtColor(frame, gray, CV_BGR2GRAY);
		equalizeHist(gray, gray);
		cascade.detectMultiScale(gray, faces, 1.1, 3, 0 | CASCADE_DO_ROUGH_SEARCH, Size(50, 50)); //目标大于50*50
		Mat face;
		Point text_lb;

		for (auto faces_iterator = faces.begin(); faces_iterator != faces.end(); faces_iterator++)
		{
			if ((*faces_iterator).height > 0 && (*faces_iterator).width > 0)
			{
				face = gray(*faces_iterator);
				text_lb = Point((*faces_iterator).x, (*faces_iterator).y);
				rectangle(frame, *faces_iterator, Scalar(255, 0, 0), 1, 8, 0);
			}
		}

		Mat face_test;
		double confidence = 0;
		double confidence1 = 0;
		double confidence2 = 0;
		int predictPCA = 0;
		int predictLBP = 0;
		int predictFisher = 0;

		if (face.rows >= 120)
			cv::resize(face, face_test, Size(92, 112));

		if (!face_test.empty()) {
			//modelPCA->predict(face_test, predictPCA, confidence);
			modelLBP->predict(face_test, predictLBP, confidence1);
			//modelFisher->predict(face_test, predictFisher, confidence2);
		}


		cout << "LBP" << predictLBP << "   置信度:" << confidence1 << endl;
		//cout << "LBP" << predictPCA << "   置信度:" << confidence << endl;
		//cout << "FSH" << predictPCA << "   置信度:" << confidence2 << endl;

		putText(frame, to_string(predictLBP), text_lb, FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255));
<<<<<<< HEAD
		stu_signed_stuId.push_back(to_string(predictLBP));
=======
		stu_signed_id.push_back(to_string(predictLBP));
>>>>>>> master
		//qDebug() << predictLBP;
		//emit sign_successed(to_string(predictLBP));
		imshow("face", frame);
		if (key == 27) {
			destroyWindow("face");
			break;
		}
	}

	QString info = "succeed:\n";
	
	//去重
	sort(stu_signed_stuId.begin(), stu_signed_stuId.end());
	stu_signed_stuId.erase(unique(stu_signed_stuId.begin(), stu_signed_stuId.end()), stu_signed_stuId.end());

<<<<<<< HEAD
	int l = stu_signed_stuId.size();
	for (auto id_iterator = stu_signed_stuId.begin(); id_iterator != stu_signed_stuId.end(); id_iterator++)
	{
		if (*id_iterator != "0") {
			int cur = getId(QString::fromStdString(*id_iterator));
			if (cur != -1) {
				info += QString::fromStdString((*id_iterator)) + "\n";
				stu_signed_id.push_back(cur);
			}
		}
	}
	ui->tip_info->setText(info);
}

//新建一个签到
void Frame_sign::createSign()
{
	QByteArray post_data;
	post_data.append("course:" + QString::number(Course_Id,10));

	HttpOp* ho = new HttpOp();
	QString strUrl = ho->reBaseUrl();
	strUrl += ("/sign");
	qDebug() << strUrl;

	connect(ho, SIGNAL(signal_requestFinished(bool, QNetworkReply&)), //http请求结束信号
		this, SLOT(slot_createSignFinished(bool, QNetworkReply&)));

	ho->postRequest(strUrl, post_data);//发送请求
}

//增加本次签到信息
void Frame_sign::detailSign()
{
	for (auto iterator = Student_List->begin(); iterator != Student_List->end(); iterator++) {
		QByteArray post_data;
		post_data.append("sign:" + sign_id);
		post_data.append("student:" + iterator->stuId);
		post_data.append("signKind: face");

		HttpOp* ho = new HttpOp();
		QString strUrl = ho->reBaseUrl();
		strUrl += ("/signDetail");
		qDebug() << strUrl;

		/*connect(ho, SIGNAL(signal_requestFinished(bool, QNetworkReply&)), //http请求结束信号
			this, SLOT(slot_detailSignFinished(bool, QNetworkReply&)));*/

		ho->postRequest(strUrl, post_data);//发送请求
	}
=======
	int l = stu_signed_id.size();
	for (auto id_iterator = stu_signed_id.begin(); id_iterator != stu_signed_id.end(); id_iterator++)
	{
		if(*id_iterator!="0")
		info += QString::fromStdString((*id_iterator)) + "\n";
	}
	ui->tip_info->setText(info);
>>>>>>> master
}

//捕捉照片
void Frame_sign::captureImage()
{
	//ui->statusBar->showMessage(tr("capturing..."), 1000);
	// ui->buttonCapture->setEnabled(false);
	//qDebug() << "开始采集照片" << endl;

	ui->buttonQuit->setEnabled(false);

	this->imageCapture->capture();
	this->capture_count++;
	string info = "got " + to_string(this->capture_count) + " photos\n ";
	info += to_string(10 - this->capture_count) + " remain";
	if (this->capture_count == 10) {
		info = "捕获照片成功\n点击下方结束";

		ui->buttonCapture->setEnabled(false);
		ui->buttonQuit->setEnabled(true);
	}
	ui->tips->setText(QString::fromStdString(info));

	/*if(flag==1)
	shoot(new_stuid);
	else updata(new_stuid);
		*/
}

//保存照片用
Mat QImage2Mat(QImage const& src)
{
	cv::Mat tmp(src.height(), src.width(), CV_8UC3, (uchar*)src.bits(), src.bytesPerLine());
	cv::Mat result; // deep copy just in case (my lack of knowledge with open cv)  
	cvtColor(tmp, result, CV_BGR2RGB);
	return result;
}

//保存照片
void Frame_sign::saveImage(int i, QImage image)
{
	string filePath = PICPATH+"\\"+dirPath + "\\" + this->new_stuid + format("pic%d.jpg", i);

	//ui->statusBar->showMessage(tr("capture OK!"), 5000);

	if (this->flag == 1) {//添加照片
		ui->label->setPixmap(QPixmap::fromImage(image));
		const QPixmap* pixmap = ui->label->pixmap();
		if (pixmap) {
			qDebug() << pixmap->save(QString::fromStdString(filePath));
		}
	}
	else {//更新照片
		Mat frame = QImage2Mat(image);
		Mat gray;
		CascadeClassifier cascade;
		
		if (!cascade.load(CASCADEPATH))
		{
			cerr << "ERROR: Could not load classifier cascade" << endl;
			return ;
		}
		vector<Rect> faces(0);
		//white_balance(frame, gray);

		cvtColor(frame, gray, CV_BGR2GRAY);
		equalizeHist(gray, gray);
		cascade.detectMultiScale(gray, faces, 1.1, 3, 0 | CASCADE_DO_ROUGH_SEARCH, Size(50, 50)); //目标大于50*50

		Mat face;
		Point text_lb;

		for (auto faces_iterator = faces.begin(); faces_iterator != faces.end(); faces_iterator++)
		{
			if ((*faces_iterator).height > 0 && (*faces_iterator).width > 0)
			{
				face = gray(*faces_iterator);
				text_lb = Point((*faces_iterator).x, (*faces_iterator).y);
				rectangle(frame, *faces_iterator, Scalar(255, 0, 0), 1, 8, 0);
			}
		}

		Mat face_test;
	
		if (face.rows >= 120)
			cv::resize(face, face_test, Size(92, 112));
		newImages.push_back(face_test);
		label.push_back(stoi(this->new_stuid));
	}
}

