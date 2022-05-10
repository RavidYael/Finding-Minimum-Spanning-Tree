//
// Created by Dan Schindler on 30/04/2022.
//

#include "Pair.h"

int Pair::getKey() const {
    return Key;
}

/*int Pair::getIndexInHeapArr() const {
    return indexInHeapArr;
}*///TODO check if needed if not can be deleted

void Pair::initializePairFromVertex(Vertex vertex){
    this->vertex = vertex;
    this->Key = vertex.getVertexNumber();
    this->Priority = vertex.getMinWeightOfEdgeConnect();
}

void Pair::setPriority(int priority) {
    Priority = priority;
    //TODO cant change lightest connective weight of vertex not sure if necessary so for now i will leave it that way (change just the pair priority)

}

Pair::Pair(){
    Key = 0;
    Priority = INT32_MAX;
    vertex = nullptr;
}

