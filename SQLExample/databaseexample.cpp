#include "databaseexample.h"
#include "ui_databaseexample.h"

DatabaseExample::DatabaseExample(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DatabaseExample)
{
	ui->setupUi(this);

	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("/tmp/exampledb.db");
	if (db.open() == false) {
		qDebug() << "Error opening database: " << db.lastError().databaseText();
	}

	ui->n_year->setRange(1960, 2050);

	refresh();

	connect (ui->b_add, &QPushButton::clicked, this, &DatabaseExample::add);
	connect (ui->b_refresh, &QPushButton::clicked, this, &DatabaseExample::refresh);
	connect (ui->b_delete, &QPushButton::clicked, this, &DatabaseExample::del);
}

DatabaseExample::~DatabaseExample()
{
	db.close();
	delete ui;
}

void DatabaseExample::add()
{
	QString cmd = QString("INSERT INTO CPU (Name, Year, Frequency) VALUES ('%1', %2, '%3');")
			.arg(ui->e_name->text())
			.arg(ui->n_year->value())
			.arg(ui->e_freq->text());
	qDebug() << cmd;

	QSqlQuery query;
	bool ok = query.exec(cmd);
	if (ok == false) {
		QMessageBox::critical(this, "Error adding data", query.lastError().databaseText());
	}
}

void DatabaseExample::refresh()
{
	ui->t_data->clear();
	ui->t_data->setRowCount(0);
	ui->t_data->setColumnCount(4);
	ui->t_data->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
	ui->t_data->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
	ui->t_data->setHorizontalHeaderItem(2, new QTableWidgetItem("Year"));
	ui->t_data->setHorizontalHeaderItem(3, new QTableWidgetItem("Frequency"));

	QSqlQuery query;
	bool ok = query.exec("SELECT * FROM CPU;");
	if (ok == false) {
		QMessageBox::critical(this, "Error loading data", query.lastError().databaseText());
		return;
	}

	int currentRow = 0;

	while (query.next()) {
		QString id = query.value("ID").toString();
		QString name = query.value("Name").toString();
		QString year = query.value("Year").toString();
		QString freq = query.value("Frequency").toString();

		ui->t_data->insertRow(ui->t_data->rowCount());

		ui->t_data->setItem(currentRow, 0, new QTableWidgetItem(id));
		ui->t_data->setItem(currentRow, 1, new QTableWidgetItem(name));
		ui->t_data->setItem(currentRow, 2, new QTableWidgetItem(year));
		ui->t_data->setItem(currentRow, 3, new QTableWidgetItem(freq));
		currentRow++;
	}
}

void DatabaseExample::del()
{
	QSqlQuery query;
	bool ok = query.exec(QString("DELETE FROM CPU WHERE Name='%1';").arg(ui->e_name_delete->text()));
	if (ok == false) {
		QMessageBox::critical(this, "Error loading data", query.lastError().databaseText());
		return;
	}
}

