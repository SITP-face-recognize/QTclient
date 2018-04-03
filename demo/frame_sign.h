#ifndef Frame_sign_H
#define Frame_sign_H

#include "httpop.h"
#include <QWidget>
#include <QtMultimedia\QCamera>
#include <QtMultimediaWidgets\QCameraViewfinder>
#include <QtMultimedia\QCameraImageCapture>
#include <QFileDialog>
#include <vector>
#include "face_recongnization.h"
#include "global.h"

using namespace cv;
using namespace std;
using namespace face;

namespace Ui {
class Frame_sign;
}
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;

class Frame_sign : public QWidget
{
    Q_OBJECT
public:
    explicit Frame_sign(int flag=0,string id="", QWidget *parent = 0);
    ~Frame_sign();

private slots:
void captureImage();
void saveImage(int,QImage);
void sign_over();
void sign_start();
void sign_first_over();
void slot_createSignFinished(bool, QNetworkReply&);
void slot_detailSignFinished(bool, QNetworkReply&);

private:
    Ui::Frame_sign *ui;

    QCamera *camera;
    QCameraViewfinder *viewfinder;
    QCameraImageCapture *imageCapture;
    //录入信息时候的学生学号
	string new_stuid;
    VideoCapture capture; // 相机

	QString sign_id;//当前签到id
	
	string dirPath;
	int flag=0;//1为首次录入照片，2为更新信息，0为正常签到
	int capture_count = 0;
    void init();
	int faceRecognition();
	vector<string> stu_signed_stuId;//这个是原来的stu_signed_id 改名了
	vector<int> stu_signed_id;
	vector<Mat> newImages;
	vector<int> label;
	void createSign();//新建创建签到函数
	void detailSign();//填补签到细节
};

#endif // Frame_sign_H
