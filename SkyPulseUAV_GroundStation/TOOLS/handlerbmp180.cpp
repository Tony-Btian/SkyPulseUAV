#include "handlerbmp180.h"


HandlerBMP180::HandlerBMP180(MediatorInterface* mediator)
    : mediator(mediator) {}

void HandlerBMP180::handleData(const QByteArray &data) {
    // 实现数据处理逻辑
    // 可能还会使用mediator来通知MainWindow更新UI
}
