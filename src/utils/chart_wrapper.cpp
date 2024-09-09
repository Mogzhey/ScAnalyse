#include "chart_wrapper.h"
#include "file_loader.h"

ChartWrapper::ChartWrapper()
{	
	chart = new QChart();
	chart_view = new QChartView();
	chart_view->setChart(chart);

	layout = new QVBoxLayout();
	layout->addWidget(chart_view);
	this->setLayout(layout);
}

void ChartWrapper::LoadDataAsSeries(std::string filename, QString title = "")
{
	// Load data into vector from file
	std::vector<std::pair<std::string, std::vector<float>>> data = FileLoader::ReadCSV(filename);
	xdata = data[0].second;
	ydata = data[1].second;

	series = new QLineSeries();

	// Load data vector into chart series
	if (xdata.size() != ydata.size())
		throw std::runtime_error("peak_col and time_col not the same length");

	for (int i = 0; i < xdata.size(); i++) {
		series->append(xdata[i], ydata[i]);
	}

	// Create axes
	x_axis = new QValueAxis();
	x_axis->setTickCount(11);
	x_axis->setTitleText("x values");

	y_axis = new QValueAxis();
	y_axis->setTickCount(11);
	y_axis->setTitleText("y values");

	chart->addSeries(series);
	chart->setAxisX(x_axis, series);
	chart->setAxisY(y_axis, series);

	chart->setTitle(title);

	// Update chart
	chart_view->setChart(chart);
}

void ChartWrapper::Clear() {
	if (sizeof(series) != 1) {
		chart->removeAllSeries();
		chart->removeAxis(x_axis);
		chart->removeAxis(y_axis);
	}
}