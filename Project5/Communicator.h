#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Communicator{
private:
    ifstream inputFile;

public:
    //Ctor
    Communicator(const string fileName);
    //Dtor
    virtual ~Communicator();
    //GETTERS

    const vector<int> &getEdgesData() const;

    vector<int> ReadGraphDetailsFromFile();

};

