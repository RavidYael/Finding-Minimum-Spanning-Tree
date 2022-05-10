//
// Created by Dan Schindler on 30/04/2022.
//

#include "UfElement.h"

void UfElement::setParent(int parent) {
    this->parent= parent;
}

void UfElement::setSize(int size) {
    this->size = size;
}

int UfElement::getParent() const {
    return parent;
}

int UfElement::getSize() const {
    return size;
}
