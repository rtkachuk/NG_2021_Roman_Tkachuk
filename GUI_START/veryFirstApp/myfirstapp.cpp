#include "myfirstapp.h"
#include "ui_myfirstapp.h"

MyFirstApp::MyFirstApp(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MyFirstApp)
{
	ui->setupUi(this);
	connect(ui->doShit, &QPushButton::clicked, this, &MyFirstApp::mirrorText);
}

MyFirstApp::~MyFirstApp()
{
	delete ui;
}

void MyFirstApp::mirrorText()
{
	QString text = ui->rofliHere->text();
	ui->rofliHere->clear();
	for (int index = text.size() - 1; index >= 0; index--) {
		ui->rofliHere->setText(ui->rofliHere->text() + text[index]);
	}
}

