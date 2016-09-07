#ifndef ROCKSTATUS_H
#define ROCKSTATUS_H

#include <QMainWindow>
#include <QHostAddress>
#include <QLabel>
#include "udpconfig.h"
#include "udpclient.h"
#include "stninfo.h"
#include "metadatatable.h"

namespace Ui {
class RockStatus;
}

class RockStatus : public QMainWindow
{
    Q_OBJECT

public:
    explicit RockStatus(QWidget *parent = 0);
    ~RockStatus();

public slots:
    void appendToDebugBrowser(const QString);

private slots:
    void on_actionConnection_triggered();
    void sockConfig();
    void setStatus(QString mstatus);
    void nothing();
    void onDisconnect();
    void DebugToggle();

signals:
    void sendDebug(bool);

private:
    Ui::RockStatus *ui;
    UdpConfig     *myConfig;
    UdpClient     *myClient;
    StnInfo       *myInfo;
    MetadataTable *myTable;
    QLabel        *status;

    bool configured;
    bool connected;
    bool debug;
};

#endif // ROCKSTATUS_H
