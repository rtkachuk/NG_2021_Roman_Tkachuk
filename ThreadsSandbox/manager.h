#ifndef MANAGER_H
#define MANAGER_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QLayout>
#include "worker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Manager; }
QT_END_NAMESPACE

class Manager : public QMainWindow
{
	Q_OBJECT

public:
	Manager(QWidget *parent = nullptr);
	~Manager();

private slots:
	void start();
	void addWorker();

private:
	Ui::Manager *ui;
	QVector<Worker*> m_workers;


};
#endif // MANAGER_H
