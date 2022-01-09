#include "databaseexample.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DatabaseExample w;
	w.show();
	return a.exec();
}
