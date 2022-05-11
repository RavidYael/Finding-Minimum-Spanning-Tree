#pragma once


class Edge
{
private:
	int m_SrcName;
	int m_DestName;
	int m_Weight;

public:
	int GetSrc() { return m_SrcName; }
	int GetDest() { return m_DestName; }
	int GetWeight() { return m_Weight; }
};

