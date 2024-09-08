#pragma once

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "gui/peakfit_view.h"

#include "homescreen.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

private slots:
	void showPeakFitView();

private:
	void createMenus();
	QMenu* fileMenu;
	QMenu* viewMenu;
	QMenu* analysisMenu;	
	QAction* peakFitAction; // TODO: make actual action
	QAction* testFileAction2; // TODO: make actual action
	QAction* testViewAction1; // TODO: make actual action
	QAction* testViewAction2; // TODO: make actual action
	HomeScreen* homeScreen;
	PeakFitView* peakFitView;		
};