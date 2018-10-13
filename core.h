#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <QList>
#include <QDebug>
#include <QAbstractItemModel>
#include "model.h"

class Core : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Model* model MEMBER m_model CONSTANT)
public:
    explicit Core(QObject *parent = nullptr);

signals:

public slots:
    QList<qreal> getListXposition();
    QList<qreal> getListYposition();
    int countListXposition();
    int countListYposition();
    void updateList();
private:
    Model *m_model;
    QList<qreal> listXposition;
    QList<qreal> listYposition;
};

#endif // CORE_H
