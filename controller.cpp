#include "controller.h"
#include <QFile>
#include <QDomDocument>
#include <QDebug>
#include <QDomElement>

Controller::Controller(QObject *parent) : QObject(parent)
{
    QFile xml("example.xml");

    if (xml.open(QIODevice::ReadOnly))
    {
        QDomDocument dom;
        QString msgErr;
        int errLine;
        int errCol;

        if (!dom.setContent(&xml, &msgErr, &errLine, &errCol))
        {
            qDebug() << __FILE__ << " line: " << __LINE__;
            qDebug() << "Msg: " << msgErr << " Line: " << errLine << " Col: " << errCol;
            xml.close();
            return;
        }
        xml.close();

        QDomElement root = dom.documentElement();

    }
}

