//
// Created by Dan Schindler on 10/05/2022.
//
#pragma once

#ifndef FINDING_MINIMUM_SPANNING_TREE_LOGIC_H
#define FINDING_MINIMUM_SPANNING_TREE_LOGIC_H

#include <iostream>
#include "AlgoRunner.h"

using namespace std;

static class Logic {
private:
    WeightedGraph m_undirectedWeightedGraph;
    AlgoRunner m_algoRunner;

public:
    void buildGraphFromEdgeDataArray(vector<int> edgeData);
    void runAlgoRunner();
};


#endif //FINDING_MINIMUM_SPANNING_TREE_LOGIC_H
