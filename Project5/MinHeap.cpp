//
// Created by Dan Schindler on 30/04/2022.
//

#include "MinHeap.h"

MinHeap::MinHeap(int Max) {
    data.reserve(Max);
    vertexIndexesInHeap = new int[Max];
    maxSize = Max;
    heapSize = 0;
    isAllocated = true;
}

MinHeap::~MinHeap() {//TODO make sure allocated memory get deleted;
    if (isAllocated){
        delete[] vertexIndexesInHeap;
        isAllocated = false;
        heapSize = 0;
    }
}

void MinHeap::BuildHeap(vector<Vertex> graphVertexes) {
    ConvertVertexesIntoPairAndBuildHeapArr(graphVertexes);
    heapSize = maxSize = graphVertexes.size();
    int i = heapSize;
    for(i = heapSize / 2; i >= 0; i--){
        fixMinHeap(i);
    }
}

void MinHeap::ConvertVertexesIntoPairAndBuildHeapArr(vector<Vertex> graphVertexes){
    int counter = 0;
    for(Vertex curVertex : graphVertexes){
        data[counter].initializePairFromVertex(curVertex.GetName(), curVertex.GetMinWeightOfEdgeConnect());
        vertexIndexesInHeap[curVertex.GetName()] = counter;//initialize vertex indexes in heap array
        counter++;
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

void MinHeap::DecreaseKey(int index,int newKey){//TODO check if this method working accordingly
    int indexInHeap = vertexIndexesInHeap[index];
    data[index].setPriority(newKey);
    fixMinHeap(index);
}

Pair MinHeap::Min(){
    return  data[0];
}

bool MinHeap::IsEmpty(){
    if(heapSize == 0){
        return true;
    }
    return false;
}

void MinHeap::fixMinHeap(int index) {
    if ( ( index > 0 ) && ( data[index].getPriority() < data[Parent(index)].getPriority())) {//check if smaller than parent
        FilterUpward(index);
    }
    else{
        FilterDownward(index);
    }
}

void MinHeap::FilterDownward(int index){//fixHeap as learned in class
    int Max;
    int left = Left(index);
    int right = Right(index);

    if ((left < heapSize) && (data[left].getPriority() > data[index].getPriority())){
        Max = left;
    }
    else
        Max = index;
    if ((right < heapSize) && (data[right].getPriority() > data[Max].getPriority())) {
        Max = right;
    }

    if (Max != index) {
       // data[index].setIndexInHeapArr(Max);
        vertexIndexesInHeap[index] = Max;
       // data[Max].setIndexInHeapArr(index);
       vertexIndexesInHeap[Max] = index;
        swap(data[index], data[Max]);
        FilterDownward(Max);
    }
}

void MinHeap::FilterUpward(int index) {//TODO check if working properly because i think that we got points deduct in the data structure projects on this method

    if (index <= 0 || data[Parent(index)].getPriority() < data[index].getPriority())//if parent smaller then me return from recursion
        return;

   // data[index].setIndexInHeapArr(Parent(index));
    vertexIndexesInHeap[index] = Parent(index);
    //data[Parent(index)].setIndexInHeapArr(index);
    vertexIndexesInHeap[Parent(index)] = index;

    swap(data[Parent(index)], data[index]);//else swap
    FilterUpward(Parent(index));//recursive call
}

Pair MinHeap::DeleteMin() {
    Pair min = data[0];
    heapSize--;
    data[0] = data[heapSize];
    vertexIndexesInHeap[0] = 0;
    fixMinHeap(0);
    return min;
}

/*void MinHeap::Insert(Pair& Item){
    int curSize = heapSize;
    heapSize++;

    while ((curSize > 0) && (data[Parent(curSize)].getPriority() > Item.getPriority())) {
        int papaInd = Parent(curSize);
        data[curSize] = data[papaInd];
        data[curSize].setIndexInHeapArr(curSize);
        curSize = papaInd;
    }
    data[curSize] = Item;
    Item.setIndexInHeapArr(curSize);
}*/