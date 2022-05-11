//
// Created by Dan Schindler on 30/04/2022.
//

#ifndef FINDING_MINIMUM_SPANNING_TREE_PAIR_H
#define FINDING_MINIMUM_SPANNING_TREE_PAIR_H


class Pair {
private:
    int Key;//Name of vertex
    int Priority;//Lightest Connective Edge from this vertex into the minimal Spanning tree
    //int indexInHeapArr;TODO not sure if needed
public:
    Pair();
    ~Pair() = default;
    //Getters
    int getKey() const;
    int getPriority() const;
    int getIndexInHeapArr() const;

    //Setters
    void initializePairFromVertex(int i_VertexName, int i_MinWeightOfConnectingEdge);

    void setPriority(int priority);

};


#endif //FINDING_MINIMUM_SPANNING_TREE_PAIR_H
