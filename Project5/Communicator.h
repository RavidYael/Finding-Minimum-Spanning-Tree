#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Communicator{
private:
    ifstream inputFile;
    int numOfVertex = 0;
    int numOfEdges = 0;
    vector<int> edgesData; //each 3 cell contain data on 1 edge vertex -> vertex and 3rd cell is the edge weight. last two cells represent the edge user want to delete after 2 algos (vertex -> vertex)
public:
    //Ctor
    Communicator(const string fileName);
    //Dtor
    virtual ~Communicator();
    //GETTERS
    int getNumOfVertex() const;
    int getNumOfEdges() const;
    const vector<int> &getEdgesData() const;

    void ReadGraphDetailsFromFile();

};

