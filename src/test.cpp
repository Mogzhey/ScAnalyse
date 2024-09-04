#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>
#include <QSize>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Mainwindow");
    mainWindow.setMinimumSize(640, 480);

    QWidget window(&mainWindow);
    mainWindow.setCentralWidget(&window);

    QVBoxLayout layout(&window);
    window.setLayout(&layout);

    QLabel label1("Label 1");
    QLabel label2("Label 2");
    QLabel label3("Label 3");

    layout.addWidget(&label1);
    layout.addWidget(&label2);
    layout.addWidget(&label3);

    mainWindow.show();
    return app.exec();
}
