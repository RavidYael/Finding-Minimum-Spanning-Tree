#pragma once
#include <vector>
#include "Vertex.h"
using namespace std;


class WeightedGraph
{
private:
	int m_NumberOfVertexes;
	int m_NumberOfEdges;
	vector<Edge> m_Edges;
	vector<Vertex> m_Vertexes;

public:
	WeightedGraph() = default;
	WeightedGraph(int i_NumberOfVertexes, int i_NumberOfEdges);
	void AddEdge(int i_src,int i_dest, int i_AdjWeight);
	const vector<Edge> GetAllEdges() { return m_Edges; }
	const vector<Vertex> GetAllVertexes() { return m_Vertexes; }
	int GetNumberOfVertexes() {	return m_NumberOfVertexes; }
	void SetNumberOfVertexes(int numOfVertexes) { m_NumberOfVertexes = numOfVertexes; }
	void SetNumberOfEdges(int numOfEdges) { m_NumberOfEdges = numOfEdges; }
	Vertex GetVertexByName(int i_VertexNumber) { return m_Vertexes[i_VertexNumber]; }
	

};

