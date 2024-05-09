#ifndef VIDEOSTREAMER_H
#define VIDEOSTREAMER_H

#include <QObject>
#include <QUdpSocket>
#include <QDebug>
#include <vector>
#include <opencv2/opencv.hpp>
#include <QThreadPool>
#include <QtConcurrent/QtConcurrent>

class VideoStreamer : public QObject {
    Q_OBJECT

public:
    explicit VideoStreamer(QObject *parent = nullptr);
    void startStreaming(const QHostAddress &address, quint16 port);

private:
    cv::VideoCapture capture;
    QUdpSocket *socket;
};

#endif // VIDEOSTREAMER_H
