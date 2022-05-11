#include "WeightedGraph.h"

void WeightedGraph::AddEdge(int i_src, int i_dest, int i_AdjWeight)
{
	Edge newEdge = Edge(i_src, i_dest, i_AdjWeight);
	m_Edges.push_back(newEdge);
}
