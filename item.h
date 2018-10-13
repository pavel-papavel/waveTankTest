#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QColor>

class Item : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(qreal xPosition READ xPosition WRITE setXPosition NOTIFY xPositionChanged)
    Q_PROPERTY(qreal yPosition READ yPosition WRITE setYPosition NOTIFY yPositionChanged)
public:
    explicit Item(QObject *parent = nullptr);

    QString name() const;
    QColor color() const;

    qreal xPosition() const;
    void setXPosition(const qreal &x);

    qreal yPosition() const;
    void setYPosition(const qreal &y);

signals:
    void nameChanged(QString);
    void colorChanged(QColor);
    void xPositionChanged(qreal);
    void yPositionChanged(qreal);

public slots:
    void setName(const QString &name);
    void setColor(const QColor &color);

private:
    QString m_name;
    QColor m_color;
    qreal m_xPosition;
    qreal m_yPosition;
};

#endif // ITEM_H
