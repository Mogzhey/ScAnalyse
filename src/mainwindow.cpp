#include "mainwindow.h"
#include "gui/peakfit_view.h"

MainWindow::MainWindow()
{
    // Setup window
    this->setWindowTitle("ScAnalyse");
    this->setMinimumSize(640, 480);

    // Set up menubar
    createMenus();

    // Add homescreen to application window
    // TODO: Create a QStackedWidget and set as central widget on mainWindow then
    //       add homeScreen (and future other screens) to the QStackedWidget rather
    //       than mainWindow to be able to change the screen shown in mainWindow
    //       without needing to create a new window for each screen.
    //       Will still be possible to make new windows if desired by just calling .show() on widget.
    homeScreen = new HomeScreen();
    this->setCentralWidget(homeScreen);
}

void MainWindow::createMenus()
{
    // Create menus
    fileMenu = menuBar()->addMenu(tr("File"));
    viewMenu = menuBar()->addMenu(tr("View"));
    analysisMenu = menuBar()->addMenu(tr("Analysis"));

    // Create actions
    peakFitAction = new QAction(tr("Fit peaks"));
    testFileAction2 = new QAction(tr("Test 2"));

    testViewAction1 = new QAction(tr("Test 1"));
    testViewAction2 = new QAction(tr("Test 2"));

    // Add actions to menus
    analysisMenu->addAction(peakFitAction);
    fileMenu->addAction(testFileAction2);

    viewMenu->addAction(testViewAction1);
    viewMenu->addAction(testViewAction2);

    // TODO: connect slots to menu action signals
    connect(peakFitAction, &QAction::triggered, this, &MainWindow::showPeakFitView);

}

void MainWindow::showPeakFitView()
{
    peakFitView = new PeakFitView();
    peakFitView->show();
}
