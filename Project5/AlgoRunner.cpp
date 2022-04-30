#include "AlgoRunner.h"

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

vector<Edge> AlgoRunner::Kruskal(WeightedGraph& i_Graph)
{
    vector<Edge> spaningTreeByEdges;
    DisjointSet connectionComponentsInGraph;
    vector<Vertex> allVertexesInGraph = i_Graph.GetAllVertexes();
    vector<Edge> sortedByWeightEdges = i_Graph.GetAllEdges();
    
    QuickSort(sortedByWeightEdges, 0, sortedByWeightEdges.size());

    for (Vertex vertrxInGraph : allVertexesInGraph)
    {
        connectionComponentsInGraph.MakeSet(vertrxInGraph);
    }
    
    for (Edge edgeInGraph : sortedByWeightEdges)
    {
        Vertex src = edgeInGraph.GetSrc();
        Vertex dest = edgeInGraph.GetDest();
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

    while (minWeightOfInEdgeHeap.IsNotEmpty()){
        Vertex currentVertexWithMinWeightOfInedge = minWeightOfInedgeHeap.DeleteMin();
        vector<Edge> allOutEdgesFromVertex = currentVertexWithMinWeightOfInedge.GetAllOutEdges();

        for (Edge outEdge : allOutEdgesFromVertex) {
            Vertex adjacent = outEdge.GetDest();
            if ((adjacent.NotInTree()) && (outEdge.GetWeight() < adjacent.getMinWeightOfEdgeConnect())) {
                adjacent.SetMinWeightOfEdgeConnect(outEdge.GetWeight());
                adjacent.SetAdjacentInSpanningTree(currentVertexWithMinWeightOfInedge);
                adjacent.SetEdgeConnectInSpanningTree(outEdge);
                minWeightOfInEdgeHeap.DecreaseKey(outEdge.GetWeight());
            }
        }
    }
    return spaningTreeByEdges(i_Graph);
}

vector<Edge> AlgoRunner::spaningTreeByEdges(WeightedGraph& i_Graph) {
    vector<Edge> edgesInSpaningTree;
    for (Vertex vertex : i_Graph.GetAllVertexes())
    {
        edgesInSpaningTree.push_back(vertex.getEdgeConnectInSpanningTree());
    }
    return edgesInSpaningTree;
}
