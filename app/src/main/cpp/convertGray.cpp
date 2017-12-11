#include <jni.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int toGray(Mat img, Mat& gray);

extern "C"

JNIEXPORT jint JNICALL Java_com_roy_opencvcameartest_MainActivity_convertGray(
        JNIEnv *env, jobject obj, jlong addrRgba, jlong addrGray) {
    Mat& mRgb = *(Mat*)addrRgba;
    Mat& mGray = *(Mat*)addrGray;

    int conv;
    jint retVal;
    conv = toGray(mRgb, mGray);

    retVal = (jint)conv;
    return retVal;
}

int toGray(Mat img, Mat& gray) {
    cvtColor(img, gray, CV_RGBA2GRAY);
    if (gray.rows == img.rows && gray.cols == img.cols) {
        return 1;
    }
    return 0;
}