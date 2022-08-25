//
// Created by Sg on 18.08.2022.
//
#pragma once
#include "IGraph.h"
#include "MatrixGraph.h"
#include "Graph.h"

class ListGraph:public Graph
{
    vector<shared_ptr<set<int>>> list;
public:
    explicit ListGraph() = default;
    explicit ListGraph(int n);
    ListGraph(const ListGraph &L);
    explicit ListGraph(const class IGraph &G);
    explicit ListGraph(const class MatrixGraph &M);
    void AddEdge() override;
    void showGraph() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
    ListGraph& operator=(const ListGraph& graph);
    ListGraph& operator=(const MatrixGraph& graph);
    ListGraph& operator=(const IGraph& graph);
    const vector<shared_ptr<set<int>>>& getList() const;
};