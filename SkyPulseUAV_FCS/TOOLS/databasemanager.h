#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class DatabaseManager
{
public:
    DatabaseManager(const QString &path);
    ~DatabaseManager();

    bool addOrUpdateParam(const QString &name, double value);
    double getParam(const QString &name);

private:
    QSqlDatabase db;
    bool openDB();
    bool createTable();

};

#endif // DATABASEMANAGER_H
