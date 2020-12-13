#ifndef EDGE_H
#define EDGE_H
#include "node.h"

class Edge
{
public:
    Edge(Node *destination, int length); // todo
    Node *getDestination();              // todo
    int getLength() const;

private:
    int length;
    Node *destination;
};

#endif