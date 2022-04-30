//
// Created by Dan Schindler on 29/04/2022.
//

#include "DisjointSet.h"


DisjointSet::DisjointSet(int numOfElements){//TODO make changes after vector change!
    this->TreeForest = new UfElement[numOfElements];
    for(int i = 0; i < numOfElements; i++){
        TreeForest[i].setParent(-1);
        TreeForest[i].setSize(0);
    }
}

void DisjointSet::MakeSet(int v) {
    TreeForest[v].setParent(v);
    TreeForest[v].setSize(1);
}

void DisjointSet::Union(int RepV,int RepU){
    int RepBiggerInSize,RepSmallerInSize;
    if(TreeForest[RepV].getSize() > TreeForest[RepU].getSize()){
        RepBiggerInSize = RepV;
        RepSmallerInSize = RepU;
    }
    else{
        RepBiggerInSize = RepU;
        RepSmallerInSize = RepV;
    }
    TreeForest[RepSmallerInSize].setParent(RepBiggerInSize);
    TreeForest[RepBiggerInSize].setSize(TreeForest[RepBiggerInSize].getSize() + TreeForest[RepSmallerInSize].getSize());
}

int DisjointSet::Find(int v) {
    if(TreeForest[v].getParent() == v){
        return v;
    }
    else{
        return(TreeForest[v].getParent() == Find(TreeForest[v].getParent()));
    }
}

