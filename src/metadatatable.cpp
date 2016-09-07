#include "metadatatable.h"

MetadataTable::MetadataTable(QObject *parent)
    : QAbstractTableModel(parent)
{
    stnSetup = false;
}

// The column count. Reimplemented Virtual (Req)
int MetadataTable::columnCount(const QModelIndex &parent = QModelIndex()) const
{
    Q_UNUSED(parent);
    return Ncol;
}

// The row count, Reimplemented Virtual (Req)
int MetadataTable::rowCount(const QModelIndex &parent = QModelIndex()) const
{
    Q_UNUSED(parent);
    return StatInfo->stations.size();
}

// The data value, Reimplemented Virtual (Req)
QVariant MetadataTable::data(const QModelIndex &index, int role) const
{
    // IF NOT VALID
    if(!index.isValid()){
        return QVariant();
    }
    else
    {
        Stn* currentSta;
        currentSta = StatInfo->stations.value(StatName.at(index.row()));

        // TEXT
        if(role == Qt::DisplayRole){

            switch(index.column()){
                case Tnet:
                    return currentSta->net;
                case Tsta:
                    return currentSta->stnname;
                case Tvol:
                    return currentSta->vvb;
                case Ttem:
                    return currentSta->deg;
                case Ttim:
                    return currentSta->latest.toString("yyyy/MM/dd HH:hh:ss");
                case Ttcq:
                    return currentSta->lcq;
                case Ttph:
                    return currentSta->lce;
                case Tdsk:
                    return currentSta->dsk;
                case Tcpu:
                    return currentSta->cpu;
                case Thum:
                    return currentSta->hum;
                default:
                    return QVariant();
            }
        }
    }
    return QVariant();
}

// The header data, Reimplemented Virtual
QVariant MetadataTable::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();
    if(orientation == Qt::Horizontal){
        switch (section){
        case Tnet:
            return tr("Network");
        case Tsta:
            return tr("Station");
        case Tvol:
            return tr("Voltage");
        case Ttem:
            return tr("Temperature");
        case Ttim:
            return tr("Time");
        case Ttcq:
            return tr("Time Quality");
        case Ttph:
            return tr("TXCO Drift");
        case Tdsk:
            return tr("Disk Usage (%)");
        case Tcpu:
            return tr("CPU Usage (%)");
        case Thum:
            return tr("Humidity");
        default:
            return QVariant();
        }
    }
    if(orientation == Qt::Vertical){
        return QString::number(section+1);
    }
    return QVariant();
}

// Setup The station info.
void MetadataTable::setStationInfo(StnInfo *MyStations)
{
    StatInfo = MyStations;
    stnSetup = true;
    emit debugMessage("Station Info setup correctly.");
}

// Add Station Information
void MetadataTable::addStaInformation()
{
    StatName.clear();
    StatName = StatInfo->stations.uniqueKeys();
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    endInsertRows();
}

// Update Station Data
void MetadataTable::updateMetadata()
{
    QVector<int> updRoles;
    updRoles.append(Qt::BackgroundRole);
    updRoles.append(Qt::DisplayRole);
    dataChanged(index(0,0),index(rowCount(),columnCount()),updRoles);
}
