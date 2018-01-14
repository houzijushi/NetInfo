#include "MainWindow.h"
#include <QTextDocument>
#include <QString>
#include <QHostInfo>
#include <QHostAddress>
#include <QNetworkInterface>

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	//pDoc = new QTextDocument;
	//ui.textEditNetInfoArea->setDocument(pDoc);

	connect(ui.pushButtonShowNetInfo, SIGNAL(clicked()), this, SLOT(showNetInfo()));

}

MainWindow::~MainWindow()
{

}

void MainWindow::showNetInfo()
{
	ui.textEditNetInfoArea->clear();

	QHostInfo hostInfo;

	//**********获取本机用户名
	ui.textEditNetInfoArea->append("**********Local User Name:");
	QString name = qgetenv("USERNAME");
	ui.textEditNetInfoArea->append(name);

	//**********获取本机主机名，也可以通过主机名来查找IP地址，或者通过IP地址来反向查找主机名。
	ui.textEditNetInfoArea->append("**********Local Host Name:");
	QString localHostName = QHostInfo::localHostName();
	ui.textEditNetInfoArea->append(localHostName);
	//qDebug() << "LocalHostName:" << localHostName;

	//**********获取本机所有IPv4地址
	ui.textEditNetInfoArea->append("**********Local IPv4 Address:");
	hostInfo = QHostInfo::fromName(localHostName);
	foreach(QHostAddress address, hostInfo.addresses())
	{
		if (address.protocol() == QAbstractSocket::IPv4Protocol)
		{
			ui.textEditNetInfoArea->append(address.toString());

		}
	}
	//**********获取本机所有IPv6地址
	ui.textEditNetInfoArea->append("**********Local IPv6 Address:");
	hostInfo = QHostInfo::fromName(localHostName);
	foreach(QHostAddress address, hostInfo.addresses())
	{
		if (address.protocol() == QAbstractSocket::IPv6Protocol)
		{
			ui.textEditNetInfoArea->append(address.toString());

		}
	}
	//**********获取网络接口IP地址
	ui.textEditNetInfoArea->append("**********NetworkInterface IP Address:");
	foreach (QHostAddress address, QNetworkInterface::allAddresses())
	{
		ui.textEditNetInfoArea->append(address.toString());
	}
	//**********获取网络接口MAC地址
	ui.textEditNetInfoArea->append("**********NetworkInterface MAC:");
	foreach(QNetworkInterface networkInterface, QNetworkInterface::allInterfaces())
	{
		ui.textEditNetInfoArea->append(networkInterface.hardwareAddress());
	}
	//**********如果查看某个网络接口的IP地址怎么办？


}