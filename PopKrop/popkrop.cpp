#include "popkrop.h"
#include "ui_popkrop.h"

PopKrop::PopKrop(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::PopKrop)
{
	ui->setupUi(this);
	m_browser = new QWebEngineView();
	ui->browserPlace->addWidget(m_browser);
	ui->pb_load->hide();

	ui->b_go->setStyleSheet("border-radius: 5px;"
							"border-width: 1px;"
							"border-color: black;"
							"border-style: solid;");

	connect (ui->b_go, &QPushButton::clicked, this, &PopKrop::go);
	connect (m_browser, &QWebEngineView::urlChanged, this, &PopKrop::urlChanged);

	connect (m_browser, &QWebEngineView::loadStarted, ui->pb_load, &QProgressBar::show);
	connect (m_browser, &QWebEngineView::loadProgress, ui->pb_load, &QProgressBar::setValue);
	connect (m_browser, &QWebEngineView::loadFinished, ui->pb_load, &QProgressBar::hide);
}

PopKrop::~PopKrop()
{
	delete ui;
}

void PopKrop::go()
{
	QString url = ui->e_url->text();
	if (url.indexOf("http://") == -1 && url.indexOf("https://") == -1)
		url = "http://" + url;
	m_browser->load(url);
}

void PopKrop::urlChanged(QUrl url)
{
	ui->e_url->setText(url.toString());
}

