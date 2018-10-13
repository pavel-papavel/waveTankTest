#ifndef MODEL_H
#define MODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include "item.h"

class Model : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);
    enum Role {
        NAME = Qt::UserRole+1,
        COLOR,
        XPosition,
        YPosition
    };

signals:

public slots:

private:
    QList<Item*> m_list;

    // QAbstractItemModel interface
public:
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QHash<int, QByteArray> roleNames() const;

    void insertItem(Item *item);
    Item *at(int index);
};

#endif // MODEL_H
