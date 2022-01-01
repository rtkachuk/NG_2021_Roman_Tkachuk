#ifndef POPKROP_H
#define POPKROP_H

#include <QMainWindow>
#include <QWebEngineView>

QT_BEGIN_NAMESPACE
namespace Ui { class PopKrop; }
QT_END_NAMESPACE

class PopKrop : public QMainWindow
{
	Q_OBJECT

public:
	PopKrop(QWidget *parent = nullptr);
	~PopKrop();

private slots:
	void go();
	void urlChanged(QUrl url);

private:
	Ui::PopKrop *ui;
	QWebEngineView *m_browser;
};
#endif // POPKROP_H
