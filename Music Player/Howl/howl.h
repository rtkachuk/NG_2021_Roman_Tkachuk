#ifndef HOWL_H
#define HOWL_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class Howl; }
QT_END_NAMESPACE

class Howl : public QMainWindow
{
	Q_OBJECT

public:
	Howl(QWidget *parent = nullptr);
	~Howl();

private slots:
	void onPlayPressed();
	void onPausePressed();
	void onFindPressed();

	void volumeChanged(int volume);

private:
	Ui::Howl *ui;
	QMediaPlayer *m_player;
};
#endif // HOWL_H
