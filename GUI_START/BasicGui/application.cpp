#include "application.h"
#include "ui_application.h"

Application::Application(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::Application)
{
	ui->setupUi(this);

	// Created by us (12, 13)

	connect (ui->clearLetter, &QPushButton::clicked, ui->data, &QLineEdit::clear);
	connect (ui->data, &QLineEdit::textChanged, this, &Application::calculateSpacebars);
}

Application::~Application()
{
	delete ui;
}

// Created by us (23-27)

void Application::calculateSpacebars()
{
	QString text = ui->data->text();
	ui->spacesAmount->setNum(text.count(' '));
}


