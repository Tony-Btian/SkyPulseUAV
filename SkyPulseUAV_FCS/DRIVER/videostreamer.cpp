#include "videostreamer.h"

VideoStreamer::VideoStreamer(QObject *parent)
    : QObject(parent), socket(new QUdpSocket(this)) {

    capture.open(0); // 0 is the default camera device ID, adjust according to the actual situation
    if (!capture.isOpened()) {
        qDebug() << "Camera open failed!";
        return;
    }
    qDebug() << "Camera open Success";
    cv::namedWindow("Video Stream", cv::WINDOW_AUTOSIZE);
}

void VideoStreamer::startStreaming(const QHostAddress &address, quint16 port) {
    QtConcurrent::run([this, address, port]() {
        while (capture.isOpened()) {
            cv::Mat frame;
            if (capture.read(frame)) {
                // Displaying video frames
                cv::imshow("Video Stream", frame);
                if (cv::waitKey(30) >= 0) break;

                std::vector<uchar> buf;
                cv::imencode(".jpg", frame, buf, std::vector<int>{cv::IMWRITE_JPEG_QUALITY, 85});
                QByteArray data(reinterpret_cast<char*>(buf.data()), buf.size());
                socket->writeDatagram(data, address, port);
            }
        }
        cv::destroyWindow("Video Stream");
    });
}
