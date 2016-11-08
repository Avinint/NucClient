#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include <QtNetwork>
#include <QList>
#include <QString>

class SocketTest: QObject
{
    Q_OBJECT

    void Connect();
    QList<QNetworkAddressEntry> allIpAddresses();
    SocketTest(QObject *parent);

    QTcpSocket *socket;
};



#endif // SOCKETTEST_H
