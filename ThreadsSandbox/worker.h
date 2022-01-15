#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QRandomGenerator>

class Worker : public QThread
{
	Q_OBJECT
	void run() override;

public:
	Worker();

signals:
	void valueChanged(int);
};

#endif // WORKER_H
