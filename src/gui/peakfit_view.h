#pragma once
#include <QWidget>
#include <QGridLayout>
#include <QFormLayout>

#include <QChartView>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>

#include <QLabel>
#include <QTextEdit>
#include <vector>

class PeakFitView : public QWidget
{
	Q_OBJECT

public:
	PeakFitView(QWidget* parent = nullptr);

private:
	void setupChart();
	void updateChart();
	
	QWidget* parent;
	QWidget* container;
	QWidget* form;

	QGridLayout* container_layout;
	QFormLayout* form_layout;

	QChartView* plot_view;
	QChart* plot;
	QLineSeries* series;
	QValueAxis* value_axes;

	QLabel* import_file_label;
	QLabel* label1;
	QLabel* label2;

	QTextEdit* import_file_text_edit;
	QTextEdit* text_edit1;
	QTextEdit* text_edit2;
};