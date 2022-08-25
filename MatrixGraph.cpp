//
// Created by Sg on 17.08.2022.
//

#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(const IGraph &G) : MatrixGraph(G.getNodesCount()){

    for (const auto& ed:G.getEdges())
        matrix[ed.from - 1][ed.to - 1] = 1;

}

MatrixGraph::MatrixGraph(const ListGraph &L) : MatrixGraph(L.getNodesCount()) {

    for (int i = 0; i < countNodes; ++i)
        for (auto ed:*L.getList()[i])
            matrix[i][ed-1] = 1;
}

MatrixGraph::MatrixGraph(int n) {
    if(n == 0)
        return;
    countNodes = n;

    for (int i = 0; i < countNodes; ++i) {
        matrix.push_back(make_unique<int[]>(countNodes));
        for (int j = 0; j < countNodes; ++j) {
            matrix[i][j] = 0;
            matrix[i][j] = 0;
        }
    }
}

void MatrixGraph::AddEdge() {
    if (matrix.empty())
        return;
    int from,to = 0;
    enterEdge(from,to);
    matrix[from-1][to-1] = 1;
    cout << "-ok!" << endl;
}

void MatrixGraph::GetNextVertices(int vertex, vector<int> &vertices) const {
    if(matrix.empty())
        return;
    for (int i = 0; i < countNodes; ++i) {
        if (matrix[vertex-1][i] == 1)
            vertices.push_back(i+1);
    }
}

void MatrixGraph::GetPrevVertices(int vertex, vector<int> &vertices) const {
    if(matrix.empty())
        return;
    for (int i = 0; i < countNodes; ++i) {
        if (matrix[i][vertex-1] == 1)
            vertices.push_back(i+1);
    }
}

void MatrixGraph::showGraph() const {
    if(matrix.empty())
        return;
    cout << " |";
    for (int i = 0; i < countNodes; ++i)
        cout << i+1 << " ";
    cout<<endl;
    cout << " ";
    for (int i = 0; i < countNodes; ++i)
        cout <<  "--";
    cout<<endl;

    for (int i = 0; i < countNodes; ++i)
    {
        cout<< i +1 << "|";
        for (int j = 0; j < countNodes; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

const vector<unique_ptr<int[]>>& MatrixGraph::getMatrix() const{
    return matrix;
}

MatrixGraph &MatrixGraph::operator=(const MatrixGraph& graph) {
    if(this == &graph)
        return *this;
    countNodes = graph.countNodes;

    if(!matrix.empty())
    {
        for (auto & i : matrix)
            i.reset();
        matrix.clear();
    }

    for (int i = 0; i < countNodes; ++i) {
        matrix.push_back(make_unique<int[]>(countNodes));
        for (int j = 0; j < countNodes; ++j) {
            matrix[i][j] = graph.matrix[i][j];
            matrix[i][j] = graph.matrix[i][j];
        }
    }

    return *this;
}

MatrixGraph::MatrixGraph(const MatrixGraph &L) : Graph(L) {
    shared_ptr<int>* g = new shared_ptr<int>;
    *this = L;
}


MatrixGraph &MatrixGraph::operator=(const ListGraph& graph)
{
    countNodes = graph.getNodesCount();
    MatrixGraph bufM(graph);
    *this = bufM;
    return *this;
}

MatrixGraph &MatrixGraph::operator=(const IGraph& graph)
{
    MatrixGraph bufM(graph);
    countNodes = graph.getNodesCount();
    *this = bufM;
    return *this;
}
MatrixGraph::MatrixGraph(Graph *G) {
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