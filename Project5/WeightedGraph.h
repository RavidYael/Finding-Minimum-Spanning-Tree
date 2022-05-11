#pragma once
#include "Vertex.h"
#include "Edge.h"
#include <vector>
using namespace std;


class WeightedGraph
{
private:
	int m_NumberOfVertexes;
	int m_NumberOfEdges;
	vector<Edge> m_Edges;
	vector<Vertex> m_Vertexes;

public:
	WeightedGraph();
	WeightedGraph(int i_NumberOfVertx, int i_NumberOfEdges);
	~WeightedGraph();
	void makeEmpty();
	bool IsAdjacent(Vertex i_src, Vertex i_dest);
	void AddEdge(int i_src,int i_dest, int i_AdjWeight);
	void RemoveAdj(Vertex i_src, Vertex i_dest);
	const vector<Edge> GetAllEdges() { return m_Edges; }
	const vector<Vertex> GetAllVertexes() { return m_Vertexes; }
	int GetNumberOfVertexes() {	return m_NumberOfVertexes; }
	void SetNumberOfVertexes(int numOfVertexes) { m_NumberOfVertexes = numOfVertexes; }
	void SetNumberOfEdges(int numOfEdges) { m_NumberOfEdges = numOfEdges; }
	Vertex GetVertexByName(int i_VertexNumber) { return m_Vertexes[i_VertexNumber]; }
	

};

