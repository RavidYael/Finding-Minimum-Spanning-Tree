//
// Created by Dan Schindler on 30/04/2022.
//

#include "MinHeap.h"

MinHeap::MinHeap(int Max) {
    data = new Pair*[Max];
    maxSize = Max;
    heapSize = 0;
    isAllocated = true;
}

MinHeap::~MinHeap() {
    if (isAllocated){
        delete[] data;
        data = nullptr;
        isAllocated = false;
        heapSize = 0;
    }
}

int MinHeap::Parent(int index) {
    return (index - 1) / 2;
}

int MinHeap::Left(int index) {
    return (2 * index + 1);
}

int MinHeap::Right(int index) {
    return (2 * index + 2);
}

void MinHeap::deleteItem(int index,bool isInMinHeap) {
    data[index] = data[heapSize - 1];
    heapSize--;
    if (isInMinHeap) {
        data[index]->setIndinMinHeap(index);
    }
    else {
        data[index]->setIndinMaxHeap(index);
    }
}

Pair* MinHeap::Min()
{
    return  data[0];
}

void MinHeap::fixMinHeap(int index) {
    if ( ( index > 0 ) && ( data[index]->getPriority() < data[Parent(index)] -> getPriority())) {//check if smaller than parent

        filterUpward(index);
    }
    else{
        filterDownward(index);
    }

}

void MinHeap::filterDownward(int index){//fixheap as learned in class
    int Max;
    int left = Left(index);
    int right = Right(index);

    if ((left < heapSize) && (data[left]->getPriority() > data[index]->getPriority())){
        Max = left;
    }
    else
        Max = index;
    if ((right < heapSize) && (data[right]->getPriority() > data[Max]->getPriority())) {
        Max = right;
    }
    if (Max != index) {
        data[index]->setIndinMinHeap(Max);
        data[Max]->setIndinMinHeap(index);

        swap(data[index], data[Max]);
        filterDownward(Max);
    }
}

void MinHeap::filterUpward(int index) {//TODO check if working properly

    if (index <= 0 || data[Parent(index)]->getPriority() < data[index]->getPriority())//if parent smaller then me return from recursion
        return;

    data[index]->setIndinMinHeap(Parent(index));
    data[Parent(index)]->setIndinMinHeap(index);

    swap(data[Parent(index)], data[index]);//else swap
    filterUpward(Parent(index));//recursive call
}

Pair* MinHeap::deleteMin() {
    Pair* min = data[0];
    heapSize--;
    data[0] = data[heapSize];
    data[0]->setIndinMinHeap(0);
    fixMinHeap(0);
    return min;
}

void MinHeap::insert(Pair* Item){
    int curSize = heapSize;
    heapSize++;

    while ((curSize > 0) && (data[Parent(curSize)]->getPriority() > Item->getPriority())) {
        int papaInd = Parent(curSize);
        data[curSize] = data[papaInd];
        data[curSize]->setIndinMinHeap(curSize);
        curSize = papaInd;
    }
    data[curSize] = Item;
    Item->setIndinMinHeap(curSize);
}