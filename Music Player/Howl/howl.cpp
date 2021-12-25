#include "howl.h"
#include "ui_howl.h"

Howl::Howl(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::Howl)
{
	ui->setupUi(this);

	m_player = new QMediaPlayer();
	ui->e_path->setReadOnly(true);

	connect (ui->b_find, &QPushButton::clicked, this, &Howl::onFindPressed);
	connect (ui->b_playPause, &QPushButton::clicked, this, &Howl::onPlayPressed);
	connect (ui->s_volumeSlider, &QSlider::valueChanged, m_player, &QMediaPlayer::setVolume);
	connect (m_player, &QMediaPlayer::volumeChanged, this, &Howl::volumeChanged);
}

Howl::~Howl()
{
	delete ui;
}

void Howl::onPlayPressed()
{
	m_player->play();
	ui->b_playPause->setText("||");
	disconnect (ui->b_playPause, &QPushButton::clicked, this, &Howl::onPlayPressed);
	connect (ui->b_playPause, &QPushButton::clicked, this, &Howl::onPausePressed);
}

void Howl::onPausePressed()
{
	m_player->pause();
	ui->b_playPause->setText(">");
	disconnect (ui->b_playPause, &QPushButton::clicked, this, &Howl::onPausePressed);
	connect (ui->b_playPause, &QPushButton::clicked, this, &Howl::onPlayPressed);
}

void Howl::onFindPressed()
{
	QString songPath = QFileDialog::getOpenFileName(this, tr("Play music"),
													QDir::homePath(),
													tr("Music (*.mp3)"));
	m_player->setMedia(QUrl::fromLocalFile(songPath));
	ui->e_path->setText(songPath.remove(0, songPath.lastIndexOf("/") + 1).remove(".mp3"));
}

void Howl::volumeChanged(int volume)
{
	ui->l_volumeLabel->setNum(volume);
}
