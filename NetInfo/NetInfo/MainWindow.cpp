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

	//**********��ȡ�����û���
	ui.textEditNetInfoArea->append("**********Local User Name:");
	QString name = qgetenv("USERNAME");
	ui.textEditNetInfoArea->append(name);

	//**********��ȡ������������Ҳ����ͨ��������������IP��ַ������ͨ��IP��ַ�����������������
	ui.textEditNetInfoArea->append("**********Local Host Name:");
	QString localHostName = QHostInfo::localHostName();
	ui.textEditNetInfoArea->append(localHostName);
	//qDebug() << "LocalHostName:" << localHostName;

	//**********��ȡ��������IPv4��ַ
	ui.textEditNetInfoArea->append("**********Local IPv4 Address:");
	hostInfo = QHostInfo::fromName(localHostName);
	foreach(QHostAddress address, hostInfo.addresses())
	{
		if (address.protocol() == QAbstractSocket::IPv4Protocol)
		{
			ui.textEditNetInfoArea->append(address.toString());

		}
	}
	//**********��ȡ��������IPv6��ַ
	ui.textEditNetInfoArea->append("**********Local IPv6 Address:");
	hostInfo = QHostInfo::fromName(localHostName);
	foreach(QHostAddress address, hostInfo.addresses())
	{
		if (address.protocol() == QAbstractSocket::IPv6Protocol)
		{
			ui.textEditNetInfoArea->append(address.toString());

		}
	}
	//**********��ȡ����ӿ�IP��ַ
	ui.textEditNetInfoArea->append("**********NetworkInterface IP Address:");
	foreach (QHostAddress address, QNetworkInterface::allAddresses())
	{
		ui.textEditNetInfoArea->append(address.toString());
	}
	//**********��ȡ����ӿ�MAC��ַ
	ui.textEditNetInfoArea->append("**********NetworkInterface MAC:");
	foreach(QNetworkInterface networkInterface, QNetworkInterface::allInterfaces())
	{
		ui.textEditNetInfoArea->append(networkInterface.hardwareAddress());
	}
	//**********����鿴ĳ������ӿڵ�IP��ַ��ô�죿


}