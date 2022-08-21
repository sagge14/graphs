//
// Created by Sg on 17.08.2022.
//
#include <memory>
#include <vector>
#include "Graph.h"
#pragma once
class MatrixGraph:public Graph
{
    vector<unique_ptr<int[]>> matrix;
public:
    explicit MatrixGraph() = default;
    explicit MatrixGraph(int n);
    MatrixGraph(const  MatrixGraph &L);
    explicit MatrixGraph(const class IGraph &G);
    explicit MatrixGraph(const class ListGraph &L);
    void showGraph() const override;
    void AddEdge() override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
    MatrixGraph& operator=(const MatrixGraph& graph);
    MatrixGraph& operator=(const ListGraph& graph);
    MatrixGraph& operator=(const IGraph& graph);
    MatrixGraph& operator=(const Graph& graph);
    const vector<unique_ptr<int[]>>& getMatrix() const;
};