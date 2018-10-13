#include "core.h"

Core::Core(QObject *parent) : QObject(parent)
{
    m_model = new Model(this);
    Item *item = new Item(this);
    item->setColor(QColor(255, 255, 0));
    item->setXPosition(0);
    item->setYPosition(20);
    m_model->insertItem(item);
    item = new Item(this);
    item->setColor(QColor(0, 0, 255));
    item->setXPosition(250);
    item->setYPosition(70);
    m_model->insertItem(item);
    item = new Item(this);
    item->setColor(QColor(0, 255, 255));
    item->setXPosition(350);
    item->setYPosition(10);
    m_model->insertItem(item);
    item = new Item(this);
    item->setColor(QColor(255, 0, 255));
    item->setXPosition(400);
    item->setYPosition(50);
    m_model->insertItem(item);
    for(int i = 0; i < m_model->rowCount(QModelIndex()); i++)
    {
        listXposition.append(m_model->at(i)->xPosition());
        listYposition.append(m_model->at(i)->yPosition());
    }
}

QList<qreal> Core::getListXposition()
{
    return listXposition;
}

QList<qreal> Core::getListYposition()
{
    return listYposition;
}

int Core::countListXposition()
{
    return listXposition.count();
}

int Core::countListYposition()
{
    return listYposition.count();
}

void Core::updateList()
{
    for(int i = 0; i < m_model->rowCount(QModelIndex()); i++)
    {
        listXposition.append(m_model->at(i)->xPosition());
        listYposition.append(m_model->at(i)->yPosition());
    }
}
