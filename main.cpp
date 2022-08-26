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
    int type;
    int countNodes;
    int countEdges = 0;
    auto **graphs = new Graph*[4];
    cout << "---Graphs---" << endl;
    cout << "Enter graph type(1-3):";
    cin >> type;
    cout << "Enter count of nodes:";
    cin >> countNodes;
    cout<<"How many edges in graph?:";
    cin >> countEdges;
    if(type == EDGES)
        graphs[0] = new IGraph(countNodes);
    else if (type == MATRIX)
        graphs[0] = new MatrixGraph(countNodes);
    else if (type == LIST)
        graphs[0] = new ListGraph(countNodes);
    for (int i = 0; i < countEdges; ++i)
        graphs[0]->AddEdge();
    graphs[1] = new MatrixGraph(graphs[0]);
    graphs[2] = new ListGraph(graphs[1]);
    graphs[3] = new IGraph(graphs[2]);
    system("cls");
    for (int i = 0; i < 4; ++i)
    {
        cout << "---" << endl;
        graphs[i]->showGraph();
    }
    system("pause");
    return 0;
}
