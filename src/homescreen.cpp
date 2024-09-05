#include "homescreen.h"

HomeScreen::HomeScreen(QWidget* parent) : QWidget(parent)
{
	this->parent = parent;

	// Create layout
	layout = new QGridLayout(this);
	this->setLayout(layout);

	// Create labels
	label11 = new QLabel("ROW1 COL1");
	label21 = new QLabel("ROW2 COL1");

	// Create plot
	plot = new QChartView();
	createTestPlot(plot);

	// Add labels and plot to layout
	layout->addWidget(label11, 1, 1);
	layout->addWidget(label21, 2, 1);
	layout->addWidget(plot, 1, 2, 2, 1);
}

void HomeScreen::createTestPlot(QChartView* parent)
{
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
		series->append(x, x*x);
	}
	series->setName("y = x^2");

	// Add line to chart
	chart->addSeries(series);

	// Add axes to chart
	chart->setAxisX(xAxis, series);
	chart->setAxisY(yAxis, series);

	// Add chart to plot
	plot->setChart(chart);
}