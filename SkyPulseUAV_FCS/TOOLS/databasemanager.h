#ifndef DATABASEMANAGER_H  // Prevents the header file from being included multiple times in the same compilation unit
#define DATABASEMANAGER_H


#include <QSqlDatabase>  // Include the QSqlDatabase class for handling database connections
#include <QSqlQuery>     // Include the QSqlQuery class for executing SQL queries
#include <QSqlError>     // Include the QSqlError class for handling SQL errors
#include <QDebug>        // Include the QDebug class for logging debug messages


/**
 * @class DatabaseManager
 * @brief Manages a database connection and performs common database operations.
 *
 * This class is designed to handle the database interactions such as opening
 * connections, creating tables, and performing data insertions or updates.
 */
class DatabaseManager
{
public:
    /**
     * @brief Constructs a DatabaseManager object and opens a database connection.
     * @param path The filesystem path to the SQLite database file.
     */
    DatabaseManager(const QString &path);

    /**
     * @brief Destroys the DatabaseManager object and closes the database connection.
     */
    ~DatabaseManager();

    /**
     * @brief Adds a new parameter to the database or updates it if it already exists.
     * @param name The name of the parameter to add or update.
     * @param value The numerical value of the parameter.
     * @return Returns true if the operation was successful, false otherwise.
     */
    bool addOrUpdateParam(const QString &name, double value);

    /**
     * @brief Retrieves the value of a parameter from the database by name.
     * @param name The name of the parameter to retrieve.
     * @return The value of the parameter if found, otherwise returns 0.
     */
    double getParam(const QString &name);

private:
    QSqlDatabase db;  // Holds the database connection object

    /**
     * @brief Opens a connection to the database specified by the db member.
     * @return Returns true if the connection was successfully opened, false otherwise.
     */
    bool openDB();

    /**
     * @brief Creates a table in the database to store parameters if it does not already exist.
     * @return Returns true if the table was successfully created or already exists, false otherwise.
     */
    bool createTable();

};


#endif // DATABASEMANAGER_H
