#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <QObject>

class Observable : public QObject
{
    Q_OBJECT

public:
    explicit Observable(QObject *parent = nullptr);

signals:
    void notifyObservers(const QString &message);

};

#endif // OBSERVABLE_H
