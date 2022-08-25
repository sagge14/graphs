//
// Created by Sg on 19.08.2022.
//
#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

class Graph {
protected:
    int countNodes = 0;
    void enterEdge(int &from, int &to) const
    {
        do {
            cout<<"Enter from:";
            cin>>from;
        }while(from > countNodes || from < 1);

        do {
            if(to == from)
                cout << "Graph without loops!" << endl;

            cout<<"Enter to:";
            cin>>to;
        }while(to > countNodes || to < 1 || to == from);
    }
public:
    Graph() = default;
    ~Graph() = default;
    void setNodesCount()
    {
        std::cout << "Enter nodes count:";
        std::cin >> countNodes;
    }
    int getNodesCount() const
    {
        return countNodes;
    }
    virtual void AddEdge() = 0;
    virtual void showGraph() const = 0;
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
};