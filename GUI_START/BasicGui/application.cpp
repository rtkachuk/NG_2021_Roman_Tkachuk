#include "application.h"
#include "ui_application.h"

Application::Application(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::Application)
{
	ui->setupUi(this);

	connect (ui->clearLetter, &QPushButton::clicked, ui->data, &QLineEdit::clear);
	connect (ui->data, &QLineEdit::textChanged, this, &Application::calculateSpacebars);
}

Application::~Application()
{
	delete ui;
}

void Application::calculateSpacebars()
{
	QString text = ui->data->text();
	ui->spacesAmount->setText(QString::number(text.count(' ')));
}


