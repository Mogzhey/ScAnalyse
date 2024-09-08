#include "peakfit_view.h"
#include "../peakfit/peakfit.h"
#include "../utils/file_loader.h"

PeakFitView::PeakFitView(QWidget* parent) : QWidget(parent) 
{
	this->parent = parent;
	this->setMinimumSize(1000, 600);

	// create containers and layouts
	container = new QWidget(this);
	container_layout = new QGridLayout();

	form = new QWidget();
	form->setMaximumHeight(50);
	form_layout = new QFormLayout();

	// set up plot view
	plot_view = new QChartView();
	plot = new QChart();
	this->setupChart();


	// set up fitting controls
	import_file_label = new QLabel("File path");
	label1 = new QLabel();
	label2 = new QLabel();

	import_file_text_edit = new QTextEdit();
	text_edit1 = new QTextEdit();
	text_edit2 = new QTextEdit();

	// add everything to layout
	form->setLayout(form_layout);
	form_layout->addRow(import_file_label, import_file_text_edit);

	container->setLayout(container_layout);
	container_layout->addWidget(plot_view, 0, 1);
	container_layout->addWidget(form, 0, 0);


	auto data = read_csv("../test_data/Am241_GE1_1.CSV");
}

void PeakFitView::setupChart() {
	/* 
	
	TODO: Make some data loading utillity thing elsewhere and call it here to put it into the figure.

	*/
	// Create chart
	auto chart = new QChart();
	chart->setTitle("Test Plot");

	// Create axes
	auto xAxis = new QValueAxis();
	xAxis->setTickCount(11);
	xAxis->setTitleText("x values");

	auto yAxis = new QValueAxis();
	yAxis->setTickCount(11);
	yAxis->setTitleText("y values");

	// Create line of y = x^2
	QLineSeries* series = new QLineSeries();
	for (float x = -10.0f; x <= 10.0f; x += 0.2f)
	{
		series->append(x, x * x);
	}
	series->setName("y = x^2");

	// Add line to chart
	chart->addSeries(series);

	// Add axes to chart
	chart->setAxisX(xAxis, series);
	chart->setAxisY(yAxis, series);

	// Add chart to plot
	this->plot_view->setChart(chart);

	read_csv("../test_data/Am241_GE1_1");
}

