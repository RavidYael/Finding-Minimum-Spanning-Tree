#include "WeightedGraph.h"

WeightedGraph::WeightedGraph(int i_NumberOfVertexes, int i_NumberOfEdges)
{
	m_NumberOfVertexes = i_NumberOfVertexes;
	m_NumberOfEdges = i_NumberOfEdges;
	for (int numOfVertex = 1; numOfVertex <= m_NumberOfVertexes; numOfVertex++) {
		m_Vertexes.push_back(Vertex(numOfVertex));
	}
}

void WeightedGraph::AddEdge(int i_src, int i_dest, int i_AdjWeight)
{
	Edge newEdge = Edge(i_src, i_dest, i_AdjWeight);
	m_Edges.push_back(newEdge);
}
