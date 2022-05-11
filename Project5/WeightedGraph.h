#pragma once
#include "Vertex.h"
#include "Edge.h"
#include <vector>
#include "VertexInAdjacentList.h"
#include <iostream>
using namespace std;


class WeightedGraph
{
private:
	int m_NumberOfVertexes;
	int m_NumberOfEdges;
	vector<Edge> m_Edges;
	vector<Vertex> m_Vertexes;
    vector<Vector<VertexInAdjacentList>> m_Graph;

public:
    //Ctor
    WeightedGraph(int mNumberOfVertexes, int mNumberOfEdges) : m_NumberOfVertexes(mNumberOfVertexes),m_NumberOfEdges(mNumberOfEdges) {}
    //Dtor
    ~WeightedGraph() = default;
	//void makeEmpty();TODO i dont think we need it
	bool IsAdjacent(Vertex i_src, Vertex i_dest);//TODO do we use this method at all? if not to delete it.
	void AddEdge(int i_src,int i_dest, int i_AdjWeight);
	void RemoveAdj(Vertex i_src, Vertex i_dest);
	const vector<Edge> GetAllEdges() { return m_Edges; }
	const vector<Vertex> GetAllVertexes() { return m_Vertexes; }
	int GetNumberOfVertexes() {	return m_NumberOfVertexes; }
    void SetNumberOfVertexes(int numOfVertexes){ m_NumberOfVertexes = numOfVertexes};
    void SetNumberOfEdges(int numOfEdges){m_NumberOfEdges = numOfEdges};
	

};

