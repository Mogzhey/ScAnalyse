#include <QApplication>
#include <QMainWindow>

#include "homescreen.h"

int main(int argc, char* argv[])
{
    // Create application
    QApplication app(argc, argv);

    // Create application window
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("ScAnalyse");
    mainWindow.setMinimumSize(640, 480);

    // Add homescreen to application window
    // TODO: Create a QStackedWidget and set as central widget on mainWindow then
    //       add homeScreen (and future other screens) to the QStackedWidget rather
    //       than mainWindow to be able to change the screen shown in mainWindow
    //       without needing to create a new window for each screen.
    //       Will still be possible to make new windows if desired by just calling .show() on widget.
    auto homeScreen = new HomeScreen();
    mainWindow.setCentralWidget(homeScreen);

    // Run application
    mainWindow.show();
    return app.exec();
}