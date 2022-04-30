//
// Created by Dan Schindler on 30/04/2022.
//

#ifndef FINDING_MINIMUM_SPANNING_TREE_PAIR_H
#define FINDING_MINIMUM_SPANNING_TREE_PAIR_H


class Pair {
private:
    int Key;//Name of vertex
    int Priority;//Lightest Connective Edge from this vertex into the minimal Spanning tree
    int indexInHeapArr;
public:
    Pair() = default;
    ~Pair() = default;
    //Getters
    int getKey() const;
    int getPriority() const;
    int getIndexInHeapArr() const;

    //Setters
    void setKey(int key);
    void setPriority(int priority);
    void setIndexInHeapArr(int indexInHeapArr);

};


#endif //FINDING_MINIMUM_SPANNING_TREE_PAIR_H
