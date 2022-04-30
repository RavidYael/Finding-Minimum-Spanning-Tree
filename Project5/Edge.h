#pragma once
class Edge
{
private:
	Vertex m_Src;
	Vertex m_Dest;
	int m_Weight;

public:
	Vertex GetSrc() { return m_Src; }
	Vertex GetDest() { return m_Dest; }
	int GetWeight() { return m_Weight; }
};

