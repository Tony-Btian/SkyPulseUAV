#include "videocapture.h"
#include <iostream>
#include <thread>

VideoCapture::VideoCapture(QObject *parent, int cameraIndex, const std::string &outputFileName)
    : QObject(parent), cameraIndex(cameraIndex), outputFileName(outputFileName)
{
    videoCaptureThread = new QThread(this);
    connect(videoCaptureThread, &QThread::started, this, &VideoCapture::setupCamera);
    connect(videoCaptureThread, &QThread::finished, videoCaptureThread, &QObject::deleteLater);
    this->moveToThread(this);
    videoCaptureThread->start();
}

VideoCapture::~VideoCapture()
{
    this->stopCamera();
    if(videoCaptureThread->isRunning()){
        videoCaptureThread->wait();
        videoCaptureThread->quit();
    }
}


void VideoCapture::setupCamera()
{

}

bool VideoCapture::startCamera()
{
    cap.open(cameraIndex);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera." << std::endl;
        return false;
    }

    // Get the resolution of the camera
    int frame_width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));

    // Use MJPG encoder and AVI container format
    writer.open(outputFileName, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 10, cv::Size(frame_width, frame_height), true);

    if (!writer.isOpened()) {
        std::cerr << "Error: Could not open video writer." << std::endl;
        return false;
    }

    std::thread(&VideoCaptureAndEncode::captureAndEncode, this).detach();
    return true;
}

void VideoCapture::stopCamera()
{
    if(cap.isOpened()){
        cap.release();
    }
    if(writer.isOpened()){
        writer.release();
    }
}

void VideoCapture::captureAndEncode()
{
    while (true) {
        cv::Mat frame;
        if (!cap.read(frame)) {
            std::cerr << "Error: Could not read frame from camera." << std::endl;
            break;
        }
        writer.write(frame);
    }
}
