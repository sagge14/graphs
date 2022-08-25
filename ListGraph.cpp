//
// Created by Sg on 18.08.2022.
//
#include "ListGraph.h"

ListGraph::ListGraph(const class IGraph &G): ListGraph(G.getNodesCount()) {

    for (const auto& ed:G.getEdges()) {
        list[ed.from-1]->insert(ed.to);
    }
}

void ListGraph::showGraph() const {
    if (list.empty())
        return;
    for (int i = 0; i < countNodes; ++i) {
            cout << i+1 << ":";
        for (auto ed:*list[i]) {
                cout << ed << " ";
        }
        cout << endl;
    }
}

ListGraph::ListGraph(const class MatrixGraph &M) : ListGraph(M.getNodesCount()){

    for (int i = 0; i < countNodes; ++i)
        for (int j = 0; j < countNodes; ++j)
            if(M.getMatrix()[i][j] == 1)
                list[i]->insert(j+1);
}

void ListGraph::AddEdge() {
    if (list.empty())
        return;
    int from,to = 0;
    enterEdge(from,to);
    list[from-1]->insert(to);
    cout << "-ok!" << endl;
}

void ListGraph::GetNextVertices(int vertex, vector<int> &vertices) const {
    if (list.empty())
        return;
    for(auto n:*list[vertex-1])
        vertices.push_back(n);
}

void ListGraph::GetPrevVertices(int vertex, vector<int> &vertices) const {
    if (list.empty())
        return;
    for (int i = 0; i < countNodes; ++i)
        for(auto n:*list[i])
            if (n == vertex)
            {
                vertices.push_back(i+1);
                break;
            }
}

const vector<shared_ptr<set<int>>>& ListGraph::getList() const {
    return list;
}

ListGraph::ListGraph(int n) {
    if(!list.empty())
        list.clear();
    countNodes = n;

    for (int i = 0; i < countNodes; ++i) {
        list.push_back(make_shared<set<int>>());
    }
}

ListGraph::ListGraph(const ListGraph &L)  : Graph(L) {
    list.clear();
    countNodes = L.countNodes;
    list = L.list;
}

ListGraph &ListGraph::operator=(const ListGraph &graph) {
    if(this == &graph)
        return *this;
    list.clear();
    countNodes = graph.countNodes;
    list =  graph.list;
    return *this;
}

ListGraph &ListGraph::operator=(const MatrixGraph &graph) {
    ListGraph bufL(graph);
    *this = bufL;
    return *this;
}

ListGraph &ListGraph::operator=(const IGraph &graph) {
    ListGraph bufL(graph);
    *this = bufL;
    return *this;
}
