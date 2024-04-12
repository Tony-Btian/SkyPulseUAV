#ifndef VIDEOCAPTURE_H
#define VIDEOCAPTURE_H

#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <string>
#include <QThread>

class VideoCapture : public QObject
{
    Q_OBJECT

public:
    explicit VideoCapture(QObject *parent() = nullptr, int cameraIndex = 0, const std::string &outputFileName = "output.avi");
    ~VideoCapture();


    void stopCamera();

private:
    QThread *videoCaptureThread;
    cv::VideoCapture cap;
    cv::VideoWriter writer;
    int cameraIndex;
    std::string outputFileName;

    void captureAndEncode();

public slots:
    bool startCamera();

private slots:
    void setupCamera();

};

#endif // VIDEOCAPTURE_H
