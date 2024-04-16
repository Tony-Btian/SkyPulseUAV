#include "droneconfigmanager.h"

DroneConfigManager::DroneConfigManager(const QString &filename, const QStringList &headers)
    : filename(filename), headers(headers)
{
    QFile file(filename);
    if (!file.exists()) {
        if (!file.open(QIODevice::WriteOnly)) {
            qDebug() << "Failed to create file: " << file.errorString();
            return;
        }
        QTextStream out(&file);
        out << headers.join(",") << "\n";
        file.close();
    }
}

bool DroneConfigManager::writeData(const QVector<uint8_t> &data)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for writing: " << file.errorString();
        return false;
    }

    QTextStream out(&file);
    out << headers.join(",") << "\n";  // Write headers first

    QStringList dataStrings;
    for (auto value : data) {
        dataStrings.append(QString::number(value));
    }
    out << dataStrings.join(",") << "\n";

    file.close();
    return true;
}

QVector<uint8_t> DroneConfigManager::readData()
{
    QVector<uint8_t> data;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Cannot open file for reading: " << file.errorString();
        return data;
    }

    QTextStream in(&file);
    in.readLine();  // Skip headers
    QString line = in.readLine();
    QStringList values = line.split(',');
    for (const QString &value : values) {
        bool ok;
        int byte = value.toInt(&ok);
        if (ok) {
            data.append(static_cast<uint8_t>(byte));
        }
    }

    file.close();
    return data;
}
