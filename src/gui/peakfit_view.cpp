#include "peakfit_view.h"
#include "../peakfit/peakfit.h"
#include "../utils/file_loader.h"
#include "../utils/chart_wrapper.h"
#include <iostream>

PeakFitView::PeakFitView(QWidget* parent) : QWidget(parent), parent(parent)
{
	// create containers and layouts
	layout = new QHBoxLayout();

	form = new QWidget();
	form->setMaximumSize(400, 150);
	form_layout = new QFormLayout();

	menu_container = new QWidget();
	menu_container->setMaximumSize(400, 150);
	menu_layout = new QVBoxLayout();

	// set up chart view
	chart = new ChartWrapper();

	// set up fitting controls
	import_file_form_title = new QLabel("Import file to load");
	import_file_form_title->setFont(QFont("Arial", 16));
	import_file_form_title->setMaximumHeight(50);

	import_file_label = new QLabel("File path");
	label1 = new QLabel("go!!!");
	figure_title_label = new QLabel("Figure title");

	import_file_text_edit = new QTextEdit("Am241_GE1_1.CSV");
	figure_title_text_edit = new QTextEdit("");

	load_file_button = new QPushButton("Load file");
	connect(load_file_button, &QPushButton::released, this, &PeakFitView::onLoadFileClick);

	// add everything to layout
	form->setLayout(form_layout);
	form_layout->addRow(import_file_label, import_file_text_edit);
	form_layout->addRow(figure_title_label, figure_title_text_edit);
	form_layout->addRow(label1, load_file_button);

	form->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

	menu_container->setLayout(menu_layout);
	menu_layout->addWidget(import_file_form_title);
	menu_layout->addWidget(form);

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

