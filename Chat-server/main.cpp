#include <QCoreApplication>
#include "servak.h"

void log(QString msg) { qDebug() << "[Core]: " << msg;}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Servak *servak = new Servak();
	bool ok = servak->listen(QHostAddress::Any, 8093);
	if (ok) {
		log ("Server started at " + QString::number(8093));
	} else {
		log ("Server crashed!");
		log (servak->errorString());
	}

	return a.exec();
}
