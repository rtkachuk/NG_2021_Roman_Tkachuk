#ifndef MYFIRSTAPP_H
#define MYFIRSTAPP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MyFirstApp; }
QT_END_NAMESPACE

class MyFirstApp : public QMainWindow
{
	Q_OBJECT

public:
	MyFirstApp(QWidget *parent = nullptr);
	~MyFirstApp();

private:
	void mirrorText();

	Ui::MyFirstApp *ui;
};
#endif // MYFIRSTAPP_H
