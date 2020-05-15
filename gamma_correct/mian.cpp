#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	Mat srcMat = imread("face.jpg", 0);
	Mat dstMat;
	Mat dstMat1;
	srcMat.copyTo(dstMat);
	srcMat.copyTo(dstMat1);
	int temp;
	float lut[256];
	float lut2[256];
	float gamma = 0.4;
	float gamma2 = 2.2;
	for (int i = 0; i < 256; i++) {
		lut[i] = (float)i/255;
		lut[i] = pow(lut[i], gamma);
		lut[i] = (int)(lut[i] * 255);
	}
	for (int i = 0; i < srcMat.rows; i++) {
		for (int j = 0; j < srcMat.cols; j++) {
			temp = srcMat.at<uchar>(i, j);
			dstMat.at<uchar>(i, j) = lut[temp];

		}
	}
	for (int i = 0; i < 256; i++) {
		lut2[i] = (float)i / 255;
		lut2[i] = pow(lut2[i], gamma2);
		lut2[i] = (int)(lut2[i] * 255);
	}
	for (int i = 0; i < srcMat.rows; i++) {
		for (int j = 0; j < srcMat.cols; j++) {
			temp = srcMat.at<uchar>(i, j);
			dstMat1.at<uchar>(i, j) = lut2[temp];

		}
	}
	imshow("Ô­Í¼", srcMat);
	imshow("µ÷ÁÁ", dstMat);
	imshow("µ÷°µ", dstMat1);
	waitKey(0);
}