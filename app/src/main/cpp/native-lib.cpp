#include <jni.h>
#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

extern "C"{
    jstring
    Java_com_example_marci_opencvsimpleproject_MainActivity_stringFromJNI(JNIEnv* env, jobject /* this */) {
        std::string hello = "Hello from C++";
        return env->NewStringUTF(hello.c_str());
    }

    int toGray(Mat img, Mat& gray){
        cvtColor(img, gray, CV_RGB2GRAY);
        if (gray.rows == img.rows && gray.cols == img.cols){
            return 1;
        }
        else{
            return 0;
        }
    }

    jint
    Java_com_example_marci_opencvsimpleproject_MainActivity_imgProc(JNIEnv* env, jclass, jlong inputMat, jlong imageGray) {
        Mat& rgb = *(Mat*) inputMat;
        Mat& gray = *(Mat*) imageGray;
        int success = toGray(rgb, gray);
        return (jint)success;

    }



}