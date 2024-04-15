#include "databasemanager.h"  // Include the header file for the DatabaseManager definition


/**
 * @brief Constructor for DatabaseManager that initializes the database connection.
 * @param path The path to the SQLite database file.
 */
DatabaseManager::DatabaseManager(const QString &path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");  // Add a SQLite database to the QSqlDatabase object
    db.setDatabaseName(path);  // Set the database file path

    if(!openDB()){  // Attempt to open the database
        qDebug() << "Failed to open database";  // Log an error message if database opening fails
    }
    else{
        if(!createTable()){  // Attempt to create a table if database was successfully opened
            qDebug() << "Failed to create table";  // Log an error message if table creation fails
        }
    }
}


/**
 * @brief Destructor for DatabaseManager that closes the database connection.
 */
DatabaseManager::~DatabaseManager()
{
    db.close();  // Close the database connection
}


/**
 * @brief Opens the database connection.
 * @return true if the database was successfully opened, otherwise false.
 */
bool DatabaseManager::openDB()
{
    if(!db.open()){  // Try to open the database connection
        qDebug() << "Error: connection with database failed";  // Log error if connection fails
        return false;  // Return false if connection fails
    }
    return true;  // Return true if the connection was successful
}


/**
 * @brief Creates a table in the database if it doesn't already exist.
 * @return true if the table was successfully created or already exists, otherwise false.
 */
bool DatabaseManager::createTable()
{
    QSqlQuery query;  // Create a QSqlQuery object to run queries
    bool success = query.exec("CREATE TABLE IF NOT EXISTS params ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                              "name TEXT NOT NULL UNIQUE, "
                              "value REAL NOT NULL)");  // SQL statement to create a table

    if (!success) {
        qDebug() << "Failed to create table: " << query.lastError();  // Log an error message if table creation fails
    }
    return success;  // Return the status of the table creation
}


/**
 * @brief Adds a new parameter or updates an existing one in the database.
 * @param name The name of the parameter.
 * @param value The value of the parameter.
 * @return true if the parameter was successfully added or updated, otherwise false.
 */
bool DatabaseManager::addOrUpdateParam(const QString &name, double value)
{
    QSqlQuery query;  // Create a QSqlQuery object to run queries
    query.prepare("INSERT OR REPLACE INTO params (name, value) VALUES (:name, :value)");  // Prepare an SQL query to insert or replace parameters
    query.bindValue(":name", name);  // Bind the name value to the query
    query.bindValue(":value", value);  // Bind the value to the query

    if (!query.exec()) {  // Execute the query
        qDebug() << "Failed to add or update param: " << query.lastError();  // Log error if query execution fails
        return false;  // Return false if execution fails
    }
    return true;  // Return true if execution was successful
}


/**
 * @brief Retrieves the value of a parameter from the database.
 * @param name The name of the parameter to retrieve.
 * @return The value of the parameter, or 0 if the parameter does not exist.
 */
double DatabaseManager::getParam(const QString &name)
{
    QSqlQuery query;  // Create a QSqlQuery object to run queries
    query.prepare("SELECT value FROM params WHERE name = :name");  // Prepare an SQL query to select the value of a parameter
    query.bindValue(":name", name);  // Bind the name value to the query

    if (!query.exec()) {  // Execute the query
        qDebug() << "Failed to retrieve param: " << query.lastError();  // Log error if query execution fails
        return 0;  // Return 0 if execution fails
    }

        if (query.next()) {  // Check if the query result contains at least one row
        return query.value(0).toDouble();  // Retrieve the first column of the row and convert it to double
    } else {
        qDebug() << "No such parameter found";  // Log a message if no rows were returned (parameter not found)
        return 0; // Return 0 indicating that the parameter was not found
    }

}
