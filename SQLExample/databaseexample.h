#ifndef DATABASEEXAMPLE_H
#define DATABASEEXAMPLE_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class DatabaseExample; }
QT_END_NAMESPACE

class DatabaseExample : public QMainWindow
{
	Q_OBJECT

public:
	DatabaseExample(QWidget *parent = nullptr);
	~DatabaseExample();

private slots:
	void add();
	void refresh();
	void del();

private:
	QSqlDatabase db;
	Ui::DatabaseExample *ui;
};
#endif // DATABASEEXAMPLE_H
