#include "peakfit_view.h"
#include "../peakfit/peakfit.h"
#include "../utils/file_loader.h"
#include "../utils/chart_wrapper.h"
#include <iostream>

PeakFitView::PeakFitView(QWidget* parent) : QWidget(parent), parent(parent)
{
	// create containers and layouts
	layout = new QHBoxLayout();

	load_file_form = new QWidget();
	load_file_form->setMaximumSize(400, 150);
	load_file_form_layout = new QFormLayout();

	peak_fit_form = new QWidget();
	peak_fit_form->setMaximumSize(400, 200);
	peak_fit_form_layout = new QFormLayout();

	menu_container = new QWidget();
	menu_container->setMaximumWidth(400);
	menu_layout = new QVBoxLayout();

	// set up chart view
	chart = new ChartWrapper();

	// set up plotting controls
	import_file_form_title = new QLabel("Import file to load");
	import_file_form_title->setFont(QFont("Arial", 16));
	import_file_form_title->setMaximumHeight(50);

	import_file_label = new QLabel("File path");
	import_file_text_edit = new QTextEdit("Am241_GE1_1.CSV");

	figure_title_label = new QLabel("Figure title");
	figure_title_text_edit = new QTextEdit("");

	label1 = new QLabel("go!!!");
	load_file_button = new QPushButton("Load file");
	connect(load_file_button, &QPushButton::released, this, &PeakFitView::onLoadFileClick);

	// add file load form elements to layout
	load_file_form->setLayout(load_file_form_layout);
	load_file_form_layout->addRow(import_file_label, import_file_text_edit);
	load_file_form_layout->addRow(figure_title_label, figure_title_text_edit);
	load_file_form_layout->addRow(label1, load_file_button);

	// set up fitting controls
	peak_fit_menu_label = new QLabel("Fit function to data");
	peak_fit_menu_label->setFont(QFont("Arial", 16));

	peak_fit_function_label = new QLabel("Select fitting function");
	peak_fit_function_combo_box = new QComboBox();

	peak_fit_xlim1_label = new QLabel("Start at");
	peak_fit_xlim1_text_edit = new QTextEdit();

	peak_fit_xlim2_label = new QLabel("Stop at");
	peak_fit_xlim2_text_edit = new QTextEdit();

	gaussian_mean_label = new QLabel("Initial mean");
	gaussian_mean_text_edit = new QTextEdit();

	gaussian_sigma_label = new QLabel("Initial sigma");
	gaussian_sigma_text_edit = new QTextEdit();

	gaussian_intensity_label = new QLabel("Initial intensity");
	gaussian_intensity_text_edit = new QTextEdit();

	peak_fit_button = new QPushButton("Fit");

	peak_fit_form->setLayout(peak_fit_form_layout);
	//peak_fit_form_layout->addRow(peak_fit_function_label, peak_fit_function_combo_box);
	peak_fit_form_layout->addRow(peak_fit_xlim1_label, peak_fit_xlim1_text_edit);
	peak_fit_form_layout->addRow(peak_fit_xlim2_label, peak_fit_xlim2_text_edit);
	peak_fit_form_layout->addRow(gaussian_mean_label, gaussian_mean_text_edit);
	peak_fit_form_layout->addRow(gaussian_sigma_label, gaussian_sigma_text_edit);
	peak_fit_form_layout->addRow(gaussian_intensity_label, gaussian_intensity_text_edit);
	peak_fit_form_layout->addRow(label1, peak_fit_button);


	// Add all container widgets to main layout
	load_file_form->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

	menu_container->setLayout(menu_layout);
	menu_layout->addWidget(import_file_form_title);
	menu_layout->addWidget(load_file_form);
	menu_layout->addWidget(peak_fit_menu_label);
	menu_layout->addWidget(peak_fit_form);

	this->setLayout(layout);
	layout->addWidget(menu_container, 0, Qt::AlignmentFlag::AlignTop);
	layout->addWidget(chart);
}

void PeakFitView::onLoadFileClick() {
	std::string filename_input = import_file_text_edit->toPlainText().toStdString();
	filename = "../../test_data/" + filename_input;

	chart->Clear();
	chart->LoadDataAsSeries(filename, figure_title_text_edit->toPlainText());
}

