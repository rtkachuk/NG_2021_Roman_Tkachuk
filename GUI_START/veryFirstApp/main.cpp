#include "myfirstapp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyFirstApp w;
	w.show();
	return a.exec();
}
