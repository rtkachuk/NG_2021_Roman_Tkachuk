#ifndef PLAYINGSLIDERS_H
#define PLAYINGSLIDERS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PlayingSliders; }
QT_END_NAMESPACE

class PlayingSliders : public QMainWindow
{
	Q_OBJECT

public:
	PlayingSliders(QWidget *parent = nullptr);
	~PlayingSliders();

private slots:
	void buttonPressed();

private:
	void appendData(QString text);
	Ui::PlayingSliders *ui;
};
#endif // PLAYINGSLIDERS_H
