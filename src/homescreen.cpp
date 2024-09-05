#include "homescreen.h"

HomeScreen::HomeScreen(QWidget* parent) : QWidget(parent)
{
	this->parent = parent;

	// Create layout
	layout = new QGridLayout(this);
	this->setLayout(layout);

	// Create labels
	label11 = new QLabel("TL");
	label12 = new QLabel("TR");
	label21 = new QLabel("BL");
	label22 = new QLabel("BR");

	// Add labels to layout
	layout->addWidget(label11, 1, 1);
	layout->addWidget(label12, 1, 2);
	layout->addWidget(label21, 2, 1);
	layout->addWidget(label22, 2, 2);
}