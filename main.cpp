#include <iostream>
#include "IGraph.h"
#include "MatrixGraph.h"
#include "ListGraph.h"
using namespace std;

int main() {
    int countNodes;
    int countEdges = 0;

    cout << "---Graphs---" << endl;
    cout << "Enter count of nodes:";
    cin >> countNodes;
    cout<<"How many edges in graph?:";
    cin >> countEdges;

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
