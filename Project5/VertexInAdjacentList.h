//
// Created by Dan Schindler on 11/05/2022.
//

#ifndef FINDING_MINIMUM_SPANNING_TREE_VERTEXINADJACENTLIST_H
#define FINDING_MINIMUM_SPANNING_TREE_VERTEXINADJACENTLIST_H
#include <iostream>
#include "Vertex.h"


class VertexInAdjacentList {
private:
    Vertex &vertex;
    int Weight;

public:
    //Ctor
    VertexInAdjacentList(Vertex &vertex, int weight);

    //Dtor
    virtual ~VertexInAdjacentList();

    const Vertex &getVertex() const;

    int getWeight() const;
};



#endif //FINDING_MINIMUM_SPANNING_TREE_VERTEXINADJACENTLIST_H
