#pragma once
class DisjointSets
{
public:
	void MakeSet(Vertex i_VertexInGraph);
	void UnionBySize(Vertex i_V, Vertex i_U);
	Vertex Find(Vertex i_VertexToFindHisRoot);
};

