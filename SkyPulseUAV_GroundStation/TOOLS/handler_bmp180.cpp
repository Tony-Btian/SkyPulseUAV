#include "handler_bmp180.h"
#include <QDebug>

Handler_BMP180::Handler_BMP180(MediatorInterface *mediator) : mediator(mediator) {}

void Handler_BMP180::handleData(const QByteArray &data) {
    // 实现类型A的数据处理逻辑
    // 这里可以进行数据解析、更新模型、发送信号等操作
    // 例如：
    qDebug() << "Handler_BMP180DataHandlerFactory is processing data: " << data;
    QString result = "处理结果"; // 假设这是处理的结果
    mediator->notify(result); // 通过中介者通知MainWindow
}
