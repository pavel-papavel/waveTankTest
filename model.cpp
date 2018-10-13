#include "model.h"

Model::Model(QObject *parent) : QAbstractListModel(parent)
{

}

QModelIndex Model::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    return QModelIndex();
}

int Model::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_list.count();
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if(index.row() > m_list.count() || index.row() < 0)
        return QVariant();
    switch (role) {
        case NAME:
            return m_list.at(index.row())->name();
            break;
        case COLOR:
            return QVariant::fromValue(m_list.at(index.row())->color());
            break;
        case XPosition:
            return QVariant::fromValue(m_list.at(index.row())->xPosition());
            break;
        case YPosition:
            return QVariant::fromValue(m_list.at(index.row())->yPosition());
            break;
        default:
            return QVariant();
    }
    return QVariant();
}

bool Model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.row() > m_list.count() || index.row() < 0)
        return false;
    switch (role) {
        case NAME:
            m_list[index.row()]->setName(value.toString());
            break;
        case COLOR:
            m_list[index.row()]->setColor(value.value<QColor>());
            break;
        case XPosition:
            m_list[index.row()]->setXPosition(value.toReal());
            break;
        case YPosition:
            m_list[index.row()]->setYPosition(value.toReal());
            break;
        default:
            return false;
    }
    return true;
}

QHash<int, QByteArray> Model::roleNames() const
{
    QHash<int, QByteArray> role = QAbstractItemModel::roleNames();
    role.insert(NAME, "modelName");
    role.insert(COLOR, "modelColor");
    role.insert(XPosition, "modelX");
    role.insert(YPosition, "modelY");
    return role;
}

void Model::insertItem(Item *item)
{
    beginInsertRows(QModelIndex(), rowCount(QModelIndex()), rowCount(QModelIndex()));
    m_list.append(item);
    endInsertRows();
}

Item *Model::at(int index)
{
    return m_list[index];
}
