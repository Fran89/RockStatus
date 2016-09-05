#ifndef ROCKSTATUS_H
#define ROCKSTATUS_H

#include <QMainWindow>

namespace Ui {
class RockStatus;
}

class RockStatus : public QMainWindow
{
    Q_OBJECT

public:
    explicit RockStatus(QWidget *parent = 0);
    ~RockStatus();

private:
    Ui::RockStatus *ui;
};

#endif // ROCKSTATUS_H
