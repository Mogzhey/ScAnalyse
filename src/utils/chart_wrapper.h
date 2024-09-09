#pragma once

#include <QVBoxLayout>

#include <QWidget>
#include <QChartView>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>

class ChartWrapper : public QWidget 
{
	Q_OBJECT

public:

	ChartWrapper();

	void LoadDataAsSeries(std::string filename, QString title);
	void Clear();

	QVBoxLayout* layout;

	QChart* chart;
	QChartView* chart_view;
	QLineSeries* series;
	QValueAxis* x_axis;
	QValueAxis* y_axis;

	std::vector<float> xdata;
	std::vector<float> ydata;
};