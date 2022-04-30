//
// Created by Dan Schindler on 29/04/2022.
//

#ifndef FINDING_MINIMUM_SPANNING_TREE_DISJOINTSET_H
#define FINDING_MINIMUM_SPANNING_TREE_DISJOINTSET_H
#include <iostream>
#include "UfElement.h"

using namespace std;

class DisjointSet {
private:
   UfElement* TreeForest;

public:
    DisjointSet(int numOfElements);

    virtual ~DisjointSet();

    void MakeSet(int v);
    void Union(int v,int u);
    int Find(int v);

};


#endif //FINDING_MINIMUM_SPANNING_TREE_DISJOINTSET_H
//