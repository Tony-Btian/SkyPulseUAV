#include "datamanager.h"

DataManager::DataManager(const QString &fileName, QObject *parent)
    : file(fileName), QObject{parent}
{
    // 检查文件是否存在
    if(!file.exists()){
        // 文件不存在，尝试创建文件
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            // 如果文件无法创建
            qWarning("Unable to create file");
            return;
        }
        file.close();
    }
}


DataManager::~DataManager()
{
    file.close();
}


bool DataManager::writeHeader(const QStringList &header)
{
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        stream.setDevice(&file);
        stream << header.join(",") + "\n";
        return true;
    }
    else{
        // 文件已存在，检查头部
        QString existingHeader = file.readLine().trimmed();
        file.close();
        if(existingHeader == header.join(",")){
            // 头部相同，覆写数据部分，保留头部
            file.open(QIODevice::ReadWrite | QIODevice::Text);
            file.resize(existingHeader.length() + 2);
            file.seek(existingHeader.length() + 2);
        }
        else{
            // 头部不同，覆写整个文件
            file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
        }
        stream.setDevice(&file);
        if(existingHeader != header.join(",")){
            stream << header.join(",") + "\n";
        }
        return true;
    }
}


bool DataManager::writeRow(const QStringList &row)
{
    if (!file.isWritable()) return false;

    stream << row.join(",") + "\n";
    return true;
}


QList<QStringList> DataManager::readAll()
{
    QList<QStringList> rows;
    if (!file.isReadable()) return rows;

    // 移动到文件开头，以便从头开始读取
    file.seek(0);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        QStringList row = line.split(",");
        rows.append(row);
    }
    return rows;
}


void DataManager::close()
{
    file.close();
}
