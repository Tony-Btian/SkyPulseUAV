#include "mainwindow.h"  // Includes the header file for the MainWindow class
#include <QApplication>  // Includes QApplication class which is essential for all Qt applications
#include <QLocale>       // Includes QLocale class for localization
#include <QTranslator>   // Includes QTranslator class for translations

/**
 * @brief Entry point for the application.
 * @param argc The count of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return Integer as the exit code of the application.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // Constructs the QApplication object with argc and argv, necessary for all Qt apps.

    QTranslator translator;  // Create a QTranslator object for managing translations.
    const QStringList uiLanguages = QLocale::system().uiLanguages();  // Get the preferred UI languages for the system.
    for (const QString &locale : uiLanguages) {  // Iterate through each locale in the system's preferred UI languages.
        const QString baseName = "SkyPulseUAV_GroundStation_" + QLocale(locale).name();  // Construct the base name for the translation files.
        if (translator.load(":/i18n/" + baseName)) {  // Attempt to load the translation file from the resource path.
            a.installTranslator(&translator);  // If loading succeeds, install the translator into the QApplication.
            break;  // Break the loop after successfully loading a translation to avoid unnecessary processing.
        }
    }
    MainWindow w;  // Create an instance of MainWindow.
    w.show();  // Show the main window.
    return a.exec();  // Enter the main event loop and return the exit code upon exit.

}
