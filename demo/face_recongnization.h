#ifndef FACE_RECONGNIZATION_H
#define FACE_RECONGNIZATION_H

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
using namespace cv;
using namespace std;
using namespace face;

int shoot();
int preprocessing();
int csv();
int mmodel_training();
int faceRecognition();
void initiallize();
int updata();
bool  CheckFolderExist(const string &strPath);


#endif // FACE_RECONGNIZATION_H
