#ifndef CLIENTS_H
#define CLIENTS_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QScrollBar>

QT_BEGIN_NAMESPACE
namespace Ui { class Clients; }
QT_END_NAMESPACE

class Clients : public QMainWindow
{
	Q_OBJECT

public:
	Clients(QWidget *parent = nullptr);
	~Clients();

private slots:
	void connected();
	void disconnected();
	void doConnection();
	void send();
	void received();

private:
	Ui::Clients *ui;
	QTcpSocket *m_socket;
};
#endif // CLIENTS_H
