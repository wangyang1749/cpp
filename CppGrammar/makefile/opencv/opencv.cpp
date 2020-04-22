#include <opencv2/opencv.hpp>

#include <iostream>

using namespace std;
using namespace cv;
int main(){
    
	//读取本地的一张图片便显示出来
	Mat img = imread("E:\\temp\\001.jpg");
	imshow("MM Viewer", img);
	//等待用户按键
	waitKey(0);
	return 0;
}