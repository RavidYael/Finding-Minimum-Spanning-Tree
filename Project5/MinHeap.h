//
// Created by Dan Schindler on 30/04/2022.
//

#ifndef FINDING_MINIMUM_SPANNING_TREE_MINHEAP_H
#define FINDING_MINIMUM_SPANNING_TREE_MINHEAP_H
#include "Pair.h"
#include "iostream"
using namespace std;

class MinHeap {
private:
    Pair* data;
    int maxSize;
    int heapSize;
    bool isAllocated;

public:

    MinHeap(int Max);
    ~MinHeap();
    static int Parent(int index);
    static int Left(int index);
    static int Right(int index);
    void BuildMinHeap();//TODO implement this method
    bool isEmpty();//TODO implement this method
    void DecreaseKet(int index,int newKey);//TODO impel this method maybe its the same as deleteItem method that already implemented.
    Pair deleteMin();
    void fixMinHeap(int index);
    void insert(Pair& Item);
    void filterUpward(int index);//fixheap as learned in class
    void filterDownward(int index);//fixheap upward
    void deleteItem(int index, bool isInMinHeap);//delete item from heap by his index in the array
   //void resetSize() { heapSize = 0; }
    Pair Min();
};


#endif //FINDING_MINIMUM_SPANNING_TREE_MINHEAP_H
