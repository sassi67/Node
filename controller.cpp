#include "controller.h"
#include <QFile>
#include <QDomDocument>
#include <QDebug>
#include <QDomElement>
#include <QDomNamedNodeMap>
#include <QMap>
#include <QDomNode>
#include <QDomAttr>

#include "node.h"

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

        QString rootName = root.nodeName();
        QString rootValue = "";
        QMap<QString, QString> attributesMap;

        if (root.hasAttributes())
        {
            QDomNamedNodeMap attributes = root.attributes();

            if (!attributes.isEmpty())
            {
//                qDebug() << attributes.length();
                for (int i = 0; i < attributes.length(); ++i)
                {
                    QDomAttr attr = attributes.item(i).toAttr();

                    QString attrKey = attr.name();
                    QString attrVal = attr.value();
                    attributesMap.insert(attrKey, attrVal);
                }
            }
        }
    }
}

