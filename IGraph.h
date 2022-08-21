//
// Created by Sg on 17.08.2022.
//
#include "myHash.h"
#include "Graph.h"
#include <vector>
#include <unordered_set>
#include <set>
#pragma once
using namespace std;
struct Edge;
static bool operator==(const Edge &n1, const Edge &n2)
{
    return n1.from == n2.from && n1.to == n2.to;
}
class IGraph : public Graph{

    unordered_set<Edge> Edges;

public:

   ~IGraph() = default;
   IGraph() = default;

   IGraph(const IGraph &G);
   explicit IGraph(int n);
   explicit IGraph(const class ListGraph &L);
   explicit IGraph(const class MatrixGraph &M);
   void showGraph() const override;
   void AddEdge() override;
   void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
   void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
   IGraph& operator=(const MatrixGraph& graph);
   IGraph& operator=(const ListGraph& graph);
   IGraph& operator=(const IGraph& graph);
   const unordered_set<Edge>& getEdges() const;
};