#pragma once
#include "Vertex.h"
class BinaryTree
{
private:
	int m_NumberOfVertexInTree;
public:
	BinaryTree();
	~BinaryTree();
	void Build(vector<Vertex> i_ArrToHeap); //TO FIX
	void DecreaseKey(int i_KeyValue);
	Vertex DeleteMin();
	bool IsNotEmpty() { return m_NumberOfVertexInTree != 0; }
};

