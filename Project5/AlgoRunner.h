#pragma once
#include "Edge.h"
using namespace std;
#include <vector>
#include "WeightedGraph.h"
#include "DisjointSet.h"
#include "MinHeap.h"
#include <iostream>
#include "WeightedGraph.h"


class AlgoRunner
{
private:
	static int partition(vector<Edge>& i_EdgeArray, int i_LeftIndex, int i_RightIndex);
	static vector<Edge> spaningTreeByEdges(WeightedGraph& i_Graph);

public:
	static vector<Edge> Kruskal(WeightedGraph& i_Graph);
	static  vector<Edge> Prim(WeightedGraph& i_Graph);
	static void QuickSort(vector<Edge>& i_EdgeArray, int i_LeftIndex, int i_RightIndex);
	

};

