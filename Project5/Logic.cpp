//
// Created by Dan Schindler on 10/05/2022.
//
#include "Logic.h"

void Logic::buildGraphFromEdgeDataArray(vector<int> edgeData){
    counter = 2;
    m_undirectedWeightedGraph.SetNumberOfEdges(edgeData[0]);
    m_undirectedWeightedGraph.SetNumberOfVertexes(edgeData[1]);
    for(int i = 0; i < numOfEdges; i++){
        m_undirectedWeightedGraph.AddEdge(edgeData[counter],edgeData[counter + 1],edgeData[counter + 2]);
        m_undirectedWeightedGraph.AddEdge(edgeData[counter + 1],edgeData[counter],edgeData[counter + 2]);
        counter++;
    }
}
void Logic::runAlgoRunner(){
    m_algoRunner.Kruskal(m_undirectedWeightedGraph);
    m_algoRunner.Prim(m_undirectedWeightedGraph);
    //m_algoRunner.RemoveEdge(edgeToRemove,m_undirectedWeightedGraph);
    /*if(removedEdgeNotABridge){
        m_algoRunner.Kruskal(m_undirectedWeightedGraph);
    }
    else{
        cout << "No MST";
    }*/

}