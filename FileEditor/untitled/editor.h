#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class Editor; }
QT_END_NAMESPACE

class Editor : public QMainWindow
{
	Q_OBJECT

public:
	Editor(QWidget *parent = nullptr);
	~Editor();

private slots:
	void save();
	void load();

private:
	bool isPathEmpty();

	Ui::Editor *ui;
};
#endif // EDITOR_H
