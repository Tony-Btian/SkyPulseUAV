#ifndef DRONECONFIGMANAGER_H
#define DRONECONFIGMANAGER_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class DroneConfigManager {
public:
    DroneConfigManager(const QString &filename, const QStringList &headers);
    bool writeData(const QVector<uint8_t> &data);
    QVector<uint8_t> readData();

private:
    QString filename;
    QStringList headers;

};

#endif // DRONECONFIGMANAGER_H
