//
// Created by Dan Schindler on 30/04/2022.
//

#ifndef FINDING_MINIMUM_SPANNING_TREE_MINHEAP_H
#define FINDING_MINIMUM_SPANNING_TREE_MINHEAP_H
#include "Pair.h"
#include "iostream"
#include "vector"

using namespace std;

class MinHeap {
private:
    Pair* data;
    int maxSize;
    int heapSize;
    bool isAllocated;
    int* vertexIndexesInHeap;

public:

    MinHeap(int Max);
    ~MinHeap();
    void BuildHeap(vector<Vertex> graphVertexes);
    void ConvertVertexesIntoPair(vector<Vertex> graphVertexes);
    static int Parent(int index);
    static int Left(int index);
    static int Right(int index);
    void BuildMinHeap();//TODO implement this method
    bool isEmpty();//TODO implement this method
    void DecreaseKet(int index,int newKey);//TODO impel this method maybe its the same as deleteItem method that already implemented.
    Pair deleteMin();
    void fixMinHeap(int index);
    void insert(Pair& Item);
    void filterUpward(int index);//fixHeap as learned in class
    void filterDownward(int index);//TODO make sure this fix upward working properly
   //void resetSize() { heapSize = 0; }
    Pair Min();
};


#endif //FINDING_MINIMUM_SPANNING_TREE_MINHEAP_H
