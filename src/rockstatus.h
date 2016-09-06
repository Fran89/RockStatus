#ifndef ROCKSTATUS_H
#define ROCKSTATUS_H

#include <QMainWindow>
#include <QHostAddress>
#include <QLabel>
#include <udpconfig.h>
#include <udpclient.h>

namespace Ui {
class RockStatus;
}

class RockStatus : public QMainWindow
{
    Q_OBJECT

public:
    explicit RockStatus(QWidget *parent = 0);
    ~RockStatus();

private slots:
    void on_actionConnection_triggered();
    void sockConfig();
    void setStatus(QString mstatus);

private:
    Ui::RockStatus *ui;
    UdpConfig *myConfig;
    UdpClient *myClient;
    QLabel *status;

    bool configured;
    bool connected;
};

#endif // ROCKSTATUS_H
