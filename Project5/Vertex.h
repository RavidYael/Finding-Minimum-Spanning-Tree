#pragma once

#include "vector"
#include "Pair.h"
#include "Edge.h"

using namespace std;


class Vertex
{
private:
	int m_VertexNumber;

	vector<Vertex> m_AdjacentInGraph;
	vector<Pair> m_AdjacentAndConnectingEdgeInGraph;
	vector<Edge> m_AllOutEdges;
	Vertex* m_AdjacentInSpanningTree; 
	Edge m_EdgeConnectInSpanningTree;
	int m_MinWeightOfEdgeConnect = INT32_MAX;
	bool m_InTree = false;

public:
	void SetInTree() { m_InTree = true; }
	vector<Edge> GetAllOutEdges() { return m_AllOutEdges; }
	bool NotInTree() { return m_InTree == false; }
	int GetMinWeightOfEdgeConnect() { return m_MinWeightOfEdgeConnect; }
	void SetMinWeightOfEdgeConnect(int i_NewMinWeight) { m_MinWeightOfEdgeConnect = i_NewMinWeight; }
	void SetAdjacentInSpanningTree(Vertex i_AdjacentInGraph, Edge i_EdgeBetweenAdjacents) { m_AdjacentInSpanningTree = &i_AdjacentInGraph;
																							  m_EdgeConnectInSpanningTree = i_EdgeBetweenAdjacents;}
	Edge GetEdgeConnctInSpanningTree() { return m_EdgeConnectInSpanningTree; }
	int GetName() { return m_VertexNumber; }
	void SetName(int i_Name) { m_VertexNumber = i_Name; }
	void operator=(const Vertex& i_ToAssign) {
		m_AdjacentInGraph = i_ToAssign.m_AdjacentInGraph;
		m_AdjacentAndConnectingEdgeInGraph = i_ToAssign.m_AdjacentAndConnectingEdgeInGraph;
		m_AllOutEdges = i_ToAssign.m_AllOutEdges;
		m_AdjacentInSpanningTree = i_ToAssign.m_AdjacentInSpanningTree;
		m_EdgeConnectInSpanningTree = i_ToAssign.m_EdgeConnectInSpanningTree;
	}
};

