#ifndef SERVAK_H
#define SERVAK_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class Servak : public QTcpServer
{
	Q_OBJECT
public:
	Servak();

private slots:
	void readyRead();
	void droppedConnection();
	void setNickname(QTcpSocket *client, QByteArray data);
	void messageReceived(QTcpSocket *client, QByteArray msg);

protected:
	void incomingConnection(qintptr handle);

private:
	void log(QString msg) { qDebug() << "[Server]: " << msg;}
	void err(QString msg) { qDebug() << "ERROR "  + msg; }

	QVector <QTcpSocket *> m_clients;
	QMap<QTcpSocket *, QString> m_nicknames;
};

#endif // SERVAK_H
