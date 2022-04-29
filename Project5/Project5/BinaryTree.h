#pragma once
#include "Vertex.h"
class BinaryTree
{
private:
	BinaryTree();
	~BinaryTree();
	void Bulid(Vertex* i_ArrToHeap); //TO FIX
	bool isEmpty();
	void DecreaseKey(int i_IndexOfKey, int i_NewKey);
};

