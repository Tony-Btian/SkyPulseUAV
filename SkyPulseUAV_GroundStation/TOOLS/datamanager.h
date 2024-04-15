#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>

class DataManager : public QObject
{
    Q_OBJECT
public:
    explicit DataManager(const QString &fileName, QObject *parent = nullptr);
    ~DataManager();

    bool writeHeader(const QStringList &header);
    bool writeRow(const QStringList &row);
    QList<QStringList> readAll();
    void close();

private:
    QFile file;
    QTextStream stream;

signals:
    void sig_fileMangerError(QString ErrorMessage);

};

#endif // DATAMANAGER_H
