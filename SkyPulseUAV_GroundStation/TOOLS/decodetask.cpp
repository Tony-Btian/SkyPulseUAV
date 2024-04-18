#include "decodetask.h"

DecodeTask::DecodeTask()
{

}

// void DecodeTask::run()
// {
//     qDebug() << "Decode Thread:" << QThread::currentThreadId();
//     // Decode the data. This is a placeholder for your decoding logic.
//     QString result;
//     for(int i = 0; i < dataToDecode.size(); ++i) {
//         QString byteString = QString::number(static_cast<unsigned char>(dataToDecode[i]), 16).rightJustified(2, '0');
//         result.append(byteString + " ");
//     }
//     qDebug() << "Decoded data:" << result;
//     decodeSensorData(dataToDecode);

//     DataHandler* handler = DataHandlerFactory::createHandler(dataToDecode, mediator);
//     if (handler) {
//         handler->handleData(dataToDecode);
//         delete handler; // 记得释放资源
//     }
//     // emit decodeDataReady(result);
// }

void DecodeTask::decodeSensorData(QByteArray data_to_decode)
{
    QDataStream stream(data_to_decode);
    stream.setByteOrder(QDataStream::LittleEndian);

    float ax, ay, az, gx, gy, gz;
    double pressure, temperature, heading;
    int x, y, z;

    stream >> ax >> ay >> az >> gx >> gy >> gz >> pressure >> temperature >> x >> y >> z >> heading;

    qDebug() << "Decoded Sensor Data:";
    qDebug() << "Accelerometer: ax=" << ax << ", ay=" << ay << ", az=" << az;
    qDebug() << "Gyroscope: gx=" << gx << ", gy=" << gy << ", gz=" << gz;
    qDebug() << "Pressure:" << pressure << "Temperature:" << temperature;
    qDebug() << "Position: x=" << x << ", y=" << y << ", z=" << z;
    qDebug() << "Heading:" << heading;
}
