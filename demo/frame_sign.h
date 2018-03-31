#ifndef Frame_sign_H
#define Frame_sign_H

#include <QWidget>
#include <QtMultimedia\QCamera>
#include <QtMultimediaWidgets\QCameraViewfinder>
#include <QtMultimedia\QCameraImageCapture>
#include <QFileDialog>
#include <vector>
#include "face_recongnization.h"
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

private:
    Ui::Frame_sign *ui;

    QCamera *camera;
    QCameraViewfinder *viewfinder;
    QCameraImageCapture *imageCapture;
    string stu_id;
    VideoCapture capture; // 相机

	string dirPath;
	int flag=0;//1为首次录入照片，2为更新信息，0为正常签到
	int capture_count = 0;
    void init();
	int shoot(string);
	int updata(string);
	int faceRecognition();
	vector<string> stu_signed_id;
	vector<Mat> newImages;
	vector<int> label;
};

#endif // Frame_sign_H
