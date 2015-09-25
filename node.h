#ifndef NODE_H
#define NODE_H

#include <QDomNode>
#include <QMap>
#include <QList>

class Node
{
public:
    Node(QString nodeName, QString nodeValue, QMap<QString,QString> attributes,
            Node *parent, Node *previousSibling);
    void setNextSibling(Node *n);
    void setChildNode(Node *n);

protected:
private:
    QString                         nodeName_;
    QString                         nodeValue_;
    QMap<QString, QString> attributes_;
    Node                            *parent_;
    Node                            *previousSibling_;
    Node                            *nextSibling_;
    QList<Node*>               childNodes_;
};

#endif // NODE_H
