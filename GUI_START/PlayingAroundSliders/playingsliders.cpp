#include "playingsliders.h"
#include "ui_playingsliders.h"

PlayingSliders::PlayingSliders(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::PlayingSliders)
{
	ui->setupUi(this);
	connect (ui->b_1, &QPushButton::clicked, this, &PlayingSliders::buttonPressed);
	connect (ui->b_2, &QPushButton::clicked, this, &PlayingSliders::buttonPressed);
}

PlayingSliders::~PlayingSliders()
{
	delete ui;
}

void PlayingSliders::buttonPressed()
{
	QPushButton *button = (QPushButton*)sender();

	if (button == ui->b_1) appendData("1");
	if (button == ui->b_2) appendData("2");
}

void PlayingSliders::appendData(QString text)
{
	ui->m_data->setText(ui->m_data->text() + text);
}
