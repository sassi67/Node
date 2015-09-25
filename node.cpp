#include "node.h"

/**
 * @brief Constructor
 * @param nodeName
 * @param nodeValue
 * @param attributes
 * @param parent
 * @param previousSibling
 */
Node::Node(QString nodeName, QString nodeValue, QMap<QString,QString> attributes,
                    Node *parent, Node *previousSibling):
    nodeName_(nodeName),
    nodeValue_(nodeValue),
    attributes_(attributes),
    parent_(parent),
    previousSibling_(previousSibling)
{

}

