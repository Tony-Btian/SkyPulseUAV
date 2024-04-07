#ifndef FLIGTHCONTROL_H
#define FLIGTHCONTROL_H

#include <QObject>

class FligthControl : public QObject
{
    Q_OBJECT
public:
    explicit FligthControl(QObject *parent = nullptr);

signals:

};

#endif // FLIGTHCONTROL_H
