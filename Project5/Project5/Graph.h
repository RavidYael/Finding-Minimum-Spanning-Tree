#pragma once
#include "Vertex.h"
#include "Adjacent.h"
#include <list>
using namespace std;


class Graph
{
private:
	Graph(int i_NumberOfVertx,int i_NumberOfAdjacent);
	~Graph();
	void makeEmpty();
	bool isAdjacent(Vertex i_src, Vertex i_dest);
	list<Adjacent> getAllAdjacents();
	void addAdj(Vertex i_src, Vertex i_dest, int i_AdjWeight);
	void removeAdj(Vertex i_src, Vertex i_dest);

};

