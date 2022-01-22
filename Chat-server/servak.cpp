#include "servak.h"

Servak::Servak()
{

}

void Servak::incomingConnection(qintptr handle)
{
	QTcpSocket *client = new QTcpSocket();
	client->setSocketDescriptor(handle);

	m_clients.append(client);
	log ("New client connected! [" + client->localAddress().toString() + "]");

	connect (client, &QTcpSocket::disconnected, this, &Servak::droppedConnection);
	connect (client, &QTcpSocket::readyRead, this, &Servak::readyRead);
}

void Servak::readyRead()
{
	QTcpSocket *client = (QTcpSocket *)sender();

	QByteArray data = client->readAll();
	if (data.indexOf("c:::n") == 0) { setNickname(client, data); return; }
	if (data.indexOf("c:::m") == 0) { messageReceived(client, data); return; }

	log(data);

	err("Command cannot be parsed");
}

void Servak::droppedConnection()
{
	QTcpSocket *client = (QTcpSocket *)sender();
	m_clients.remove(m_clients.indexOf(client));
	m_nicknames[client] = "annonymous";
	log ("Client dropped connection!");

	connect (client, &QTcpSocket::disconnected, this, &Servak::droppedConnection);
	connect (client, &QTcpSocket::readyRead, this, &Servak::readyRead);
}

void Servak::setNickname(QTcpSocket *client, QByteArray data)
{
	data.remove(0, QByteArray("c:::n").length());
	m_nicknames[client] = data;
	log ("Added nickname: " + data);
}

void Servak::messageReceived(QTcpSocket *client, QByteArray msg)
{
	msg.remove(0, QByteArray("c:::m").length());
	QByteArray data = QString(m_nicknames[client] + ":" + msg).toUtf8();

	for (QTcpSocket *socket : m_clients) {
		socket->write(data);
	}
}
