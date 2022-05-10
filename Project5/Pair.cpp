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
    this->Key = vertex.getVertexNumber();
    this->Priority = vertex.getMinWeightOfEdgeConnect();
}

