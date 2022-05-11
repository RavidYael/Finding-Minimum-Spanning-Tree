#pragma once
using namespace std;
#include <vector>
#include <iostream>
#include "WeightedGraph.h"
#include "DisjointSet.h"
#include "MinHeap.h"


class AlgoRunner
{
private:
	static int partition(vector<Edge>& i_EdgeArray, int i_LeftIndex, int i_RightIndex);
	static vector<Edge> spaningTreeByEdges(WeightedGraph& i_Graph);

public:
	static vector<Edge> Kruskal(WeightedGraph& i_Graph);
	static  vector<Edge> Prim(WeightedGraph& i_Graph);
	static void QuickSort(vector<Edge>& i_EdgeArray, int i_LeftIndex, int i_RightIndex);
	static bool IsConnectedCompont(WeightedGraph i_Graph);
	static void DFS(WeightedGraph i_TheGraph, vector<bool> i_VisitedVertexes);
	static void DFSUtil(WeightedGraph i_TheGraph, Vertex i_CurrentVertex, vector<bool> i_VisitedVertexes);
	static bool IsAllVertexesVisitedDuringDFS(vector<bool> i_VisitedVertexes);
};

