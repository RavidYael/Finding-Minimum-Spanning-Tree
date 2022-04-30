//
// Created by Dan Schindler on 30/04/2022.
//

#include "Pair.h"

int Pair::getKey() const {
    return Key;
}

int Pair::getIndexInHeapArr() const {
    return indexInHeapArr;
}

void Pair::setKey(int key) {
    Key = key;
}

void Pair::setIndexInHeapArr(int indexInHeapArr) {
    Pair::indexInHeapArr = indexInHeapArr;
}

int Pair::getPriority() const {
    return Priority;
}

void Pair::setPriority(int priority) {
    Priority = priority;
}
