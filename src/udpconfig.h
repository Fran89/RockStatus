#ifndef UDPCONFIG_H
#define UDPCONFIG_H

#include <QDialog>
#include <QVariant>
#include <QHostAddress>
#include <QFileDialog>


namespace Ui {
class UdpConfig;
}

class UdpConfig : public QDialog
{
    Q_OBJECT

public:
    explicit UdpConfig(QWidget *parent = 0);
    ~UdpConfig();
    struct udpconfig {
        QVariant MyIPAddress;
        QVariant Port;
        QVariant LogFolder;
    };
    QFileDialog *myFolder;
    udpconfig config;

private:
    Ui::UdpConfig *ui;
    void accept();
};

#endif // UDPCONFIG_H
