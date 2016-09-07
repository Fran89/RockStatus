#ifndef METADATATABLE_H
#define METADATATABLE_H
#include <QString>
#include <QList>
#include <QVariant>
#include <QBrush>
#include <QDateTime>
#include <QAbstractTableModel>
#include "include/TableDef.h"
#include "stninfo.h"

// This class is meant to recieve information from the StationInfo and update the UI
class MetadataTable : public QAbstractTableModel
{
    Q_OBJECT
    
public:
    explicit MetadataTable(QObject *parent = 0);
    void setStationInfo(StnInfo* MyStations);

public slots:
    void addStaInformation();
    void updateMetadata();
    
private:
    StnInfo *StatInfo;
    QList<QString> StatName;
    bool stnSetup;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void updateColors();

signals:
    void debugMessage(QString);

};

#endif // METADATATABLE_H
