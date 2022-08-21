#include <iostream>
#include "Graph.h"
#include "IGraph.h"
#include "MatrixGraph.h"
#include "ListGraph.h"
using namespace std;
enum {
    EDGES = 1,
    MATRIX,
    LIST
};

int main() {
   // int type;
    int countNodes;
    int countEdges = 0;
  //  auto **graphs = new Graph*[3];

    cout << "---Graphs---" << endl;
   // cout << "Enter graph type:";
   // cin >> type;
    cout << "Enter count of nodes:";
    cin >> countNodes;
    cout<<"How many edges in graph?:";
    cin >> countEdges;
/*
    if(type == EDGES)
        graphs[0] = new IGraph(countNodes);
    else if (type == MATRIX)
        graphs[0] = new MatrixGraph(countNodes);
    else if (type == LIST)
        graphs[0] = new ListGraph(countNodes);

    for (int i = 0; i < countEdges; ++i)
        graphs[0]->AddEdge();

    MatrixGraph M;
    M =  *dynamic_cast<MatrixGraph*>(graphs[0]);
    graphs[1] = new MatrixGraph(*dynamic_cast<MatrixGraph*>(graphs[0]));
    graphs[2] = new ListGraph(*dynamic_cast<MatrixGraph*>(graphs[0]));
*/

    IGraph G(countNodes);
    for (int i = 0; i < countEdges; ++i)
    {
        system("cls");
        cout << "Edge N " << i+1 << ":" << endl;
        G.AddEdge();
    }

    system("cls");

    MatrixGraph M(G);
    ListGraph L(M);
    IGraph G2;
    G2 = L;
    M = L;
    cout << "--G2---" << endl;
    G2.showGraph();
    cout << "--M---" << endl;
    M.showGraph();
    cout << "--L---" << endl;
    L.showGraph();
    cout << "--G---" << endl;
    G.showGraph();
    cout<<"---Bye, bye---" << endl;
    system("pause");

    return 0;
}
