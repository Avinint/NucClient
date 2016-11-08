#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) :
    QObject(parent)
{
}

void SocketTest::Connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("bogotobogo.com", 2000);

    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected!";

        // send
        socket->write("hello server\r\n\r\n\r\n\r\n");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "Reading: " << socket->bytesAvailable();

        qDebug() << socket->readAll();

        socket->close();
    }
    else
    {
        qDebug() << "Not connected!";
    }

    // sent

    // got

    // closed
}

QString allIpAddresses()
{
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    for(int i=0; i<interfaces.count(); i++)
    {
    QList<QNetworkAddressEntry> entries = interfaces.at(i).addressEntries();
    for(int j=0; j<entries.count(); j++)
    {
    if(entries.at(j).ip().protocol() == QAbstractSocket::IPv4Protocol)
    {
    qDebug() << entries.at(j).ip().toString();
    qDebug() << entries.at(j).netmask().toString();
    }
    }
    }
}
