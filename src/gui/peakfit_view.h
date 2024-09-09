#pragma once
#include <QWidget>
#include <QHBoxLayout>
#include <QFormLayout>

#include <QChartView>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>

#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <vector>
#include "../utils/chart_wrapper.h"

class PeakFitView : public QWidget
{
	Q_OBJECT

public:
	PeakFitView(QWidget* parent = nullptr);

private:

	void onLoadFileClick();

	std::vector<std::pair<std::string, std::vector<float>>> data;
	std::vector<float> time_col;
	std::vector<float> peak_col;
	
	ChartWrapper* chart;
	QWidget* parent;
	QWidget* form;
	QWidget* menu_container;

	QHBoxLayout* layout;
	QVBoxLayout* menu_layout;
	QFormLayout* form_layout;

	QLabel* import_file_form_title;
	QLabel* import_file_label;
	QLabel* label1;
	QLabel* figure_title_label;

	QTextEdit* import_file_text_edit;
	QTextEdit* figure_title_text_edit;
	QTextEdit* text_edit2;

	QPushButton* load_file_button;
	std::string filename;
};