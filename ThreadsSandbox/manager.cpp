#include "manager.h"
#include "ui_manager.h"

Manager::Manager(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::Manager)
{
	ui->setupUi(this);

	connect (ui->b_add, &QPushButton::clicked, this, &Manager::addWorker);
	connect (ui->b_start, &QPushButton::clicked, this, &Manager::start);
}

Manager::~Manager()
{
	delete ui;
}

void Manager::start()
{
	// Just start all created Threads from our array (Vector)

	for (Worker *buffer : m_workers) {
		buffer->start();
	}
}

void Manager::addWorker()
{
	// Create Thread and save it to array (Vector)

	Worker *worker = new Worker();
	m_workers.append(worker);

	// Only graphical stuff: add progress bar
	//

	QHBoxLayout *layout = new QHBoxLayout();
	QLabel *m_label = new QLabel("Task " + QString::number(m_workers.size()));
	QProgressBar *progress = new QProgressBar();

	layout->addWidget(m_label);
	layout->addWidget(progress);
	ui->verticalLayout->addLayout(layout);

	// Just connect new Thread to our progressbar

	connect (worker, &Worker::valueChanged, progress, &QProgressBar::setValue);
}

