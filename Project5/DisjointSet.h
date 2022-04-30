//
// Created by Dan Schindler on 29/04/2022.
//

#ifndef FINDING_MINIMUM_SPANNING_TREE_DISJOINTSET_H
#define FINDING_MINIMUM_SPANNING_TREE_DISJOINTSET_H
#include <iostream>
#include "UfElement.h"
#include <vector>
using namespace std;

class DisjointSet {
private:
   vector<UfElement> TreeForest;

public:
    DisjointSet(int numOfElements);
    virtual ~DisjointSet() = default;

    void MakeSet(int v);
    void UnionBySize(int v, int u);
    int Find(int v);

};


#endif //FINDING_MINIMUM_SPANNING_TREE_DISJOINTSET_H
//