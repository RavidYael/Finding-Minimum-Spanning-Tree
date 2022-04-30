#pragma once

#include "Edge.h"
#include "vector"
using namespace std;
class Vertex
{
private:
    int m_VertexNumber;
	vector<Vertex> m_AdjacentInGraph;
	vector<Edge> m_AllOutEdges;
	Vertex m_AdjacentInSpanningTree = nullptr;
	Edge m_EdgeConnectInSpanningTree;
	int m_MinWeightOfEdgeConnect = INFINITY;//TODO change to int32_max
	bool m_InTree = false;

public:
	void SetInTree() { m_InTree = true; }
	vector<Edge> GetAllOutEdges() { return m_AllOutEdges; }
	inline bool NotInTree() { return m_InTree == false; }
	inline int getMinWeightOfEdgeConnect() { return m_MinWeightOfEdgeConnect; }
	inline void SetMinWeightOfEdgeConnect(int i_NewMinWeight) { m_MinWeightOfEdgeConnect = i_NewMinWeight; }
	inline void SetAdjacentInSpanningTree(Vertex& i_AdjacentInGraph) { m_AdjacentInSpanningTree = i_AdjacentInGraph;}
    inline void SetEdgeConnectInSpanningTree(const Edge& i_EdgeBetweenAdjacents) {
        m_EdgeConnectInSpanningTree = i_EdgeBetweenAdjacents;
    }
    inline int getVertexNumber() const {return m_VertexNumber;}
    inline void setMMinWeightOfEdgeConnect(int mMinWeightOfEdgeConnect) {m_MinWeightOfEdgeConnect = mMinWeightOfEdgeConnect;}
    Edge getEdgeConnectInSpanningTree() { return m_EdgeConnectInSpanningTree; }






};

