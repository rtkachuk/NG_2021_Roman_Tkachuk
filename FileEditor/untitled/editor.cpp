#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::Editor)
{
	ui->setupUi(this);
	connect (ui->b_save, &QPushButton::clicked, this, &Editor::save);
	connect (ui->b_load, &QPushButton::clicked, this, &Editor::load);
}

Editor::~Editor()
{
	delete ui;
}

void Editor::save()
{
	if (isPathEmpty()) return;

	QString path = ui->e_path->text();

	QFile file(path);
	if (file.open(QIODevice::ReadWrite) == false) {
		QMessageBox::critical(this, "Страшная ошибка!", file.errorString());
		return;
	}

	QTextStream in(&file);
	QString text = ui->e_text->toPlainText();
	in << text;
	file.close();

	ui->statusbar->showMessage("File saved to " + path);
}

void Editor::load()
{
	if (isPathEmpty()) return;

	QString path = ui->e_path->text();

	QFile file(path);
	if (file.open(QIODevice::ReadWrite) == false) {
		QMessageBox::critical(this, "Страшная ошибка!", file.errorString());
		return;
	}

	QTextStream out(&file);
	ui->e_text->setPlainText(out.readAll());
	file.close();

	ui->statusbar->showMessage("File " + path + " successfully loaded!");
}

bool Editor::isPathEmpty()
{
	if (ui->e_path->text().isEmpty()) {
		QMessageBox::critical(this, "Страшная ошибка!", "Путь к файлу не может быть пустым!");
		return true;
	}
	return false;
}

