//
// Created by Dan Schindler on 11/05/2022.
//

#include "VertexInAdjacentList.h"

const Vertex &VertexInAdjacentList::getVertex() const {
    return vertex;
}

int VertexInAdjacentList::getWeight() const {
    return Weight;
}


VertexInAdjacentList::~VertexInAdjacentList() {
    //TODO not sure if i need to delete memory allocation of vertex here i think graph will do it.
}

VertexInAdjacentList::VertexInAdjacentList(Vertex &vertex, int weight) : vertex(vertex), Weight(weight) {}
