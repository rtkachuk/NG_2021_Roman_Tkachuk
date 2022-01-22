#include "clients.h"
#include "ui_clients.h"

Clients::Clients(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::Clients)
{
	ui->setupUi(this);
	m_socket = new QTcpSocket();

	ui->s_port->setMaximum(65535);

	connect (m_socket, &QTcpSocket::connected, this, &Clients::connected);
	connect (m_socket, &QTcpSocket::disconnected, this, &Clients::disconnected);
	connect (ui->b_connect, &QPushButton::clicked, this, &Clients::doConnection);
	connect (ui->b_send, &QPushButton::clicked, this, &Clients::send);
	connect (m_socket, &QTcpSocket::readyRead, this, &Clients::received);
}

Clients::~Clients()
{
	delete ui;
}

void Clients::connected()
{
	ui->stackedWidget->setCurrentIndex(1);
	m_socket->write(QString("c:::n" + ui->e_nick->text()).toUtf8());
}

void Clients::disconnected()
{
	ui->stackedWidget->setCurrentIndex(0);
}

void Clients::doConnection()
{
	QString host = ui->e_ip->text();
	int port = ui->s_port->value();
	m_socket->connectToHost(host, port);
}

void Clients::send()
{
	m_socket->write(QString("c:::m" + ui->te_input->toPlainText()).toUtf8());
}

void Clients::received()
{
	ui->te_chat->setText(ui->te_chat->toHtml() + "\n" + m_socket->readAll());
	ui->te_chat->verticalScrollBar()->setValue(ui->te_chat->verticalScrollBar()->maximum());
}

