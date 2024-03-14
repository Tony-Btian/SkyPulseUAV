#include "databasemanager.h"

DatabaseManager::DatabaseManager(const QString &path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if(!openDB()){
        qDebug() << "Failed to open database";
    }
    else{
        if(!createTable()){
            qDebug() << "Failed to create table";
        }
    }
}


DatabaseManager::~DatabaseManager()
{
    db.close();
}

bool DatabaseManager::openDB()
{
    if(!db.open()){
        qDebug() << "Error: connection with database failed";
        return false;
    }
    return true;
}

bool DatabaseManager::createTable()
{
    QSqlQuery query;
    bool success = query.exec("CREATE TABLE IF NOT EXISTS params ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                              "name TEXT NOT NULL UNIQUE, "
                              "value REAL NOT NULL)");

    if (!success) {
        qDebug() << "Failed to create table: " << query.lastError();
    }
    return success;
}

bool DatabaseManager::addOrUpdateParam(const QString &name, double value)
{
    QSqlQuery query;
    query.prepare("INSERT OR REPLACE INTO params (name, value) VALUES (:name, :value)");
    query.bindValue(":name", name);
    query.bindValue(":value", value);

    if (!query.exec()) {
        qDebug() << "Failed to add or update param: " << query.lastError();
        return false;
    }
    return true;
}

double DatabaseManager::getParam(const QString &name)
{
    QSqlQuery query;
    query.prepare("SELECT value FROM params WHERE name = :name");
    query.bindValue(":name", name);

    if (!query.exec()) {
        qDebug() << "Failed to retrieve param: " << query.lastError();
        return 0;
    }

    if (query.next()) {
        return query.value(0).toDouble();
    } else {
        qDebug() << "No such parameter found";
        return 0; // Parameter not found
    }
}
