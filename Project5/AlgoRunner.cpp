#include "AlgoRunner.h"
#include <iostream>


using namespace std;

int AlgoRunner::partition(vector<Edge>& i_EdgeArray, int i_LeftIndex, int i_RightIndex)
{

    Edge pivot = i_EdgeArray[i_LeftIndex];
    int count = 0;
    
    for (int i = i_LeftIndex + 1; i <= i_RightIndex; i++) {
        if (i_EdgeArray[i].GetWeight() <= pivot.GetWeight())
            count++;
    }
    
    int pivotIndex = i_LeftIndex + count;
    
    swap(i_EdgeArray[pivotIndex], i_EdgeArray[i_LeftIndex]);
    
    int i = i_LeftIndex, j = i_RightIndex;

    while (i < pivotIndex && j > pivotIndex) {

        while (i_EdgeArray[i].GetWeight() <= pivot.GetWeight()) {
            i++;
        }

        while (i_EdgeArray[j].GetWeight() > pivot.GetWeight()) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(i_EdgeArray[i++], i_EdgeArray[j--]);
        }
    }

    return pivotIndex;
}

void AlgoRunner::QuickSort(vector<Edge>& i_EdgeArray, int i_LeftIndex, int i_RightIndex)
{
    if (i_LeftIndex >= i_RightIndex)
        return;
    
   
    int p = AlgoRunner::partition(i_EdgeArray, i_LeftIndex, i_RightIndex);

    QuickSort(i_EdgeArray, i_LeftIndex, p - 1);

    QuickSort(i_EdgeArray, p + 1, i_RightIndex);
}

bool AlgoRunner::IsConnectedCompont(WeightedGraph i_Graph)
{
    vector<bool> visitedVertxes;
    visitedVertxes.reserve(i_Graph.GetNumberOfVertexes());
    
    DFS(i_Graph, visitedVertxes);
    
    return IsAllVertexesVisitedDuringDFS(visitedVertxes);

}

void AlgoRunner::DFSUtil(WeightedGraph i_TheGraph, Vertex i_CurrentVertex, vector<bool> i_VisitedVertexes)
{
    // Mark the current node as visited
    i_VisitedVertexes[i_CurrentVertex.GetName()] = true;

    // Recur for all the vertices adjacent to this vertex
    vector<Edge>::iterator EdgeToAdjacent;
    for (EdgeToAdjacent = i_CurrentVertex.GetAllOutEdges().begin(); EdgeToAdjacent != i_CurrentVertex.GetAllOutEdges().end(); ++EdgeToAdjacent)
        if (!i_VisitedVertexes[(*EdgeToAdjacent).GetDest()])
            DFSUtil(i_TheGraph, i_TheGraph.GetVertexByName((*EdgeToAdjacent).GetDest()), i_VisitedVertexes);
}


// The function to do DFS traversal. It uses recursive
// DFSUtil()
void AlgoRunner::DFS(WeightedGraph i_TheGraph, vector<bool> i_VisitedVertexes)
{
    for (Edge edge : i_TheGraph.GetAllEdges())
        if (i_VisitedVertexes[edge.GetSrc()] == false)
            DFSUtil(i_TheGraph, i_TheGraph.GetVertexByName(edge.GetSrc()), i_VisitedVertexes);
}

bool AlgoRunner::IsAllVertexesVisitedDuringDFS(vector<bool> i_VisitedVertexAfterDFS) {
    bool graphIsConnectedCompont = true;

    for (bool isVertexVisited : i_VisitedVertexAfterDFS) {
        if (isVertexVisited != true) {
            graphIsConnectedCompont = false;
            break;
        }
    }
   
    return graphIsConnectedCompont;
   
}

vector<Edge> AlgoRunner::Kruskal(WeightedGraph& i_Graph)
{
    vector<Edge> spaningTreeByEdges;
    DisjointSet connectionComponentsInGraph(i_Graph.GetNumberOfVertexes());
    vector<Vertex> allVertexesInGraph = i_Graph.GetAllVertexes();
    vector<Edge> sortedByWeightEdges = i_Graph.GetAllEdges();
    
    QuickSort(sortedByWeightEdges, 0, sortedByWeightEdges.size());

    for (Vertex vertrxInGraph : allVertexesInGraph)
    {
        connectionComponentsInGraph.MakeSet(vertrxInGraph.GetName());
    }
    
    for (Edge edgeInGraph : sortedByWeightEdges)
    {
        int src = edgeInGraph.GetSrc();
        int dest = edgeInGraph.GetDest();
        if (connectionComponentsInGraph.Find(src) != connectionComponentsInGraph.Find(dest))
        {
            spaningTreeByEdges.push_back(edgeInGraph);
            connectionComponentsInGraph.UnionBySize(src, dest);
        }
    }
    return spaningTreeByEdges;
}

vector<Edge> AlgoRunner::Prim(WeightedGraph& i_Graph)
{
    MinHeap minWeightOfInEdgeHeap(i_Graph.GetNumberOfVertexes());
    minWeightOfInEdgeHeap.BuildHeap(i_Graph.GetAllVertexes());

    while (!minWeightOfInEdgeHeap.IsEmpty()){
        int NameOfVertexWithMinimumWeightOfInedge = minWeightOfInEdgeHeap.DeleteMin().getKey();
        Vertex currentVertexWithMinWeightOfInedge = i_Graph.GetVertexByName(NameOfVertexWithMinimumWeightOfInedge);
        vector<Edge> allOutEdgesFromVertex = currentVertexWithMinWeightOfInedge.GetAllOutEdges();

        for (Edge outEdge : allOutEdgesFromVertex) {

            Vertex adjacent = i_Graph.GetVertexByName(outEdge.GetDest());
            if ((adjacent.NotInTree()) && (outEdge.GetWeight() < adjacent.GetMinWeightOfEdgeConnect())) {
                adjacent.SetMinWeightOfEdgeConnect(outEdge.GetWeight());
                adjacent.SetAdjacentInSpanningTree(currentVertexWithMinWeightOfInedge,outEdge);
                minWeightOfInEdgeHeap.DecreaseKey(NameOfVertexWithMinimumWeightOfInedge,outEdge.GetWeight());
            }
        }
    }
    return spaningTreeByEdges(i_Graph);
}

vector<Edge> AlgoRunner::spaningTreeByEdges(WeightedGraph& i_Graph) {
    vector<Edge> edgesInSpaningTree;
    for (Vertex vertex : i_Graph.GetAllVertexes())
    {
        edgesInSpaningTree.push_back(vertex.GetEdgeConnctInSpanningTree());
    }
    return edgesInSpaningTree;
}
