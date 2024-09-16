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
#include <QComboBox>
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
	QWidget* load_file_form;
	QWidget* peak_fit_form;
	QWidget* menu_container;

	QHBoxLayout* layout;
	QVBoxLayout* menu_layout;
	QFormLayout* load_file_form_layout;
	QFormLayout* peak_fit_form_layout;

	QLabel* import_file_form_title;
	QLabel* import_file_label;
	QLabel* label1;
	QLabel* figure_title_label;

	QLabel* peak_fit_menu_label;
	QLabel* peak_fit_function_label;

	QLabel* peak_fit_xlim1_label;
	QLabel* peak_fit_xlim2_label;
	QLabel* gaussian_mean_label;
	QLabel* gaussian_sigma_label;
	QLabel* gaussian_intensity_label;

	QTextEdit* import_file_text_edit;
	QTextEdit* figure_title_text_edit;
	QTextEdit* text_edit2;

	QTextEdit* peak_fit_xlim1_text_edit;
	QTextEdit* peak_fit_xlim2_text_edit;
	QTextEdit* gaussian_mean_text_edit;
	QTextEdit* gaussian_sigma_text_edit;
	QTextEdit* gaussian_intensity_text_edit;

	QComboBox* peak_fit_function_combo_box;

	QPushButton* load_file_button;
	QPushButton* peak_fit_button;
	std::string filename;
};