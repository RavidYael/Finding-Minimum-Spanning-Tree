#include "WeightedGraph.h"



bool WeightedGraph::IsAdjacent(Vertex i_src, Vertex i_dest) {
    vector<VertexInAdjacentList> adjacent = m_Graph[i_src.GetName()];
    for(VertexInAdjacentList curVer : adjacent){
        if(curVer.getVertex() = i_dest){
            return true;
        }
    }
    return false;
}

void WeightedGraph::AddEdge(int i_src, int i_dest, int i_AdjWeight) {
    VertexInAdjacentList curVer(m_Vertexes[i_dest],i_AdjWeight);
    m_Graph[i_src].push_back(curVer);//TODO maybe not ok maybe we need to implement a copy ctor
    Edge curEdge(i_src,i_dest,i_AdjWeight);
    if(std::find(m_Edges.begin(), m_Edges.end(), curEdge) != m_Edges.end())
        m_Edges.push_back(curEdge);//TODO maybe not ok maybe we need to implement a copy ctor i think here its ok but with curVer we have a problem because of the ref to vertex.—
}

//void WeightedGraph::RemoveAdj(Vertex i_src, Vertex i_dest) {
//    for(VertexInAdjacentList curAdjVertex : m_Graph[i_src.GetName()]){
//        if(curAdjVertex.getVertex() == i_dest){
//
//        }
//    }
//}
