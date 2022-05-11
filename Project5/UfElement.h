//
// Created by Dan Schindler on 30/04/2022.
//
#pragma once
#ifndef FINDING_MINIMUM_SPANNING_TREE_UFELEMENT_H
#define FINDING_MINIMUM_SPANNING_TREE_UFELEMENT_H


class UfElement {
private:
    int parent;
    int size;
public:

    int getParent() const;

    int getSize() const;

    void setParent(int parent);

    void setSize(int size);
};


#endif //FINDING_MINIMUM_SPANNING_TREE_UFELEMENT_H
