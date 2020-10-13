#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QDebug>

class MyClass : public QObject
{
    Q_OBJECT
public:
    MyClass(QObject *QMLObject) : viewer(QMLObject) {}

signals:

public slots:
    void buttonClicked();
protected:
    QObject *viewer;
};

#endif // MYCLASS_H
