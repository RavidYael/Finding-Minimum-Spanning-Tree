//
// Created by Dan Schindler on 30/04/2022.
//

#ifndef FINDING_MINIMUM_SPANNING_TREE_MINHEAP_H
#define FINDING_MINIMUM_SPANNING_TREE_MINHEAP_H
#include <iostream>
#include "vector"
#include "Pair.h"
#include "Vertex.h"

using namespace std;

class MinHeap {
private:
    vector<Pair> data;
    int maxSize;
    int heapSize;
    bool isAllocated;
    int* vertexIndexesInHeap;

public:

    MinHeap(int Max);
    ~MinHeap();
    void BuildHeap(vector<Vertex> graphVertexes);
    void ConvertVertexesIntoPairAndBuildHeapArr(vector<Vertex> graphVertexes);
    static int Parent(int index);
    static int Left(int index);
    static int Right(int index);
    void BuildMinHeap();
    bool IsEmpty();
    void DecreaseKey(int index,int newKey);//TODO impel this method maybe its the same as deleteItem method that already implemented.
    Pair DeleteMin();
    void fixMinHeap(int index);
    void Insert(Pair& Item);
    void FilterUpward(int index);//fixHeap as learned in class
    void FilterDownward(int index);//TODO make sure this fix upward working properly
   //void resetSize() { heapSize = 0; }
    Pair Min();
};


#endif //FINDING_MINIMUM_SPANNING_TREE_MINHEAP_H
