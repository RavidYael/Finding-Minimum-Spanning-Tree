#pragma once


class Edge
{
private:
	int m_SrcName;
	int m_DestName;
	int m_Weight;

public:
	Edge(int i_SrcNumber, int i_DestNumber, int i_EdgeWeight) {
		m_SrcName = i_SrcNumber;
		m_DestName = i_DestNumber;
		m_Weight = i_EdgeWeight;
	}
	int GetSrc() { return m_SrcName; }
	int GetDest() { return m_DestName; }
	int GetWeight() { return m_Weight; }
};

