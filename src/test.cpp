#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QString>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("Mainwindow");

    QLabel label("Hello World!", &window);

    window.show();
    return app.exec();
}
