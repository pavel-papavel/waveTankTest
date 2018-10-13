#include "item.h"

Item::Item(QObject *parent) : QObject(parent)
{

}

QString Item::name() const
{
    return m_name;
}

void Item::setName(const QString &name)
{
    m_name = name;
    emit nameChanged(m_name);
}

QColor Item::color() const
{
    return m_color;
}

void Item::setColor(const QColor &color)
{
    m_color = color;
    emit colorChanged(m_color);
}

qreal Item::yPosition() const
{
    return m_yPosition;
}

void Item::setYPosition(const qreal &y)
{
    m_yPosition = y;
}

qreal Item::xPosition() const
{
    return m_xPosition;
}

void Item::setXPosition(const qreal &x)
{
    m_xPosition = x;
}
