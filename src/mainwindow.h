#pragma once

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include "homescreen.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

private:
	void createMenus();

private slots:
	// Add slots e.g. openFile()

private:
	QMenu* fileMenu;
	QMenu* viewMenu;
	QAction* testFileAction1; // TODO: make actual action
	QAction* testFileAction2; // TODO: make actual action
	QAction* testViewAction1; // TODO: make actual action
	QAction* testViewAction2; // TODO: make actual action
	HomeScreen* homeScreen;
};