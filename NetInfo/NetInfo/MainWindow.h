#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class QTextDocument;
class QString;

#include <QtGui/QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;

	//QTextDocument *pDoc;


public slots:
	void showNetInfo();
};

#endif // MAINWINDOW_H
