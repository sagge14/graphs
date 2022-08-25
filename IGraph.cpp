//
// Created by Sg on 17.08.2022.
//
#include "IGraph.h"

void IGraph::AddEdge() {
    if(countNodes ==0)
        return;

    int from,to = 0;
    enterEdge(from,to);
    Edge edge(from,to);
    Edges.insert(edge);
    cout << "-ok!" << endl;
}

void IGraph::GetNextVertices(int vertex, vector<int> &vertices) const {
    for(const auto& edge:Edges)
    {
        if(edge.from == vertex)
            vertices.push_back(edge.to);
    }
}

void IGraph::GetPrevVertices(int vertex, vector<int> &vertices) const {
    for(const auto& edge:Edges)
    {
        if(edge.to == vertex)
            vertices.push_back(edge.from);
    }
}

void IGraph::showGraph() const {
    cout << "Edges:" << endl;
    for(const auto& edge:Edges)
        cout << edge.from << " - " << edge.to << endl;
}

const unordered_set<Edge>& IGraph::getEdges() const {
    return Edges;
}

IGraph::IGraph(const IGraph &G)  : Graph(G) {
    countNodes = G.countNodes;
    Edges = G.Edges;
}

IGraph::IGraph(const ListGraph &L)
{
    countNodes = L.getNodesCount();
    for (int i = 0; i < countNodes; ++i) {
        for(auto n:*L.getList()[i])
        {
            Edge edge(i+1,n);
            Edges.insert(edge);
        }
    }
}

IGraph::IGraph(const MatrixGraph &M)
{
    countNodes = M.getNodesCount();
    for (int i = 0; i < countNodes; ++i) {
        for (int j = 0; j < countNodes; ++j) {
            if(M.getMatrix()[i][j] == 1)
            {
                Edge edge(i+1,j+1);
                Edges.insert(edge);
            }
        }
    }
}

IGraph &IGraph::operator=(const IGraph &graph) {
    Edges.clear();
    Edges = graph.Edges;
    countNodes = graph.getNodesCount();
    return *this;
}

IGraph &IGraph::operator=(const ListGraph &graph) {
    IGraph bufG(graph);
    *this = bufG;
    return *this;
}

IGraph &IGraph::operator=(const MatrixGraph &graph) {
    IGraph bufG(graph);
    *this = bufG;
    return *this;
}

IGraph::IGraph(int n) {
    countNodes = n;
}

IGraph::IGraph(Graph *G) {
    MatrixGraph* M = dynamic_cast<MatrixGraph*>(G);
    if(M)
        *this = *M;
    else
    {
        ListGraph* L = dynamic_cast<ListGraph*>(G);
        if(L)
            *this = *L;
        else
        {
            IGraph*  GG = dynamic_cast<IGraph*>(G);
            if(GG)
                *this = *GG;
        }
    }
}
